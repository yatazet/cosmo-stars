/*
	COSMO - STARS v0.1
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <random>
using namespace std;
enum class Keys {
	NOSET,
	ENTER = 0x0D,
	ESC = 0x1B,
	A = 0x41,
	D = 0x44,
	W = 0x57,
	S = 0x53
};
const int screen_width = 15;
const int screen_height = 15;
bool gameOver = false;
int score = 2000;
int rocket_y = 13;
int meteor_y = 2;
int rocket_x = 8;
void hello_words()
{
	cout << "######   #######   ######  ##     ##  #######                 ######  ########    ###    ########   ######" << endl;
	cout << "##    ## ##     ## ##    ## ###   ### ##     ##               ##    ##    ##      ## ##   ##     ## ##    ##" << endl;
	cout << "##       ##     ## ##       #### #### ##     ##               ##          ##     ##   ##  ##     ## ##" << endl;
	cout << "##       ##     ##  ######  ## ### ## ##     ##    #######     ######     ##    ##     ## ########   ######" << endl;
	cout << "##       ##     ##       ## ##     ## ##     ##                     ##    ##    ######### ##   ##         ##" << endl;
	cout << "##    ## ##     ## ##    ## ##     ## ##     ##               ##    ##    ##    ##     ## ##    ##  ##    ##" << endl;
	cout << "######   #######   ######  ##     ##  #######                 ######     ##    ##     ## ##     ##  ######" << endl;
	cout << "1. Play" << endl;
	cout << "2. Show settings" << endl;
	cout << "3. Exit" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		system("cls");
		break;
	case 2:
		system("cls");
		cout << "Use caps - lock while playing! " << endl;
		cout << "Move - W, A, S, D " << endl;
		cout << "Esc - Exit game " << endl;
		Sleep(5000);
		system("cls");
		break;
	case 3:
		exit(0);
		break;
	}
}
void draw()
{
	random_device r;
	default_random_engine e(r());
	uniform_int_distribution<int> dist(5, screen_width - 5);
	int meteor_x = dist(e);
	meteor_y++;
	system("cls");
	for (int i = 0; i < screen_width + 1; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < screen_height; i++)
	{
		for (int j = 0; j < screen_width; j++)
		{
			if (j == 0) cout << "#";
			if (j == screen_width - 1) cout << "#";
			if (i == rocket_y && j == rocket_x) cout << "R";
			else if (i == meteor_y && j == meteor_x) cout << "M";
			else cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < screen_width + 1; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Current score: " << score << endl;
	if (rocket_y == meteor_y and rocket_x == meteor_x)
	{
		cout << "YOU WON" << endl;
		score += 1000;
		meteor_y = 2;
		rocket_y = 13;
		rocket_x = 8;
		return;
	}
	if (rocket_y == meteor_y and rocket_x < meteor_x or rocket_y == meteor_y and rocket_x > meteor_x)
	{
		cout << "You lose" << endl;
		score -= 1000;
		meteor_y = 2;
		rocket_y = 13;
		rocket_x = 8;
		return;
	}
	if (rocket_y < meteor_y)
	{
		cout << "You lose" << endl;
		score -= 1000;
		meteor_y = 2;
		rocket_y = 13;
		rocket_x = 8;
		return;
	}
}
void logic()
{
		if (_kbhit())
		{
			switch (static_cast<Keys>(_getch()))
			{
			case Keys::A:
				rocket_x = rocket_x - 1;
				draw();
				break;
			case Keys::D:
				rocket_x += 1;
				draw();
				break;
			case Keys::W:
				rocket_y -= 1;
				draw();
				break;
			case Keys::S:
				rocket_y += 1;
				draw();
				break;
			case Keys::ESC:
				exit(0);
				break;
			}
		}
}
int main()
{
	hello_words();
	while (!gameOver)
	{
		if (score < 0) gameOver = true;
		logic();
	}
	return 0;
}

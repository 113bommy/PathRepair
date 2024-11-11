#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX 30
using namespace std;


int main()
{
	int p[MAX][MAX];
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			p[i][j] = 0;
		}
	}
	int x, y, size;
	while (scanf("%d,%d,%d", &x, &y, &size) != EOF){
		x += 10;
		y += 10;
		p[x][y]++;
		p[x - 1][y]++;
		p[x + 1][y]++;
		p[x][y - 1]++;
		p[x][y + 1]++;
		if (size == 1){
			continue;
		}
		p[x - 1][y - 1]++;
		p[x - 1][y + 1]++;
		p[x + 1][y - 1]++;
		p[x + 1][y + 1]++;
		if (size == 2){
			continue;
		}
		p[x - 2][y]++;
		p[x + 2][y]++;
		p[x][y - 2]++;
		p[x][y + 2]++;
	}
	int clean = 0, ink = 0;
	for (int i = 10; i < 20; i++){
		for (int j = 10; j < 20; j++){
			if (p[i][j] == 0){
				clean++;
			}
			ink = max(ink, p[i][j]);
		}
	}
	cout << clean << endl;
	cout << ink << endl;

	return 0;
}
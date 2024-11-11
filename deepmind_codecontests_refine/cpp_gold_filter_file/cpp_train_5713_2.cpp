#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int grid[14][14] = { 0 };

void small(int x, int y){
	grid[x][y]++;
	grid[x - 1][y]++;
	grid[x + 1][y]++;
	grid[x][y - 1]++;
	grid[x][y + 1]++;
}

void medium(int x, int y){
	small(x, y);
	grid[x - 1][y - 1]++;
	grid[x + 1][y - 1]++;
	grid[x - 1][y + 1]++;
	grid[x + 1][y + 1]++;
}

void large(int x, int y){
	medium(x, y);
	grid[x - 2][y]++;
	grid[x + 2][y]++;
	grid[x][y - 2]++;
	grid[x][y + 2]++;
}

int main(){
	int x, y, size;
	
	while (scanf("%d,%d,%d", &x, &y, &size) != EOF){
		if (size == 1) small(x + 2, y + 2);
		else if (size == 2) medium(x + 2, y + 2);
		else if (size == 3) large(x + 2, y + 2);
	}

	int ans1 = 0;
	int ans2 = 0;

	for (int i = 2; i < 12; i++){
		for (int j = 2; j < 12; j++){
			if (grid[i][j] == 0)
				ans1++;
			else
				ans2 = max(ans2, grid[i][j]);
		}
	}

	printf("%d\n%d\n", ans1, ans2);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 0, -1, -1, 1, 1},
    dy[] = {0, 1, 0, 0, -1, -1, 1, -1, 1};
char field[9][9];
bool dfs(int x, int y, int c, int d_x, int d_y) {
  if (c > 8 || (x == d_x && y == d_y)) return true;
  for (int i = 0; i < 9; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (!(nx >= 0 && nx < 7 && ny >= 0 && ny < 7)) continue;
    if (nx >= c && field[nx - c - 1][ny] == 'S') continue;
    if (nx >= c && field[nx - c][ny] == 'S') continue;
    if (dfs(nx, ny, c + 1, d_x, d_y)) return true;
  }
  return false;
}
int main() {
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) cin >> field[i][j];
  }
  if (dfs(7, 0, 0, 0, 7))
    cout << "WIN";
  else
    cout << "LOSE";
}

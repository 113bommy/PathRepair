#include <bits/stdc++.h>
using namespace std;
int dir[] = {-1, 0, 1, 0, -1};
void dfs(vector<vector<char>> &grid, int &cnt, int r, int c, int rows,
         int cols) {
  if (cnt <= 0) return;
  grid[r][c] = 'V';
  cnt--;
  for (int i = 0; i < 4; i++) {
    int row = r + dir[i];
    int col = c + dir[i + 1];
    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        grid[row][col] == '.')
      dfs(grid, cnt, row, col, rows, cols);
  }
  return;
}
int main() {
  int rows, cols, k, e = 0, r, c;
  string s;
  cin >> rows >> cols >> k;
  vector<vector<char>> grid(rows, vector<char>(cols));
  for (int i = 0; i < rows; i++) {
    cin >> s;
    for (int j = 0; j < cols; j++) {
      grid[i][j] = s[j];
      if (s[j] == '.') {
        r = i;
        c = j;
        e++;
      }
    }
  }
  int cnt = e - k;
  dfs(grid, cnt, r, c, rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 'V')
        printf(".");
      else if (grid[i][j] == '.')
        printf("x");
      else
        printf("%c", grid[i][j]);
    }
    printf("\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int grid[5][5];
  int mat[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      grid[i][j] = 1;
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> mat[i][j];
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (mat[i][j] % 2 != 0) {
        grid[i][j] = abs(grid[i][j] - 1);
        grid[i - 1][j] = abs(grid[i - 1][j] - 1);
        grid[i][j - 1] = abs(grid[i][j - 1] - 1);
        grid[i + 1][j] = abs(grid[i + 1][j] - 1);
        grid[i][j + 1] = abs(grid[i][j + 1] - 1);
      }
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int grid[11][11];
int main() {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) {
    grid[i][0] = 1;
    grid[0][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
    }
  }
  printf("%d", grid[n - 1][n - 1]);
}

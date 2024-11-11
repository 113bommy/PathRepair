#include <bits/stdc++.h>
using namespace std;
int n, m, take[100][100], i, j, k;
char grid[100][100];
int main() {
  scanf("%d %d\n", &n, &m);
  for (i = 0; i < n; i++) {
    gets(grid[i]);
  }
  for (k = 0; k < n; k++) {
    for (i = 0; i < m; i++) {
      for (j = i + 1; j < m; j++) {
        if (grid[k][i] == grid[k][j]) {
          take[k][i] = 1;
          take[k][j] = 1;
        }
      }
    }
  }
  for (k = 0; k < m; k++) {
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        if (grid[i][k] == grid[j][k]) {
          take[i][k] = 1;
          take[j][k] = 1;
        }
      }
    }
  }
  string ans;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (!take[i][j]) {
        ans += grid[i][j];
      }
    }
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int grid[n][m];
  string line;
  for (int i = 0; i < n; ++i) {
    cin >> line;
    for (int j = 0; j < m; ++j) {
      if (line[j] == '*') {
        grid[i][j] = 1;
      } else {
        grid[i][j] = 0;
      }
    }
  }
  int up[n][m];
  int left[n][m];
  for (int i = 0; i < m; ++i) {
    up[0][i] = grid[0][i];
  }
  for (int i = 0; i < n; ++i) {
    left[i][0] = grid[i][0];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      up[i][j] = grid[i][j] + up[i - 1][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      left[i][j] = grid[i][j] + left[i][j - 1];
    }
  }
  long long count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j]) {
        int u = up[i][j] - 1;
        int d = up[n - 1][j] - up[i][j];
        int l = left[i][j] - 1;
        int r = left[i][m - 1] - left[i][j];
        count += (u + d) * (l + r);
      }
    }
  }
  cout << count << endl;
}

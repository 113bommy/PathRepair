#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char arr[n][m];
  vector<vector<bool> > g(n, vector<bool>(m, false));
  int sx, sy, tx, ty;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (arr[i][j] == 'T') {
        tx = i;
        ty = j;
      }
    }
  for (int i = sx; i >= 0; --i) {
    if (arr[i][sy] == '*') break;
    g[i][sy] = 1;
    int j = sy;
    while (j < m && arr[i][j] != '*') {
      g[i][j] = 1;
      ++j;
    }
    j = sy;
    while (j >= 0 && arr[i][j] != '*') {
      g[i][j] = 1;
      --j;
    }
  }
  for (int i = sx; i < n; ++i) {
    if (arr[i][sy] == '*') break;
    g[i][sy] = 1;
    int j = sy;
    while (j < m && arr[i][j] != '*') {
      g[i][j] = 1;
      ++j;
    }
    j = sy;
    while (j >= 0 && arr[i][j] != '*') {
      g[i][j] = 1;
      --j;
    }
  }
  for (int j = sy; j >= 0; --j) {
    if (arr[sx][j] == '*') break;
    g[sx][j] = 1;
    int i = sx;
    while (i < n && arr[i][j] != '*') {
      g[i][j] = 1;
      ++i;
    }
    i = sx;
    while (i >= 0 && arr[i][j] != '*') {
      g[i][j] = 1;
      --i;
    }
  }
  for (int j = sy; j < m; ++j) {
    if (arr[sx][j] == '*') break;
    g[sx][j] = 1;
    int i = sx;
    while (i < n && arr[i][j] != '*') {
      g[i][j] = 1;
      ++i;
    }
    i = sx;
    while (i >= 0 && arr[i][j] != '*') {
      g[i][j] = 1;
      --i;
    }
  }
  for (int i = tx; i < n; ++i) {
    if (arr[i][ty] == '*') break;
    if (g[i][ty] == 1) return (!(cout << "YES"));
  }
  for (int i = tx; i >= 0; --i) {
    if (arr[i][ty] == '*') break;
    if (g[i][ty] == 1) return (!(cout << "YES"));
  }
  for (int j = ty; j < m; ++j) {
    if (arr[tx][j] == '*') break;
    if (g[tx][j] == 1) return (!(cout << "YES"));
  }
  for (int j = ty; j >= 0; --j) {
    if (arr[tx][j] == '*') break;
    if (g[tx][j] == 1) return (!(cout << "YES"));
  }
  cout << "NO";
  return 0;
}

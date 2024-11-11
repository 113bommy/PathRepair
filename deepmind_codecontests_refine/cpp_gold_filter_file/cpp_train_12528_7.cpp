#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
string a[50];
int n, m, x[2], y[2];
int numb, f[50][50];
bool ok(int x, int y) { return (x >= 0) && (x < n) && (y >= 0) && (y < m); }
int dfs(int x, int y) {
  f[x][y] = numb;
  int cnt = 1;
  for (int i = 0; i < 4; i++)
    if (ok(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == '#' &&
        f[x + dx[i]][y + dy[i]] != numb)
      cnt += dfs(x + dx[i], y + dy[i]);
  return cnt;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == '#') {
        if (cnt < 2) {
          x[cnt] = i;
          y[cnt] = j;
        }
        cnt++;
      }
  if (cnt <= 2) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == '#') {
        a[i][j] = '.';
        for (int k = 0; k < 2; k++)
          if (x[k] != i || y[k] != j) {
            numb++;
            if (dfs(x[k], y[k]) != cnt - 1) {
              cout << 1;
              return 0;
            }
            break;
          }
        a[i][j] = '#';
      }
  cout << 2;
  return 0;
}

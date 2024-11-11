#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 10000 + 10;
char c[MAXN][MAXM];
int f[2] = {1, 1};
int dir[2] = {-1, 1};
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    c[i][0] = c[i][m + 1] = '#';
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  }
  long long ans = 0;
  int t = 0;
  int x = 0, y = 1;
  int d = 1;
  while (x != n - 1 and t <= 1000 * 1000 * 3 + 1) {
    t++;
    if (c[x + 1][y] == '.') {
      x++;
      f[0] = f[1] = y;
      ans++;
      continue;
    }
    if (d == 1) {
      if (y == f[1]) {
        ans++;
        if (c[x][y + 1] == '.')
          y = ++f[1];
        else if (c[x][y + 1] == '+') {
          d = 0;
          c[x][y + 1] = '.';
          f[1]++;
        } else {
          d = 0;
        }
      } else {
        ans += f[1] - y;
        y = f[1];
      }
    } else {
      if (y == f[0]) {
        ans++;
        if (c[x][y - 1] == '.')
          y = --f[0];
        else if (c[x][y - 1] == '+') {
          d = 1;
          c[x][y - 1] = '.';
          f[0]--;
        } else {
          d = 1;
        }
      } else {
        ans += y - f[0];
        y = f[0];
      }
    }
  }
  if (t > 1000 * 1000 * 3)
    cout << "Never" << endl;
  else
    cout << ans << endl;
  return 0;
}

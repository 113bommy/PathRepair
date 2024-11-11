#include <bits/stdc++.h>
using namespace std;
int n, m, t, a[310][310];
int tp, tu, td;
int r[301][301], d[301][301], l[301][301], u[301][301];
void init() {
  memset(d, 0, sizeof(d));
  memset(r, 0, sizeof(r));
  memset(l, 0, sizeof(l));
  memset(u, 0, sizeof(u));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m - 1; j++)
      if (a[i][j + 1] > a[i][j])
        r[i][j + 1] = r[i][j] + tu;
      else if (a[i][j + 1] == a[i][j])
        r[i][j + 1] = r[i][j] + tp;
      else
        r[i][j + 1] = r[i][j] + td;
  for (int i = 0; i < n; i++)
    for (int j = m - 1; j > 0; j--)
      if (a[i][j - 1] > a[i][j])
        l[i][j - 1] = l[i][j] + tu;
      else if (a[i][j - 1] == a[i][j])
        l[i][j - 1] = l[i][j] + tp;
      else
        l[i][j - 1] = l[i][j] + td;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m; j++)
      if (a[i + 1][j] > a[i][j])
        d[i + 1][j] = d[i][j] + tu;
      else if (a[i + 1][j] == a[i][j])
        d[i + 1][j] = d[i][j] + tp;
      else
        d[i + 1][j] = d[i][j] + td;
  for (int i = n - 1; i > 0; i--)
    for (int j = 0; j < m; j++)
      if (a[i - 1][j] > a[i][j])
        u[i - 1][j] = u[i][j] + tu;
      else if (a[i - 1][j] == a[i][j])
        u[i - 1][j] = u[i][j] + tp;
      else
        u[i - 1][j] = u[i][j] + td;
}
int calc(int x1, int y1, int x2, int y2) {
  int temp = r[x1][y2] - r[x1][y1] + d[x2][y2] - d[x1][y2] + l[x2][y1] -
             l[x2][y2] + u[x1][y1] - u[x2][y1];
  return temp;
}
void solve() {
  cin >> n >> m >> t;
  cin >> tp >> tu >> td;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  init();
  int sx = 0, sy = 0, ex = 2, ey = 2;
  for (int i = 0; i + 2 < n; i++)
    for (int j = 0; j + 2 < m; j++)
      for (int p = i + 2; p < n; p++) {
        int lb = j + 1, ub = m;
        while (ub - lb > 1) {
          int mid = (ub + lb) >> 1;
          int temp = calc(i, j, p, mid);
          if (temp > t)
            ub = mid;
          else
            lb = mid;
          if (sx == -1 || abs(calc(sx, sy, ex, ey) - t) > abs(temp - t)) {
            sx = i;
            sy = j;
            ex = p;
            ey = mid;
          }
        }
      }
  cout << sx + 1 << ' ' << sy + 1 << ' ' << ex + 1 << ' ' << ey + 1 << endl;
}
int main() {
  solve();
  return 0;
}

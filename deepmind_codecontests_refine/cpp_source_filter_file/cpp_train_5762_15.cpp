#include <bits/stdc++.h>
const int mn = 2100;
const double pi = 3.1415926535897932384626433832795;
int n, ans1 = 0, ans2 = 0, u, v, tt;
int s[mn][mn], f[mn][mn];
double d1, d2, d;
int sqr(int x) { return x * x; }
void dfs(int x, int y) {
  if (!s[x][y]) return;
  s[x][y] = 0, ++tt;
  if (x > u || (x == u && y > v)) u = x, v = y;
  dfs(x - 1, y), dfs(x + 1, y);
  dfs(x, y - 1), dfs(x, y + 1);
}
int main() {
  scanf("%d", &n);
  int i, j, k, x, y;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) scanf("%d", f[i] + j);
  for (i = 1; i <= n - 4; ++i)
    for (j = 1; j <= n - 4; ++j) {
      k = 0;
      for (x = i; x <= i + 4; ++x)
        for (y = j; y <= j + 4; ++y) k += f[x][y];
      if (k >= 15) s[i][j] = 1;
    }
  for (i = 1; i <= n - 4; ++i)
    for (j = 1; j <= n - 4; ++j) {
      if (!s[i][j]) continue;
      u = i, v = j;
      tt = 0;
      dfs(i, j);
      d = sqrt(sqr(u - i) + sqr(v - j));
      if (d < 10) continue;
      d1 = fabs(d * d * 0.25 * pi - tt);
      d2 = fabs(d * d * 0.5 - tt);
      if (d1 < d2)
        ++ans1;
      else
        ++ans2;
    }
  printf("%d %d\n", ans1, ans2);
  return 0;
}

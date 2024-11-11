#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, mod = 998244853;
int n, m, sl, fh, ans, dp1[4010][4010], dp2[4010][4010];
int rd() {
  sl = 0;
  fh = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
void upd(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  n = rd();
  m = rd();
  dp1[1][1] = 1;
  dp2[0][0] = 1;
  for (int i = 1; i < n + m; ++i)
    for (int j = 1; j <= n && j <= i; ++j)
      if (2 * j - i > 0) {
        if (j < n) upd(dp1[i + 1][j + 1], dp1[i][j]);
        if (i - j < m) upd(dp1[i + 1][j], dp1[i][j]);
      }
  for (int i = 1; i <= n + m; ++i)
    for (int j = 1; j <= m && j <= i; ++j)
      if (i - 2 * j <= 0) {
        upd(dp2[i][j], dp2[i - 1][j - 1]);
        if (i - j) upd(dp2[i][j], dp2[i - 1][j]);
      }
  for (int i = 1; i <= n + m; ++i)
    for (int j = 1; j <= n; ++j)
      ans = (ans +
             1ll * (2 * j - i) * dp1[i][j] % mod * dp2[n + m - i][m - i + j]) %
            mod;
  printf("%d\n", ans);
  return 0;
}

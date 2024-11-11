#include <bits/stdc++.h>
using namespace std;
const long long inff = 0x3f3f3f3f3f3f3f3f;
int n, dp[1008][58][58], x, y, z, d[58][28], e[58][28], ans = -int(0x3f3f3f3f);
string a, b, c;
int as(int xx, int yy, int zz) {
  if (zz && d[xx][yy] != -1) return d[xx][yy];
  if (!zz && e[xx][yy] != -1) return e[xx][yy];
  if (zz) {
    for (int i(min(xx + 1, y)); i >= (0); --i) {
      int qw = 1;
      for (int j(1); j <= (i - 1); ++j)
        if (b[j - 1] != b[xx - i + j]) {
          qw = 0;
          break;
        }
      if (!i) return d[xx][yy] = 0;
      if (b[i - 1] - 'a' != yy) qw = 0;
      if (qw) return d[xx][yy] = i;
    }
  } else {
    for (int i(min(xx + 1, z)); i >= (0); --i) {
      int qw = 1;
      for (int j(1); j <= (i - 1); ++j)
        if (c[j - 1] != c[xx - i + j]) {
          qw = 0;
          break;
        }
      if (!i) return e[xx][yy] = 0;
      if (c[i - 1] - 'a' != yy) qw = 0;
      if (qw) return e[xx][yy] = i;
    }
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> c;
  x = a.size(), y = b.size(), z = c.size();
  memset(d, -1, sizeof(d)), memset(e, -1, sizeof(e));
  memset(dp, -int(0x3f3f3f3f), sizeof(dp));
  dp[0][0][0] = 0;
  for (int i(0); i <= (x - 1); ++i)
    for (int j(0); j <= (y); ++j)
      for (int k(0); k <= (z); ++k) {
        if (dp[i][j][k] == -int(0x3f3f3f3f)) continue;
        for (int q(0); q <= (25); ++q) {
          int cc = as(j, q, 1), dd = as(k, q, 0), qw = 0;
          if (cc == y) qw++;
          if (dd == z) qw--;
          if (a[i] == '*')
            dp[i + 1][cc][dd] = max(dp[i + 1][cc][dd], dp[i][j][k] + qw);
          else if (q == a[i] - 'a')
            dp[i + 1][cc][dd] = max(dp[i + 1][cc][dd], dp[i][j][k] + qw);
        }
      }
  for (int i(0); i <= (y); ++i)
    for (int j(0); j <= (z); ++j) ans = max(ans, dp[x][i][j]);
  cout << ans << endl;
  return 0;
}

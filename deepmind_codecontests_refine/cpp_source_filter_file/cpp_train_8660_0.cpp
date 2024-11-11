#include <bits/stdc++.h>
const long long mo = 1e9 + 7;
const int maxn = 2e3 + 3;
int n, m;
char s[maxn][maxn];
long long dp[maxn][maxn][2], dpb[maxn][maxn], dpr[maxn][maxn], bs[maxn][maxn],
    rs[maxn][maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= 0; --j) rs[i][j] = rs[i][j + 1] + (s[i][j] == 'R');
  }
  for (int i = n; i >= 0; --i) {
    for (int j = 1; j <= m; ++j) bs[i][j] = bs[i + 1][j] + (s[i][j] == 'R');
  }
  for (int i = n; i >= 1; --i) {
    dp[i][m][1] = bs[i][m] ? 0 : 1;
    dp[i][m][0] = 0;
    dpb[i][m] = dpb[i + 1][m] + dp[i][m][0];
    dpr[i][m] = dp[i][m][1];
  }
  for (int j = m - 1; j >= 1; --j) {
    dp[n][j][1] = 0;
    dp[n][j][0] = rs[n][j] ? 0 : 1;
    dpr[n][j] = dpr[n][j + 1] + dp[n][j][1];
    dpb[n][j] = dp[n][j][0];
  }
  for (int i = n - 1; i >= 1; --i)
    for (int j = m - 1; j >= 1; --j)
      for (int d = 0; d < 2; ++d) {
        if (d) {
          int k = bs[i + 1][j];
          dp[i][j][d] = (dpb[i + 1][j] - dpb[n - k + 1][j]) % mo;
          dpr[i][j] = (dpr[i][j + 1] + dp[i][j][d]) % mo;
        } else {
          int k = rs[i][j + 1];
          dp[i][j][d] = (dpr[i][j + 1] - dpr[i][m - k + 1]) % mo;
          dpb[i][j] = (dpb[i + 1][j] + dp[i][j][d]) % mo;
        }
      }
  printf("%lld\n", (dp[1][1][0] + dp[1][1][1]) % mo);
  return 0;
}

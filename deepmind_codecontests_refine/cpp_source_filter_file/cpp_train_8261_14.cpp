#include <bits/stdc++.h>
using namespace std;
long long dp[2][31][31][31][31];
const long long MOD = 1000000009;
int main() {
  ios::sync_with_stdio(false);
  int n, h;
  cin >> n >> h;
  dp[0][0][0][0][0] = 1;
  int nj, nl, nm, nk;
  long long tmp;
  int x = 0, y = 1;
  for (int i = 1; i <= n; i++) {
    x = x ^ 1, y = y ^ 1;
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < h + 1; k++)
        for (int l = 0; l < h + 1; l++)
          for (int m = 0; m < h + 1; m++) {
            tmp = dp[y][j][k][l][m];
            dp[y][j][k][l][m] = 0;
            tmp %= MOD;
            nj = j < 1 ? j + 1 : h;
            nk = min(k + 1, h);
            nl = min(l + 1, h);
            nm = min(m + 1, h);
            if (!j)
              dp[x][0][nk][nl][nm] += tmp;
            else
              dp[x][1][nk][nl][nm] += tmp;
            if (k != h)
              dp[x][0][nl][nm][nj] += tmp;
            else
              dp[x][1][nl][nm][nj] += tmp;
            if (l != h)
              dp[x][0][nm][nj][nk] += tmp;
            else
              dp[x][1][nm][nj][nk] += tmp;
            if (m != h)
              dp[x][0][nj][nk][nl] += tmp;
            else
              dp[x][1][nj][nk][nl] += tmp;
          }
  }
  int ans = 0;
  for (int j = 0; j < 2; j++)
    for (int k = 0; k < h + 1; k++)
      for (int l = 0; l < h + 1; l++)
        for (int m = 0; m < h + 1; m++)
          if (j < 1 || k < h || l < h || m < h) {
            ans += dp[x][j][k][l][m];
            ans %= MOD;
          }
  cout << ans << endl;
  return 0;
}

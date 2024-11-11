#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 3005;
int n, m;
char mp[maxn][maxn];
int dp[maxn][maxn];
long long a11, a22, a12, a21;
long long ans, ans1, ans2;
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
    memset(dp, 0, sizeof(dp));
    dp[1][2] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (mp[i][j] == '#') {
          dp[i][j] = 0;
          continue;
        }
        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
        dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
      }
    a11 = dp[n - 1][m];
    a12 = dp[n][m - 1];
    memset(dp, 0, sizeof(dp));
    dp[2][1] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (mp[i][j] == '#') {
          dp[i][j] = 0;
          continue;
        }
        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
        dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
      }
    a22 = dp[n][m - 1];
    a21 = dp[n - 1][m];
    ans1 = (a11 * a22) % mod;
    ans2 = (a12 * a21) % mod;
    ans = ((ans1 - ans2) % mod + mod) % mod;
    printf("%I64d\n", ans);
  }
  return 0;
}

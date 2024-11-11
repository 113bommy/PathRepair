#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, K = 13, M = 4, MOD = 1e9 + 7;
long long dp[N][K][1 << M];
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int all = (1 << m) - 1;
  dp[n + 1][0][0] = 1;
  for (int i = n; i > 0; i--) {
    for (int j = 0; j <= k; j++) {
      for (int mask = 0; mask < (1 << m); mask++) {
        int nwmask = (mask << 1) & all;
        dp[i][j][nwmask] += dp[i + 1][j][mask];
        dp[i][j][nwmask] %= MOD;
        if (j > 0) {
          nwmask |= 1;
          dp[i][j][nwmask] += dp[i + 1][j - 1][mask];
          for (int b = 0; b < m; b++)
            if (mask & (1 << b)) {
              dp[i][j][nwmask] += dp[i + 1][j - 1][mask];
            }
          dp[i][j][nwmask] %= MOD;
        }
      }
    }
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << m); ++mask) ans += dp[1][k][mask];
  cout << ans % MOD << endl;
}

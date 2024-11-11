#include <bits/stdc++.h>
using namespace std;
long long n, t, dp[25][5][25];
int main() {
  cin >> n >> t;
  dp[1][1][0] = dp[1][2][0] = dp[1][3][0] = 1;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= 4; ++j) {
      for (long long k = 0; k < 2 * 1; ++k) {
        if (k % 2 == 0) {
          if (i != 1)
            for (long long ii = j - 1; ii >= 1; --ii)
              dp[i + 1][ii][k + 1] += dp[i][j][k];
          for (long long ii = j + 1; ii <= 4; ++ii)
            dp[i + 1][ii][k] += dp[i][j][k];
        } else {
          if (i != 1)
            for (long long ii = j - 1; ii >= 1; --ii)
              dp[i + 1][ii][k] += dp[i][j][k];
          for (long long ii = j + 1; ii <= 4; ++ii)
            dp[i + 1][ii][k + 1] += dp[i][j][k];
        }
      }
    }
  }
  long long ans = 0;
  for (long long j = 1; j <= 4; ++j) ans += dp[n][j][2 * t - 1];
  cout << ans;
  return 0;
}

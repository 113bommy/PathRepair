#include <bits/stdc++.h>
using namespace std;
long long i = 1, dp[1005][105][3], ans, n, k, mod;
long long q[1005];
int main() {
  cin >> n >> k >> mod;
  dp[0][0][0] = 1;
  q[0] = 1;
  for (int i = 1; i <= n; i++) q[i] = q[i - 1] * 10, q[i] %= k;
  while (i <= n) {
    for (int j = 0; j < k; j++) {
      for (int y = 0; y <= 9; y++) {
        int t = 1;
        if (y == 0 && i == n) continue;
        if (y == 0 && j == 0) t = 0;
        int l = (j + y * q[i - 1]) % k;
        if (l == 0) {
          dp[i][0][1] += dp[i - 1][j][1] + dp[i - 1][j][0] * t,
              dp[i][0][1] %= mod;
          if (t == 0) dp[i][0][0] += dp[i - 1][j][0], dp[i][0][0] %= mod;
        } else {
          dp[i][l][0] += dp[i - 1][j][0];
          dp[i][l][0] %= mod;
          dp[i][l][1] += dp[i - 1][j][1];
          dp[i][l][1] %= mod;
        }
      }
    }
    i++;
  }
  for (int j = 0; j < k; j++) ans += dp[n][j][1], ans %= mod;
  cout << ans;
}

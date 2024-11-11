#include <bits/stdc++.h>
using namespace std;
long long i, i1, j, k, k1, t, n, m, res, check1, a, b, mod, dp[510][510];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mod = 998244353;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      if (j == 0 || j == 1) {
        dp[i][j] = 2;
      } else if (j <= i) {
        dp[i][j] = (2 * dp[i][j - 1] + mod) % mod;
      } else {
        dp[i][j] = (2 * dp[i][j - 1] - dp[i][j - i - 1] + mod) % mod;
      }
    }
  }
  dp[0][0] = 0;
  for (i = 1; i <= n; i++) {
    dp[i][0] = 0;
    dp[0][i] = 0;
  }
  res = 0;
  for (i = 1; i <= n; i++) {
    m = (mod + dp[i][n] - dp[i - 1][n]) * dp[min((k - 1) / i, n)][n];
    res += m;
    res %= mod;
  }
  if (res % 2 == 1) {
    res += mod;
  }
  res /= 2;
  res %= mod;
  cout << res;
  return 0;
}

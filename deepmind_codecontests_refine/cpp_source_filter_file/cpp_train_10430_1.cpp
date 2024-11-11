#include <bits/stdc++.h>
using namespace std;
const long long N = 2222, M = 998244353;
long long n, k, h[N], dp[N][N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> h[i];
  if (k == 1) {
    cout << 0;
    return 0;
  }
  if (h[0] == h[1 % n]) {
    dp[0][n] = k;
  } else {
    dp[0][n + 1] = 1;
    dp[0][n - 1] = 1;
    dp[0][n] = (k - 2) % M;
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j <= 2 * n; j++) {
      if (h[i] == h[(i + 1) % n]) {
        dp[i][j] = dp[i - 1][j] * k % M;
      } else {
        if (j < 2 * n) dp[i][j] += dp[i - 1][j + 1];
        dp[i][j] %= M;
        if (j > 0) dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] %= M;
        dp[i][j] += dp[i - 1][j] * (k - 2) % M;
        dp[i][j] %= M;
      }
    }
  }
  long long ans = 0;
  for (long long i = n + 1; i <= 2 * n; i++) {
    ans += dp[n - 1][i];
    ans %= M;
  }
  cout << ans;
  return 0;
}

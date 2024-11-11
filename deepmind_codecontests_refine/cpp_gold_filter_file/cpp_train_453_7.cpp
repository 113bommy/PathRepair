#include <bits/stdc++.h>
using namespace std;
const long long MAXn = 2e3 + 10;
const long long MOD = 1e9 + 7;
long long n, m, s[MAXn], dp[MAXn][MAXn], a[MAXn], ans;
signed main() {
  cin >> n >> m;
  for (long long i = 1; i < n + 1; ++i) {
    dp[2][i] = i;
    s[i + 1] += i;
    a[i + 1] += i;
  }
  for (long long i = 3; i < m + 1; ++i) {
    for (long long j = 1; j < n + 1; ++j) {
      s[j] += dp[i][j - 1];
      s[j] %= MOD;
      a[j] += s[j];
      a[j] %= MOD;
      dp[i][j] = (a[j] + 1) % MOD;
    }
  }
  for (long long i = 1; i < n + 1; ++i) {
    for (long long j = 2; j < m + 1; ++j) {
      long long x = (dp[j][i] * (dp[j][n - i + 1] - dp[j][n - i] + MOD)) % MOD;
      x = (x * (m + 1 - j)) % MOD;
      ans += x;
      ans %= MOD;
    }
  }
  return cout << ans << endl, 0;
}

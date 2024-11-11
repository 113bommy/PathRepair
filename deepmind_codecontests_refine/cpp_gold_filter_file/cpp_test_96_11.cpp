#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long mod = 998244353;
const double eps = 1e-7;
long long n, m, k, x;
long long dp[510][510];
long long c[510][510];
long long qsm(long long a, long long b) {
  long long ans = 1, temp = a;
  while (b) {
    if (b & 1) ans = (ans * temp) % mod;
    temp = (temp * temp) % mod;
    b >>= 1;
  }
  return ans;
}
long long C(long long n, long long m) { return c[n][m]; }
void solve() {
  for (long long i = (1); i <= (x); i++) dp[1][i] = i;
  for (long long i = (2); i <= (n); i++) {
    for (long long j = (1); j <= (x); j++) {
      if (i <= j)
        for (long long k = (0); k <= (i - 1); k++)
          dp[i][j] +=
              dp[i - k][j - i + 1] * qsm(i - 1, k) % mod * C(i, k) % mod,
              dp[i][j] %= mod;
    }
  }
  long long ans = (qsm(x, n) - dp[n][x] + mod) % mod;
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  for (long long i = (0); i <= (500); i++) c[i][0] = 1;
  for (long long i = (1); i <= (500); i++) {
    for (long long j = (1); j <= (i); j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  cin >> n >> x;
  solve();
}

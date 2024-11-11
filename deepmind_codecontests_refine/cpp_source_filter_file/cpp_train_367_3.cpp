#include <bits/stdc++.h>
using namespace std;
const int N = 1010, D = 12;
int n, d, MOD;
long long dp[N][D][N], inv[D];
long long power(long long a, int b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return res;
}
int main() {
  cin >> n >> d >> MOD;
  if (n == 1) return puts("0"), 0;
  for (int i = (1); i <= (d); ++i) inv[i] = power(i, MOD - 2);
  dp[1][0][0] = 1;
  dp[1][d - 1][0] = 1;
  for (int i = (2); i <= (n); ++i) {
    for (int j = (1); j <= (min(d, i - 1)); ++j) {
      for (int k = (1); k <= (i - 1); ++k) {
        dp[i][j][k] = dp[i][j][k - 1];
        long long tmp = 1;
        for (int t = 1; t <= j && k * t < i; ++t) {
          tmp = 1ll * tmp * (dp[k][d - 1][k - 1] + t - 1) % MOD;
          tmp = 1ll * tmp * inv[t] % MOD;
          dp[i][j][k] = (dp[i][j][k] +
                         1ll * dp[i - k * t][j - t][min(k - 1, i - k * t - 1)] *
                             tmp % MOD) %
                        MOD;
        }
      }
    }
  }
  long long ans = dp[n][d][(n - 1) >> 1];
  if (!(n & 1)) {
    long long t = dp[n >> 1][d - 1][(n >> 1) - 1];
    (ans += 1ll * (t + 1) * t / 2 % MOD) %= MOD;
  }
  cout << ans << endl;
  return 0;
}

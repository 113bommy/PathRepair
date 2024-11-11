#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 5, MOD = 998244353;
long long n, k, MIN, sum, ans, now;
long long f[N][N], g[N];
signed main() {
  scanf("%lld%lld", &n, &k);
  MIN = min(n, k);
  for (register long long i = 1; i <= MIN; ++i) {
    f[i][1] = 2;
    sum = f[i][1];
    for (register long long j = 2; j <= i; ++j) {
      f[i][j] = f[i][j - 1] * 2 % MOD;
      sum = (sum + f[i][j]) % MOD;
    }
    for (register long long j = i + 1; j <= n; ++j) {
      f[i][j] = sum;
      sum = (sum - f[i][j - i] + f[i][j] + MOD) % MOD;
    }
  }
  ans = 0;
  for (register long long i = 1; i <= MIN; ++i) {
    now = min(k / i, n);
    g[1] = f[i][n] - f[i - 1][n];
    sum = g[1];
    for (register long long j = 2; j <= now; ++j) {
      g[j] = g[j - 1] * 2 % MOD;
      sum = (sum + g[j]) % MOD;
    }
    for (register long long j = now + 1; j <= n; ++j) {
      g[j] = sum;
      sum = (sum - g[j - now] + g[j] + MOD) % MOD;
    }
    ans = (ans + g[n]) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}

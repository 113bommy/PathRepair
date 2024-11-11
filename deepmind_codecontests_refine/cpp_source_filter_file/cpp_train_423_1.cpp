#include <bits/stdc++.h>
using namespace std;
const long long mod = 174086401;
const long long N = 2005;
long long n, K, ans, sum, sum2, f[N][N], g[N];
long long kuai(long long a, long long b) {
  if (b == 0) return 1ll;
  if (b == 1) return a;
  long long x = kuai(a, b / 2);
  if (b % 2 == 0) return x * x % mod;
  return x * x % mod * a % mod;
}
signed main() {
  scanf("%lld%lld", &n, &K);
  K--;
  for (long long i = 1; i <= n; i++) {
    sum = 2;
    f[i][1] = 2;
    for (long long j = 2; j <= i; j++) {
      f[i][j] = f[i][j - 1] * 2 % mod;
      sum = (sum + f[i][j]) % mod;
    }
    for (long long j = i + 1; j <= n; j++) {
      f[i][j] = sum;
      sum = ((sum - f[i][j - i] + f[i][j]) % mod + mod) % mod;
    }
  }
  for (long long i = 1; i <= n; i++) {
    long long k = K / i;
    k = min(k, n);
    if (k == 0) continue;
    sum2 = 2;
    g[1] = 2;
    for (long long j = 2; j <= k; j++) {
      g[j] = g[j - 1] * 2 % mod;
      sum2 = (sum2 + g[j]) % mod;
    }
    for (long long j = k + 1; j <= n; j++) {
      g[j] = sum2;
      sum2 = ((sum2 - g[j - k] + g[j]) % mod + mod) % mod;
    }
    ans = (ans + g[n] * (f[i][n] - f[i - 1][n] + mod) % mod) % mod;
  }
  cout << ans * kuai(2, mod - 2) % mod;
  return 0;
}

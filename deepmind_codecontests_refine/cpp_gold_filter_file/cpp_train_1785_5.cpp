#include <bits/stdc++.h>
using namespace std;
long long int Pow(long long int a, long long int b, long long int md,
                  long long int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans % md;
}
const long long int MAXK = 1e6 + 10;
const long long int MAXN = 2e3 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
long long int dp[MAXN][MAXN], fact[MAXK], inv[MAXK], ans = 0, n, m, k;
long long int add(long long int x, long long int y) { return (x + y) % MOD; }
long long int mul(long long int x, long long int y) { return x * y % MOD; }
long long int C(long long int x, long long int y) {
  if (y > x) return 0;
  return fact[x] * inv[y] % MOD * inv[x - y] % MOD;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  if (m == 1) return !printf("%lld\n", Pow(k, n, MOD));
  fact[0] = inv[0] = 1;
  for (long long int i = 1; i < MAXK; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = Pow(fact[i], MOD - 2, MOD);
  }
  dp[0][0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= i; j++) {
      dp[i][j] = j * (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j <= i; j++) {
      ans = add(ans, mul(Pow(j, n * (m - 2) % MOD, MOD),
                         mul(dp[n][i] * dp[n][i] % MOD,
                             mul(C(k - i, i - j), mul(C(k, i), C(i, j))))));
    }
  }
  printf("%lld\n", ans);
  return 0;
}

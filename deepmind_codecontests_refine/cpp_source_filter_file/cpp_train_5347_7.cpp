#include <bits/stdc++.h>
using namespace std;
int K, n;
const long long mod = 1e9 + 7;
long long f[110][110], dp[110][110 * 110], C[110][110], m;
long long qpow(long long base, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (res * base) % mod;
    base = base * base % mod;
    k >>= 1;
  }
  return res;
}
int main() {
  scanf("%d%lld%d", &n, &m, &K);
  register int i, j, k;
  C[0][0] = 1;
  for (i = 1; i <= n; i++) {
    C[i][0] = C[i][1] = 1;
    for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  for (i = 1; i <= n; i++)
    for (j = 0; j <= n; j++) f[i][j] = qpow(C[n][j], 1ll * (m - i + n) / n);
  dp[0][0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= i * n; j++) {
      for (k = max(j - n, 0); k <= j; k++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][k] * f[i][j - k] % mod) % mod;
      }
    }
  }
  printf("%I64d", dp[n][K]);
  return 0;
}

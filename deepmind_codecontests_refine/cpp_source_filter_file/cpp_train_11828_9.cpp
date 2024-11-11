#include <bits/stdc++.h>
using namespace std;
const int N = 266666;
int n, k, i, j, u, v, w, M = 1000000009;
long long fac[N], inv[N], dp[22][22], a[18][N], b[N];
long long qpow(long long a, long long b) {
  long long s = a, ans = 1;
  while (b) {
    if (b & 1) ans = ans * s % M;
    b >>= 1;
    s = s * s % M;
  }
  return ans;
}
int main() {
  scanf("%d %d %d", &n, &k, &M);
  if (n & 1) {
    cout << qpow(k, n);
    return 0;
  }
  fac[0] = 1;
  for (i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % M;
  inv[n] = qpow(fac[n], M - 2);
  for (i = n - 1; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % M;
  n >>= 1;
  for (i = 0; i <= n; ++i) {
    int pp = __builtin_popcount(i);
    a[pp][i] = inv[i * 2];
  }
  for (i = 0; i < 17; ++i)
    for (j = 0; j < 17; ++j)
      for (u = 0; u < (1 << 17); ++u)
        if ((u >> j) & 1) a[i][u] += a[i][u ^ (1 << j)];
  for (i = 0; i < 17; ++i)
    for (u = 0; u < (1 << 17); ++u) a[i][u] %= M;
  int pn = __builtin_popcount(n);
  for (i = 0; i < (1 << 17); ++i) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (j = 1; j <= k; ++j) {
      for (u = 0; u <= 17; ++u) {
        for (v = 0; u + v <= 17; ++v)
          dp[j][u + v] = dp[j][u + v] + a[u][i] * dp[j - 1][v];
        if (u & 7 == 0)
          for (v = 0; v <= 17; ++v) dp[j][v] %= M;
      }
      for (v = 0; v <= 17; ++v) dp[j][v] %= M;
    }
    b[i] = dp[k][pn];
  }
  for (i = 0; i < 17; ++i)
    for (j = 0; j < (1 << 17); ++j)
      if ((j >> i) & 1) b[j] -= b[j ^ (1 << i)];
  cout << ((qpow(k, n * 2) - b[n] * fac[n * 2]) % M + M) % M << endl;
}

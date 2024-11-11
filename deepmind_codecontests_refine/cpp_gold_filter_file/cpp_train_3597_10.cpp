#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int K = 100005;
long long jc[K], mei[K], you[K], ny_b, n, m, a, b, k, inv[K], suml[1505][1505],
    f[1505][1505], sumr[1505][1505], pl[1505], pr[1505], sum_pl[1505],
    sum_g[1505];
long long pow(long long x, long long y, long long mod) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (long long)res * x % mod;
    y >>= 1;
    x = (long long)x * x % mod;
  }
  return res;
}
long long c(long long n, long long m) {
  return (long long)jc[m] * inv[m - n] % mod * inv[n] % mod;
}
int main() {
  scanf("%lld%lld%lld%lld%lld", &n, &m, &a, &b, &k);
  ny_b = pow(b, mod - 2, mod);
  mei[0] = you[0] = 1;
  mei[1] = (long long)a * ny_b % mod;
  you[1] = (long long)(b - a) * ny_b % mod;
  for (int i = 2; i <= k; i++)
    mei[i] = (long long)mei[i - 1] * mei[1] % mod,
    you[i] = (long long)you[i - 1] * you[1] % mod;
  jc[0] = 1;
  for (int i = 1; i <= k; i++) jc[i] = (long long)jc[i - 1] * i % mod;
  inv[k] = pow(jc[k], mod - 2, mod);
  for (int i = k - 1; i >= 0; i--)
    inv[i] = (long long)inv[i + 1] * (i + 1) % mod;
  for (int i = 0; i < m; i++) {
    if (i > k)
      pl[i + 1] = 0;
    else
      pl[i + 1] = (long long)c(i, k) * mei[i] % mod * you[k - i] % mod;
    pr[m - i] = pl[i + 1];
  }
  for (int i = 1; i <= m; i++) sum_pl[i] = (sum_pl[i - 1] + pl[i]) % mod;
  sumr[0][m] = 1;
  for (int i = 1; i <= n; i++) {
    for (int r = 1; r <= m; r++)
      sum_g[r] =
          (sum_g[r - 1] + (long long)pl[r] * sumr[i - 1][r - 1] % mod) % mod;
    for (int r = 1; r <= m; r++)
      f[i][r] = (long long)pr[r] * sum_pl[r] % mod *
                    (sumr[i - 1][m] - suml[i - 1][r + 1]) % mod -
                (long long)pr[r] * sum_g[r] % mod;
    for (int r = 1; r <= m; r++)
      suml[i][m - r + 1] = sumr[i][r] = (sumr[i][r - 1] + f[i][r]) % mod;
  }
  printf("%lld\n", (sumr[n][m] + mod) % mod);
  return 0;
}

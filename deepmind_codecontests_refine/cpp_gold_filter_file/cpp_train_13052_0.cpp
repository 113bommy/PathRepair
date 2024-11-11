#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx,avx2")
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const long long N = 1005, mod = 1e9 + 7;
long long f[N][N][2][2], g[N], ans[N], n, m, fac[N], inv[N];
long long C(long long n, long long m) {
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
  read(n);
  read(m);
  fac[0] = inv[0] = inv[1] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  for (long long i = 2; i <= n; i++)
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  for (long long i = 1; i <= n; i++) inv[i] = inv[i] * inv[i - 1] % mod;
  f[1][0][0][0] = f[1][1][0][1] = 1;
  for (long long i = 2; i <= n; i++)
    for (long long j = 0; j < i; j++) {
      f[i][j][0][0] =
          (f[i][j][0][0] + f[i - 1][j][0][0] + f[i - 1][j][1][0]) % mod;
      f[i][j][1][0] =
          (f[i][j][1][0] + f[i - 1][j][0][1] + f[i - 1][j][1][1]) % mod;
      f[i][j + 1][0][0] = f[i - 1][j][0][0];
      f[i][j + 1][0][1] = (f[i - 1][j][0][0] + f[i - 1][j][1][0]) % mod;
      f[i][j + 1][1][0] = f[i - 1][j][0][1];
      f[i][j + 1][1][1] = (f[i - 1][j][0][1] + f[i - 1][j][1][1]) % mod;
    }
  for (long long i = 0; i <= n; i++)
    g[i] = (f[n][i][0][0] + f[n][i][1][0]) * fac[n - i] % mod;
  for (long long i = 0; i <= n; i++)
    for (long long j = i, op = 1; j <= n; j++, op *= -1)
      ans[i] = (ans[i] + mod + op * C(j, i) * g[j] % mod) % mod;
  write(ans[m]);
}

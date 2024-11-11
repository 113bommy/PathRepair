#include <bits/stdc++.h>
const long long M = 505;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, m, p, f[M][M], g[M][M], C[M][M];
void init() {
  C[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
  }
}
long long sum(long long x) { return x * (x + 1) / 2 % p; }
signed main() {
  n = read();
  m = read();
  p = read();
  init();
  g[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= i; j++) {
      long long t = g[j - 1][j - 1] * g[i - j][i - j] % p * C[i - 1][j - 1] % p;
      long long s = (f[j - 1][j - 1] * g[i - j][i - j] +
                     f[i - j][i - j] * g[j - 1][j - 1]) %
                    p;
      g[i][i] = (g[i][i] + (i + 1) * t) % p;
      f[i][i] += (sum(j - 1) + sum(i - j)) * t % p;
      f[i][i] += (i + 1) * C[i - 1][j - 1] % p * s % p;
      f[i][i] %= p;
    }
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j < i; j++) {
      f[i][j] = f[i - 1][j], g[i][j] = g[i - 1][j];
      for (long long k = 1; k <= j; k++) {
        g[i][j] = (g[i][j] + g[k][k] * g[i - k - 1][j - k] % p * C[j][k]) % p;
        f[i][j] +=
            (f[i - k - 1][j - k] * g[k][k] + f[k][k] * g[i - k - 1][j - k]) %
            p * C[j][k] % p;
        f[i][j] %= p;
      }
    }
  printf("%lld\n", f[n][m]);
}

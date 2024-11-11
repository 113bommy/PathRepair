#include <bits/stdc++.h>
const long long M = 1 << 17;
const long long MOD = 1e9 + 7;
long long read() {
  long long num = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
  return num * flag;
}
long long n, cnt[18][M + 5], f[18][M + 5], inv2 = (MOD + 1) / 2;
long long ans, a[M + 5], b[M + 5], c[M + 5], fb[M + 5], bit[M + 5];
void fwt_or(long long *a, long long n, long long op) {
  for (long long i = 1; i < n; i <<= 1)
    for (long long p = i << 1, j = 0; j < n; j += p)
      for (long long k = 0; k < i; k++) {
        if (op == 1)
          a[i + j + k] = (a[i + j + k] + a[j + k]) % MOD;
        else
          a[i + j + k] = (a[i + j + k] - a[j + k] + MOD) % MOD;
      }
}
void fwt_and(long long *a, long long n, long long op) {
  for (long long i = 1; i < n; i <<= 1)
    for (long long p = i << 1, j = 0; j < n; j += p)
      for (long long k = 0; k < i; k++) {
        if (op == 1)
          a[j + k] = (a[j + k] + a[i + j + k]) % MOD;
        else
          a[j + k] = (a[j + k] - a[i + j + k] + MOD) % MOD;
      }
}
void fwt_xor(long long *a, long long n, long long op) {
  for (long long i = 1; i < n; i <<= 1)
    for (long long p = i << 1, j = 0; j < n; j += p)
      for (long long k = 0; k < i; k++) {
        long long x = a[j + k], y = a[i + j + k];
        a[j + k] = (x + y) % MOD;
        a[i + j + k] = (x + MOD - y) % MOD;
        if (op == -1) {
          a[j + k] = 1ll * a[j + k] * inv2 % MOD;
          a[i + j + k] = 1ll * a[i + j + k] * inv2 % MOD;
        }
      }
}
signed main() {
  n = read();
  for (long long i = 1; i < M; i++) bit[i] = bit[i >> 1] + (i & 1);
  for (long long i = 1; i <= n; i++) {
    long long x = read();
    b[x]++;
    c[x]++;
    cnt[bit[x]][x]++;
  }
  for (long long i = 0; i < 17; i++) fwt_xor(cnt[i], M, 1);
  for (long long i = 0; i < 17; i++)
    for (long long j = 0; j <= i; j++)
      for (long long k = 0; k < M; k++)
        f[i][k] = (f[i][k] + cnt[j][k] * cnt[i - j][k]) % MOD;
  for (long long i = 0; i < 17; i++) fwt_xor(f[i], M, -1);
  for (long long i = 0; i < M; i++) a[i] = f[bit[i]][i];
  fwt_xor(c, M, 1);
  for (long long i = 0; i < M; i++) c[i] = c[i] * c[i] % MOD;
  fwt_xor(c, M, -1);
  fb[1] = 1;
  for (long long i = 2; i < M; i++) fb[i] = (fb[i - 1] + fb[i - 2]) % MOD;
  for (long long i = 0; i < M; i++) {
    a[i] = a[i] * fb[i] % MOD;
    b[i] = b[i] * fb[i] % MOD;
    c[i] = c[i] * fb[i] % MOD;
  }
  fwt_and(a, M, 1);
  fwt_and(b, M, 1);
  fwt_and(c, M, 1);
  for (long long i = 0; i < M; i++) a[i] = a[i] * b[i] % MOD * c[i] % MOD;
  fwt_and(a, M, -1);
  for (long long i = 0; i < 17; i++) ans = (ans + a[1 << i]) % MOD;
  printf("%lld\n", ans);
}

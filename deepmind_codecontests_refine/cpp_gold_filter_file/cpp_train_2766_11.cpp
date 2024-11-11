#include <bits/stdc++.h>
using namespace std;
const long long g = 3;
const long long invg = 332748118;
const long long mod = 998244353;
const long long ff = 1e6 + 1;
const long long inf = 1e18 + 7;
long long n, k, m, len = 1, l, r[ff];
long long a[ff], b[ff];
long long f[3][ff];
long long s1[3][ff], s2[3][ff];
long long fr[3], se[3];
void getr() {
  fr[0] = 0;
  se[0] = 0;
  fr[1] = 0;
  se[1] = 1;
  fr[2] = 1;
  se[2] = 1;
  while (len <= k * 2) len <<= 1, l++;
  for (long long i = 0; i < len; ++i)
    r[i] = ((r[i >> 1] >> 1) | ((i & 1) << (l - 1)));
}
long long qsm(long long x, long long y) {
  long long c = 1;
  while (y) {
    if (y & 1) c = (c * x) % mod;
    y >>= 1;
    x = (x * x) % mod;
  }
  return c % mod;
}
void ntt(long long plen, long long *c, long long typ) {
  for (long long i = 0; i < plen; ++i)
    if (i < r[i]) swap(c[i], c[r[i]]);
  for (long long i = 1; i < plen; i <<= 1) {
    long long mi = (mod - 1) / (i << 1);
    long long plu = qsm(g, mi);
    if (typ == -1) plu = qsm(plu, mod - 2);
    for (long long j = 0; j < plen; j += (i << 1)) {
      long long w = 1;
      for (long long L = 0; L < i; ++L, w = (w * plu) % mod) {
        long long x = c[L + j] % mod, y = c[L + j + i] * w % mod;
        c[L + j] = (x + y) % mod;
        c[L + j + i] = ((x - y) % mod + mod) % mod;
      }
    }
  }
  long long iplen = qsm(plen, mod - 2);
  if (typ == -1)
    for (long long i = 0; i < plen; ++i) c[i] = c[i] * iplen % mod;
}
void mul() {
  for (long long i = 0; i <= 2; ++i) ntt(len, f[i], 1);
  for (long long i = 0; i <= 2; ++i)
    for (long long j = 0; j < len; ++j)
      s1[i][j] = (f[i >> 1][j] * f[i - (i >> 1)][j]) % mod;
  for (long long i = 0; i <= 2; ++i)
    for (long long j = 0; j < len; ++j)
      s2[i][j] = (f[(i >> 1) + 1][j] * f[i - (i >> 1) + 1][j]) % mod;
  for (long long i = 0; i <= 2; ++i) {
    ntt(len, s1[i], -1);
    ntt(len, s2[i], -1);
    for (long long j = 0; j < len; ++j)
      s1[i][j] = (s1[i][j] + s2[i][j - 1]) % mod;
  }
  for (long long i = 0; i <= 2; ++i)
    for (long long j = 0; j <= k; ++j) f[i][j] = s1[i][j];
  for (long long i = 0; i <= 2; ++i)
    for (long long j = k + 1; j < len; ++j) f[i][j] = 0;
}
void add() {
  for (long long i = 0; i <= k; ++i) f[2][i] = f[1][i], f[1][i] = f[0][i];
  for (long long i = 0; i <= k; ++i)
    f[0][i] = ((!i) ? f[1][i] : (f[1][i] + f[1][i - 1] + f[2][i - 1]) % mod);
}
void init() {
  long long S = 0;
  for (long long i = (1 << 30); i > 0; i >>= 1) {
    if (S) mul(), S <<= 1;
    if ((n & i)) add(), S++;
  }
}
void input() {
  scanf("%lld %lld", &n, &k);
  f[0][0] = 1;
}
void output() {
  for (long long i = 1; i <= k; ++i) {
    printf("%lld ", f[0][i]);
  }
}
signed main() {
  input();
  getr();
  init();
  output();
}

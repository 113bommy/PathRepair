#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005, mod = 998244353, g = 3;
long long add(long long x, long long y) {
  return x + y < mod ? x + y : x + y - mod;
}
long long rdc(long long x, long long y) {
  return x - y < 0 ? x - y + mod : x - y;
}
long long qpow(long long x, int y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret;
}
int n;
int rev[maxn << 1], lim, bit;
long long s[maxn << 1], fac[maxn], fav[maxn], c[maxn << 1], d[maxn << 1], ginv;
void NTT_init(int x) {
  lim = 1;
  bit = 0;
  while (lim <= x) {
    lim <<= 1;
    ++bit;
  }
  for (int i = 1; i < lim; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
}
void NTT(long long *x, int y) {
  for (int i = 1; i < lim; ++i)
    if (i < rev[i]) swap(x[i], x[rev[i]]);
  long long wn, w, u, v;
  for (int i = 1; i < lim; i <<= 1) {
    wn = qpow(y == 1 ? g : ginv, (mod - 1) / (i << 1));
    for (int j = 0; j < lim; j += (i << 1)) {
      w = 1;
      for (int k = 0; k < i; ++k) {
        u = x[j + k];
        v = x[j + k + i] * w % mod;
        x[j + k] = add(u, v);
        x[j + k + i] = rdc(u, v);
        w = w * wn % mod;
      }
    }
  }
  if (y == -1) {
    long long inv = qpow(lim, mod - 2);
    for (int i = 0; i < lim; ++i) x[i] = x[i] * inv % mod;
  }
}
void solve(int x) {
  if (x == 1) {
    s[1] = 1;
    return;
  }
  if (x & 1) {
    solve(x - 1);
    for (int i = x; i >= 1; --i) s[i] = add(s[i - 1], s[i] * (x - 1) % mod);
    return;
  }
  solve(x >> 1);
  for (int i = 0; i <= (x >> 1); ++i) {
    c[(x >> 1) - i] = s[i] * fac[i] % mod;
    d[i] = qpow(x >> 1, i) * fav[i] % mod;
  }
  NTT_init(x);
  NTT(c, 1);
  NTT(d, 1);
  for (int i = 0; i < lim; ++i) c[i] = c[i] * d[i] % mod;
  NTT(c, -1);
  reverse(c, c + (x >> 1) + 1);
  for (int i = 0; i <= (x >> 1); ++i) c[i] = c[i] * fav[i] % mod;
  for (int i = (x >> 1) + 1; i < lim; ++i) c[i] = 0;
  NTT_init(x << 1);
  NTT(s, 1);
  NTT(c, 1);
  for (int i = 0; i < lim; ++i) {
    s[i] = c[i] * s[i] % mod;
    c[i] = d[i] = 0;
  }
  NTT(s, -1);
  for (int i = x + 1; i < lim; ++i) s[i] = 0;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  fav[n] = qpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) fav[i] = fav[i + 1] * (i + 1) % mod;
}
long long comb(int x, int y) {
  return (fac[x] * fav[y] % mod) * fav[x - y] % mod;
}
int main() {
  int x, y;
  scanf("%d%d%d", &n, &x, &y);
  if (x + y > n + 1 || x == 0 || y == 0) {
    printf("0");
    return 0;
  }
  init();
  --n;
  ginv = qpow(g, mod - 2);
  if (n == 0) {
    s[0] = 1;
  } else {
    solve(n);
  }
  printf("%lld", s[x + y - 2] * comb(x + y - 2, x - 1) % mod);
  return 0;
}

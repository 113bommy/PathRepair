#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &a) {
  T x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  a = x * f;
}
template <typename T>
void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10) return (void)putchar(x + '0');
  write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  putchar('\n');
}
template <typename T>
void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T, typename... Args>
void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
template <typename T, typename... Args>
void writes(T t, Args... args) {
  writes(t);
  writes(args...);
}
template <typename T, typename... Args>
void writeln(T t, Args... args) {
  writes(t);
  writes(args...);
  putchar('\n');
}
const long long mod = 998244353;
long long n, m, p[100005 << 2], f[100005 << 2], g[100005 << 2], h[100005 << 2],
    lim, r[100005 << 2];
long long fac[100005], ifac[100005], inv[100005];
long long ksm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
void getr(long long lim) {
  for (long long i = 0; i < lim; i++)
    r[i] = (i & 1) * (lim >> 1) + (r[i >> 1] >> 1);
}
void ntt(long long *x, long long opt) {
  for (long long i = 0; i < lim; i++)
    if (r[i] < i) swap(x[i], x[r[i]]);
  for (long long l = 2; l <= lim; l <<= 1) {
    long long k = l >> 1, gn = ksm(3, (mod - 1) / l);
    for (long long i = 0; i < lim; i += l) {
      long long g = 1;
      for (long long j = 0; j < k; j++) {
        long long tmp = x[i + j + k] * g % mod;
        x[i + j + k] = (x[i + j] - tmp + mod) % mod;
        x[i + j] = (x[i + j] + tmp) % mod;
        g = g * gn % mod;
      }
    }
  }
  if (opt == -1) {
    reverse(x + 1, x + lim);
    long long inv = ksm(lim, mod - 2);
    for (long long i = 0; i < lim; i++) x[i] = x[i] * inv % mod;
  }
}
signed main() {
  read(n, m);
  m %= mod - 1;
  for (long long i = 0; i <= n; i++) read(p[i]);
  inv[1] = 1;
  for (long long i = 2; i <= n + 1; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  fac[0] = ifac[0] = 1;
  for (long long i = 1; i <= n + 1; i++)
    fac[i] = fac[i - 1] * i % mod, ifac[i] = ifac[i - 1] * inv[i] % mod;
  for (long long i = 0; i <= n; i++)
    f[i] = ifac[i], g[i] = p[n - i] * fac[n - i] % mod;
  lim = 1;
  while (lim < (n << 1) + 1) lim <<= 1;
  getr(lim);
  ntt(f, 1);
  ntt(g, 1);
  for (long long i = 0; i < lim; i++) g[i] = f[i] * g[i] % mod;
  ntt(g, -1);
  for (long long i = 0; i <= n; i++)
    g[n - i] = ksm(inv[i + 1], m) * g[n - i] % mod;
  for (long long i = 0; i <= n; i++) {
    if (i & 1)
      f[i] = mod - ifac[i];
    else
      f[i] = ifac[i];
  }
  for (long long i = n + 1; i < lim; i++) f[i] = g[i] = 0;
  ntt(f, 1);
  ntt(g, 1);
  for (long long i = 0; i < lim; i++) f[i] = f[i] * g[i] % mod;
  ntt(f, -1);
  reverse(f, f + n + 1);
  for (long long i = 0; i <= n; i++) writes(f[i] * ifac[i] % mod);
  puts("");
  return 0;
}

#include <bits/stdc++.h>
template <typename T>
inline void read(T& x) {
  int f = 0, c = getchar();
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  if (f) x = -x;
}
template <typename T, typename... Args>
inline void read(T& x, Args&... args) {
  read(x);
  read(args...);
}
template <typename T>
void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <typename T>
inline bool chkmin(T& x, const T& y) {
  return y < x ? (x = y, true) : false;
}
template <typename T>
inline bool chkmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
const long long mod = 998244353, G = 3, Gi = 332748118;
const int maxn = 1e5 + 7;
inline long long qpow(long long x, long long k) {
  long long s = 1;
  for (; k; x = x * x % mod, k >>= 1)
    ;
  if (k & 1) s = s * x % mod;
  return s;
}
inline void ntt(long long* A, int* r, int lim, int tp) {
  for (int i = 0; i < lim; ++i)
    if (i < r[i]) std::swap(A[i], A[r[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    long long wn = qpow(tp == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int j = 0; j < lim; j += mid << 1) {
      long long w = 1;
      for (int k = 0; k < mid; ++k, w = w * wn % mod) {
        long long x = A[j + k], y = w * A[j + k + mid] % mod;
        A[j + k] = (x + y) % mod;
        A[j + k + mid] = (x - y + mod) % mod;
      }
    }
  }
  if (tp == -1) {
    long long inv = qpow(lim, mod - 2);
    for (int i = 0; i < lim; ++i) A[i] = A[i] * inv % mod;
  }
}
int n, r[maxn << 2], lim, l;
long long m, p[maxn], fac[maxn], ifac[maxn];
long long a[maxn << 2], b[maxn << 2], g[maxn];
int main() {
  read(n, m);
  for (int i = 0; i <= n; ++i) read(p[i]);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n + 1; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[n + 1] = qpow(fac[n + 1], mod - 2);
  for (int i = n; i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  for (int i = 0; i <= n; ++i) {
    a[i] = ifac[i];
    b[i] = fac[n - i] * p[n - i] % mod;
  }
  for (lim = 1; lim <= (n << 1); ++l) lim <<= 1;
  for (int i = 0; i < lim; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
  ntt(a, r, lim, 1);
  ntt(b, r, lim, 1);
  for (int i = 0; i < lim; ++i) a[i] = a[i] * b[i] % mod;
  ntt(a, r, lim, -1);
  for (int i = 0; i <= n; ++i)
    g[i] = ifac[i] * a[n - i] % mod * qpow(qpow(i + 1, m), mod - 2) % mod;
  for (int i = 0; i <= n; ++i) {
    a[i] = ((i & 1) ? mod - 1 : 1ll) * ifac[i] % mod;
    b[i] = fac[n - i] * g[n - i] % mod;
  }
  for (int i = n + 1; i < lim; ++i) a[i] = b[i] = 0;
  ntt(a, r, lim, 1);
  ntt(b, r, lim, 1);
  for (int i = 0; i < lim; ++i) a[i] = a[i] * b[i] % mod;
  ntt(a, r, lim, -1);
  for (int i = 0; i <= n; ++i) write(ifac[i] * a[n - i] % mod), putchar(' ');
  return 0;
}

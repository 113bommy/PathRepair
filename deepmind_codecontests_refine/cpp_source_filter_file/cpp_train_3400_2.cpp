#include <bits/stdc++.h>
const long long mod = 998244353, g = 3, maxn = 1e6 + 9;
inline long long Pow(long long base, long long b) {
  long long ret(1);
  while (b) {
    if (b & 1) ret = ret * base % mod;
    base = base * base % mod;
    b >>= 1;
  }
  return ret;
}
long long r[maxn];
inline long long Fir(long long n) {
  long long limit(1), len(0);
  while (limit < (n << 1)) {
    limit <<= 1;
    ++len;
  }
  for (long long i = 0; i < limit; ++i)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << len - 1);
  return limit;
}
inline void NTT(long long *a, long long n, long long type) {
  for (long long i = 0; i < n; ++i)
    if (i < r[i]) std::swap(a[i], a[r[i]]);
  for (long long mid = 1; mid < n; mid <<= 1) {
    long long wn(Pow(g, (mod - 1) / (mid << 1)));
    if (type == -1) wn = Pow(wn, mod - 2);
    for (long long R = mid << 1, j = 0; j < n; j += R)
      for (long long k = 0, w = 1; k < mid; ++k, w = w * wn % mod) {
        long long x(a[j + k]), y(w * a[j + mid + k] % mod);
        a[j + k] = (x + y) % mod;
        a[j + mid + k] = (x - y + mod) % mod;
      }
  }
  if (type == -1) {
    long long ty(Pow(n, mod - 2));
    for (long long i = 0; i < n; ++i) a[i] = a[i] * ty % mod;
  }
}
long long T[maxn], F[maxn], H[maxn], G[maxn], fac[maxn], fav[maxn], tmp[maxn],
    sum[maxn], B[maxn];
inline void Mul(long long n, long long *a, long long *b, long long *ans) {
  long long limit(Fir(n));
  NTT(a, limit, 1);
  NTT(b, limit, 1);
  for (long long i = 0; i < limit; ++i) ans[i] = a[i] * b[i] % mod;
  NTT(ans, limit, -1);
}
inline void Solve(long long n, long long *a) {
  if (!n) {
    a[0] = 1;
    return;
  }
  if (n == 1) {
    a[1] = 1;
    return;
  }
  long long len(n / 2);
  Solve(len, a);
  for (long long i = 0; i <= len; ++i) F[i] = Pow(len, i) * fav[i] % mod;
  for (long long i = 0; i <= len; ++i) H[i] = fac[i] * a[i] % mod;
  for (long long i = 0; i <= (len >> 1); ++i) std::swap(H[i], H[len - i]);
  long long limit(Fir(len + 1));
  for (long long i = len + 1; i < limit; ++i) F[i] = H[i] = 0;
  NTT(F, limit, 1);
  NTT(H, limit, 1);
  for (long long i = 0; i < limit; ++i) G[i] = F[i] * H[i] % mod;
  NTT(G, limit, -1);
  for (long long i = 0; i <= len; ++i)
    tmp[i] = G[len - i] * Pow(fac[i], mod - 2) % mod;
  Mul(len + 1, a, tmp, B);
  for (long long i = 0; i <= (len << 1); ++i) a[i] = B[i];
  for (long long i = (len << 1) + 1; i <= (len << 2); ++i) a[i] = tmp[i] = 0;
  if (n & 1) {
    for (long long i = 0; i < n; ++i) T[i] = a[i];
    for (long long i = 1; i <= n; ++i)
      a[i] = (T[i - 1] + (n - 1) * T[i] % mod) % mod;
  }
}
inline long long Get_c(long long n, long long m) {
  return fac[n] * fav[m] % mod * fav[n - m] % mod;
}
long long n, a, b;
long long ans[maxn];
int main() {
  scanf("%lld%lld%lld", &n, &a, &b);
  fac[0] = fac[1] = 1;
  for (long long i = 2; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  fav[n] = Pow(fac[n], mod - 2);
  for (long long i = n; i >= 1; --i) fav[i - 1] = fav[i] * i % mod;
  Solve(n - 1, ans);
  printf("%lld\n", ans[a + b - 2] * Get_c(a + b - 2, a - 1));
}

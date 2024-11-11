#include <bits/stdc++.h>
template <typename A, typename B>
inline char smax(A &a, const B &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename A, typename B>
inline char smin(A &a, const B &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename I>
inline void read(I &x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
  x = c & 15;
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  f ? x = -x : 0;
}
const int N = 4e5 + 7;
const int P = 998244353;
const int Gi = 332748118;
const int G = 3;
int n, Aa, Bb, nlg;
int A[N], B[N], pw[20][N], cc[20];
int fac[N], inv[N], ifac[N];
inline void ycl(const int &n = ::n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = (long long)fac[i - 1] * i % P;
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) inv[i] = (long long)(P - P / i) * inv[P % i] % P;
  ifac[0] = 1;
  for (int i = 1; i <= n; ++i) ifac[i] = (long long)ifac[i - 1] * inv[i] % P;
}
inline int C(int x, int y) {
  if (x < y) return 0;
  return (long long)fac[x] * ifac[y] % P * ifac[x - y] % P;
}
inline int smod(int x) { return x >= P ? x - P : x; }
inline void sadd(int &x, const int &y) {
  x += y;
  x >= P ? x -= P : x;
}
inline int fpow(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = (long long)x * x % P)
    if (y & 1) ans = (long long)ans * x % P;
  return ans;
}
inline void NTT(int *a, int n, int f) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i > j) std::swap(a[i], a[j]);
    for (int l = n >> 1; (j ^= l) < l; l >>= 1)
      ;
  }
  for (int i = 1; i < n; i <<= 1) {
    int w = fpow(f > 0 ? G : Gi, (P - 1) / (i << 1));
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0, e = 1; k < i; ++k, e = (long long)e * w % P) {
        int x = a[j + k], y = (long long)e * a[i + j + k] % P;
        a[j + k] = smod(x + y), a[i + j + k] = smod(x + P - y);
      }
  }
  if (f < 0)
    for (int i = 0, p = fpow(n, P - 2); i < n; ++i)
      a[i] = (long long)a[i] * p % P;
}
inline void Mul(int *a, int *b, int *c, int n, int m) {
  int l = 1;
  while (l <= n + m) l <<= 1;
  for (int i = 0; i <= n; ++i) A[i] = a[i];
  for (int i = n + 1; i < l; ++i) A[i] = 0;
  for (int i = 0; i <= m; ++i) B[i] = b[i];
  for (int i = m + 1; i < l; ++i) B[i] = 0;
  NTT(A, l, 1), NTT(B, l, 1);
  for (int i = 0; i < l; ++i) A[i] = (long long)A[i] * B[i] % P;
  NTT(A, l, -1);
  for (int i = 0; i <= n + m; ++i) c[i] = A[i];
}
int a[N], b[N], c[N];
inline int Calc_Strling1(int n, int m) {
  if (!n) return m == 0;
  if (m > n || m <= 0) return 0;
  a[1] = 1;
  for (int k = 0; k < nlg; ++k) {
    int l = cc[k];
    for (int i = 0; i <= l; ++i) b[i] = (long long)a[l - i] * fac[l - i] % P;
    for (int i = 0; i <= l; ++i) c[i] = (long long)pw[k][i] * ifac[i] % P;
    Mul(b, c, b, l, l);
    for (int i = 0; i <= l; ++i) c[i] = (long long)b[l - i] * ifac[i] % P;
    Mul(a, c, a, l, l);
    if (cc[k + 1] & 1) {
      l = cc[k + 1];
      for (int i = l; i; --i) a[i] = (a[i - 1] + (l - 1ll) * a[i]) % P;
      a[0] = (l - 1ll) * a[0] % P;
    }
  }
  return a[m];
}
inline void work() {
  ycl();
  cc[0] = n - 1;
  while (cc[nlg] >> 1) cc[nlg + 1] = cc[nlg] >> 1, ++nlg;
  std::reverse(cc, cc + nlg + 1);
  for (int i = 0; i < nlg; ++i) {
    pw[i][0] = 1;
    for (int j = 1; j <= n; ++j) pw[i][j] = (long long)pw[i][j - 1] * cc[i] % P;
  }
  printf("%I64d\n", (long long)Calc_Strling1(n - 1, Aa + Bb - 2) *
                        C(Aa + Bb - 2, Aa - 1) % P);
}
inline void init() { read(n), read(Aa), read(Bb); }
int main() {
  init();
  work();
  fclose(stdin), fclose(stdout);
  return 0;
}

#include <bits/stdc++.h>
const int N = 262144, P = 1e9 + 7;
const double pi = acos(-1.0);
long long ri() {
  char c = getchar();
  long long x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c;
  return x * f;
}
struct cp {
  double r, i;
  cp(double _r = 0, double _i = 0) : r(_r), i(_i) {}
  cp operator*(const cp &a) const {
    return cp(r * a.r - i * a.i, r * a.i + i * a.r);
  }
  cp operator+(const cp &a) const { return cp(r + a.r, i + a.i); }
  cp operator-(const cp &a) const { return cp(r - a.r, i - a.i); }
} w[N], A[N], B[N], C[N], D[N];
int L, k, R[N], fac[N], ivf[N];
void Pre(int m) {
  int x = 0;
  L = 1;
  for (; (L <<= 1) < m; ++x)
    ;
  for (int i = 1; i < L; ++i) R[i] = (R[i >> 1] >> 1) | (i & 1) << x;
  for (int i = 0; i < L; ++i)
    w[i] = cp(cos(2 * pi * i / L), sin(2 * pi * i / L));
}
void FFT(cp *F) {
  for (int i = 0; i < L; ++i)
    if (i < R[i]) std::swap(F[i], F[R[i]]);
  for (int i = 2, d = L >> 1; i <= L; i <<= 1, d >>= 1)
    for (int j = 0; j < L; j += i) {
      cp *l = F + j, *r = F + j + (i >> 1), *p = w, tp;
      for (int k = 0; k < (i >> 1); ++k, ++l, ++r, p += d)
        tp = *r * *p, *r = *l - tp, *l = *l + tp;
    }
}
void Fill(cp *A, cp *B, const std::vector<int> &a, int n) {
  for (int i = 0; i < n; ++i) A[i] = a[i] & 32767, B[i] = a[i] >> 15;
  for (int i = n; i < L; ++i) A[i] = B[i] = 0;
}
long long V(double x) { return (long long)(x / L + 0.5) % P; }
std::vector<int> operator*(const std::vector<int> &a,
                           const std::vector<int> &b) {
  static std::vector<int> c;
  const int lim = 5e3;
  int n = a.size(), m = b.size();
  c.resize(n + m - 1);
  if (1LL * n * m <= lim) {
    for (int i = 0; i < n + m - 1; ++i) c[i] = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % P;
    return c;
  }
  Pre(n + m - 1);
  Fill(A, B, a, n);
  Fill(C, D, b, m);
  FFT(A);
  FFT(B);
  FFT(C);
  FFT(D);
  for (int i = 0; i < L; ++i) {
    const cp a = A[i], b = B[i], c = C[i], d = D[i];
    A[i] = a * c;
    B[i] = b * c + a * d;
    C[i] = b * d;
  }
  FFT(A);
  FFT(B);
  FFT(C);
  for (int i = 0; i < n + m - 1; ++i) {
    int j = L - i & L - 1;
    c[i] = ((V(C[j].r) << 30) % P + (V(B[j].r) << 15) % P + V(A[j].r)) % P;
  }
  return c;
}
int Pow(int x, int k) {
  int r = 1;
  for (; k; x = 1LL * x * x % P, k >>= 1)
    if (k & 1) r = 1LL * r * x % P;
  return r;
}
void Trans(std::vector<int> &a, int &la, const std::vector<int> &b,
           const int &lb) {
  static std::vector<int> c;
  c = b;
  for (int i = 0; i < c.size(); ++i)
    c[i] = 1LL * c[i] * Pow(2, 1LL * la * i % (P - 1)) % P;
  a = a * c;
  a.resize(k + 1);
  la += lb;
}
int c(int m, int n) { return 1LL * fac[m] * ivf[n] % P * ivf[m - n] % P; }
int main() {
  long long n = ri();
  k = ri();
  if (n > k) return puts("0"), 0;
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = 1LL * fac[i - 1] * i % P;
  ivf[k] = Pow(fac[k], P - 2);
  for (int i = k; i; --i) ivf[i - 1] = 1LL * ivf[i] * i % P;
  std::vector<int> e;
  e.resize(k + 1, 0);
  for (int i = 1; i <= k; ++i) e[i] = ivf[i];
  int len = 1;
  std::vector<int> x = e;
  int xlen = 1;
  --n;
  for (; n; n >>= 1, Trans(x, xlen, x, xlen))
    if (n & 1) Trans(e, len, x, xlen);
  int ans = 0;
  for (int i = 0; i <= k; ++i)
    ans = (ans + 1LL * e[i] * fac[i] % P * c(k, i)) % P;
  printf("%d\n", ans);
  return 0;
}

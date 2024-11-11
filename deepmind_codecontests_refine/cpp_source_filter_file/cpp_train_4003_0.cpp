#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
namespace {
const long long P = 998244353, G = 3;
long long qpow(long long x, long long y) {
  long long res = 1;
  for (; y; y >>= 1, x = x * x % P) {
    if (y & 1) res = res * x % P;
  }
  return res;
}
long long inv(long long x) { return qpow(x, P - 2); }
long long legendre_symbol(long long x) {
  if (x == 0) return 0;
  return qpow(x, P - 1 >> 1) == 1 ? 1 : -1;
}
long long tonelli_shanks(long long a) {
  if (legendre_symbol(a) != 1) return 0;
  long long q = P - 1, t = 0, n, z;
  while (!(q & 1)) q >>= 1, ++t;
  if (t == 1) return qpow(a, P + 1 >> 2);
  for (n = 1; n < P; ++n) {
    if (legendre_symbol(n) == -1) {
      z = qpow(n, q);
      break;
    }
  }
  long long y = z, r = t, x = qpow(a, q - 1 >> 1), b = x;
  x = x * a % P, b = x * b % P;
  while (1) {
    if (b == 1) return x;
    long long m;
    for (m = 1; m < r; ++m) {
      if (qpow(b, (1LL << m) % P) == 1) break;
    }
    long long v = qpow(y, (1LL << r - m - 1) % P);
    y = v * v % P, r = m, x = x * v % P, b = b * y % P;
  }
}
long long EPS[N], INV[N];
void init(int n) {
  long long g = qpow(G, (P - 1) / n);
  int l = n >> 1;
  EPS[l] = INV[1] = 1;
  for (int i = l + 1; i < n; ++i) EPS[i] = EPS[i - 1] * g % P;
  for (int i = l - 1; i > 0; --i) EPS[i] = EPS[i << 1];
  for (int i = 2; i < l; ++i) INV[i] = (P - P / i) * INV[P % i] % P;
}
void revbin(int n, long long x[]) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i < j) std::swap(x[i], x[j]);
    for (int k = n >> 1; (j ^= k) < k; k >>= 1) {
    }
  }
}
void dif_fft_core(int n, long long x[]) {
  for (int i = n; i >= 2; i >>= 1)
    for (int j = 0, l = i >> 1; j < n; j += i)
      for (int k = 0; k < l; ++k) {
        long long u = x[j + k], v = x[j + k + l];
        x[j + k] = (u + v) % P, x[j + k + l] = (u - v) * EPS[l + k] % P;
      }
}
void dit_fft_core(int n, long long x[]) {
  for (int i = 2; i <= n; i <<= 1)
    for (int j = 0, l = i >> 1; j < n; j += i)
      for (int k = 0; k < l; ++k) {
        long long u = x[j + k], v = EPS[l + k] * x[j + k + l];
        x[j + k] = (u + v) % P, x[j + k + l] = (u - v) % P;
      }
}
void dft(int n, long long x[]) { dif_fft_core(n, x); }
void idft(int n, long long x[]) {
  dit_fft_core(n, x), std::reverse(x + 1, x + n);
  long long in = P - (P - 1) / n;
  for (int i = 0; i < n; ++i) x[i] = (x[i] + P) * in % P;
}
void derivative(int n, const long long x[], long long y[]) {
  for (int i = 1; i < n; ++i) y[i - 1] = x[i] * i % P;
  y[n - 1] = 0;
}
void integral(int n, const long long x[], long long y[]) {
  for (int i = n - 1; i; --i) y[i] = x[i - 1] * INV[i] % P;
  y[0] = 0;
}
void polyInv(int n, const long long x[], long long y[]) {
  assert(x != y && x[0] != 0);
  static long long x_copy[N];
  memset(y, 0, sizeof(long long) * (n << 1));
  y[0] = inv(x[0]);
  for (int i = 2; i <= n; i <<= 1) {
    int l = i << 1;
    memcpy(x_copy, x, sizeof(long long) * i);
    memset(x_copy + i, 0, sizeof(long long) * i);
    dft(l, x_copy), dft(l, y);
    for (int j = 0; j < l; ++j) y[j] = y[j] * ((2 - x_copy[j] * y[j]) % P) % P;
    idft(l, y);
    memset(y + i, 0, sizeof(long long) * i);
  }
}
void polyLn(int n, const long long x[], long long y[]) {
  assert(x != y && x[0] == 1);
  static long long dx[N];
  derivative(n, x, dx);
  memset(dx + n, 0, sizeof(long long) * n);
  polyInv(n, x, y);
  int l = n << 1;
  dft(l, dx), dft(l, y);
  for (int i = 0; i < l; ++i) y[i] = dx[i] * y[i] % P;
  idft(l, y);
  integral(n, y, y);
  memset(y + n, 0, sizeof(long long) * n);
}
void polyExp(int n, const long long x[], long long y[]) {
  assert(x != y && x[0] == 0);
  static long long ln_y[N];
  memset(y, 0, sizeof(long long) * (n << 1));
  y[0] = 1;
  for (int i = 2; i <= n; i <<= 1) {
    int l = i << 1;
    polyLn(i, y, ln_y);
    for (int j = ln_y[0] = 1; j < i; ++j) ln_y[j] = (x[j] - ln_y[j]) % P;
    dft(l, y), dft(l, ln_y);
    for (int j = 0; j < l; ++j) y[j] = y[j] * ln_y[j] % P;
    idft(l, y);
    memset(y + i, 0, sizeof(long long) * i);
  }
}
long long quadraticResiduesModP(long long x) { return tonelli_shanks(x); }
void polySqrt(int n, const long long x[], long long y[]) {
  assert(x != y);
  static long long x_copy[N], y_inv[N];
  memset(y, 0, sizeof(long long) * (n << 1));
  assert((y[0] = quadraticResiduesModP(x[0])) != 0);
  if (P - y[0] < y[0]) y[0] = P - y[0];
  long long inv2 = (P >> 1) + 1;
  for (int i = 2; i <= n; i <<= 1) {
    int l = i << 1;
    memcpy(x_copy, x, sizeof(long long) * i);
    memset(x_copy + i, 0, sizeof(long long) * i);
    polyInv(i, y, y_inv), dft(l, x_copy), dft(l, y), dft(l, y_inv);
    for (int j = 0; j < l; ++j)
      y[j] = inv2 * (y[j] + y_inv[j] * x_copy[j] % P) % P;
    idft(l, y);
    memset(y + i, 0, sizeof(long long) * i);
  }
}
const long long IMAG = P - qpow(G, P - 1 >> 2);
void polySin(int n, const long long x[], long long y[]) {
  static long long exp_ix[N], exp_neg_ix[N], ix[N];
  for (int i = 0; i < n; ++i) ix[i] = x[i] * IMAG % P;
  polyExp(n, ix, exp_ix), polyInv(n, exp_ix, exp_neg_ix);
  long long iv = (P - (P - 1 >> 1)) * (P - IMAG) % P;
  for (int i = 0; i < n; ++i) y[i] = (P + exp_ix[i] - exp_neg_ix[i]) * iv % P;
}
void polyCos(int n, const long long x[], long long y[]) {
  static long long exp_ix[N], exp_neg_ix[N], ix[N];
  for (int i = 0; i < n; ++i) ix[i] = x[i] * IMAG % P;
  polyExp(n, ix, exp_ix), polyInv(n, exp_ix, exp_neg_ix);
  long long iv = P - (P - 1 >> 1);
  for (int i = 0; i < n; ++i) y[i] = (exp_ix[i] + exp_neg_ix[i]) * iv % P;
}
};  // namespace
long long a[N], b[N], c[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int t;
  for (int i = 0; i < n; ++i) cin >> t, a[t] = 1;
  for (int i = 0; i <= m; ++i) a[i] = (P - a[i] * 4);
  ++a[0];
  int len = 2;
  while (len < m) len <<= 1;
  init(len << 1);
  polySqrt(len, a, b);
  b[0] = (b[0] + 1) % P;
  polyInv(len, b, c);
  for (int i = 1; i <= m; ++i) cout << c[i] * 2 % P << '\n';
  return 0;
}

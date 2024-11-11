#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 21) + 10;
const double pi = acos(-1.0);
int rev[maxn];
bool flag[maxn];
struct Complex {
  double x, y;
  Complex(double _x = 0, double _y = 0) { x = _x, y = _y; }
  void clear() { x = y = 0; }
} A[maxn], B[maxn], C[maxn];
Complex operator+(const Complex &a, const Complex &b) {
  return Complex(a.x + b.x, a.y + b.y);
}
Complex operator-(const Complex &a, const Complex &b) {
  return Complex(a.x - b.x, a.y - b.y);
}
Complex operator*(const Complex &a, const double &b) {
  return Complex(a.x * b, a.y * b);
}
Complex operator*(const Complex &a, const Complex &b) {
  return Complex(a.x * b.x - b.y * a.y, a.x * b.y + b.x * a.y);
}
void FFT(Complex *a, int n, int type) {
  for (int i = 1; i < n; ++i) {
    if (i > rev[i]) swap(a[i], a[rev[i]]);
  }
  int i, j, k;
  Complex w, wn, pa, pb;
  for (k = 2; k <= n; k <<= 1) {
    wn = Complex(cos(2.0 * pi * type / k), sin(2.0 * pi * type / k));
    for (j = 0; j < n; j += k) {
      for (i = 0, w = Complex(1); i < (k >> 1); ++i, w = w * wn) {
        pa = a[i + j], pb = w * a[i + j + (k >> 1)];
        a[i + j] = pa + pb;
        a[i + j + (k >> 1)] = pa - pb;
      }
    }
  }
  if (type == -1) {
    double inv = 1.0 / n;
    for (i = 0; i < n; ++i) a[i] = a[i] * inv;
  }
}
char str[maxn];
int ans[maxn];
const double eps = 1e-2;
int Dcmp(double x) {
  if (x > -eps && x < eps) return 0;
  return x > 0 ? 1 : -1;
}
void solve() {
  int n, m, N, K;
  scanf("%d", &n);
  scanf("%s", str);
  for (int i = 0; i < n; ++i) {
    if (str[i] == '?')
      A[i] = Complex(0), B[n - i - 1] = Complex(0);
    else if (str[i] == 'K')
      A[i] = Complex(1), B[n - i - 1] = Complex(0);
    else
      A[i] = Complex(0), B[n - i - 1] = Complex(1);
  }
  m = n * 2 - 1;
  for (N = 1, K = 0; N < m; N <<= 1, ++K)
    ;
  --K;
  for (int i = 1; i < N; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << K);
  }
  FFT(A, N, 1);
  FFT(B, N, 1);
  for (int i = 0; i < N; ++i) C[i] = A[i] * B[i];
  FFT(C, N, -1);
  ans[0] = 0;
  flag[n] = 1;
  for (int i = 1; i < n; ++i) {
    if (Dcmp(C[n - 1 + i].x) == 0 && Dcmp(C[n - 1 - i].x) == 0)
      flag[i] = 1;
    else
      flag[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (flag[i])
      for (int j = i * 2; j <= n; j += i) {
        flag[i] &= flag[j];
      }
  }
  for (int i = 1; i <= n; ++i)
    if (flag[i]) ans[++ans[0]] = i;
  printf("%d\n", ans[0]);
  for (int i = 1; i < ans[0]; ++i) printf("%d ", ans[i]);
  printf("%d\n", ans[ans[0]]);
  for (int i = 0; i < N; ++i) {
    A[i].clear();
    B[i].clear();
    C[i].clear();
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}

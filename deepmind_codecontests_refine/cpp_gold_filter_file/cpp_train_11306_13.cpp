#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Complex {
 public:
  T r;
  T v;
  Complex(T r = 0, T v = 0) : r(r), v(v) {}
  Complex operator+(Complex b) { return Complex(r + b.r, v + b.v); }
  Complex operator-(Complex b) { return Complex(r - b.r, v - b.v); }
  Complex operator*(Complex b) {
    return Complex(r * b.r - v * b.v, r * b.v + v * b.r);
  }
  Complex operator/(double x) { return Complex(r / x, v / x); }
};
const int N = 1 << 21;
const double pi = acos(-1);
const double eps = 0.5;
inline void Rader(Complex<double> *f, int len) {
  for (int i = 1, j = len >> 1, k; i < len - 1; i++) {
    if (i < j) swap(f[i], f[j]);
    for (k = len >> 1; j >= k; j -= k, k >>= 1)
      ;
    if (j < k) j += k;
  }
}
inline void fft(Complex<double> *f, int len, int sign) {
  Rader(f, len);
  for (int l = 2; l <= len; l <<= 1) {
    Complex<double> wn(cos(2 * pi / l), sin(2 * pi * sign / l)), u, v;
    int hl = l >> 1;
    for (int i = 0; i < len; i += l) {
      Complex<double> w(1, 0);
      for (int j = 0; j < hl; j++, w = w * wn) {
        u = f[i + j], v = w * f[i + j + hl];
        f[i + j] = u + v, f[i + j + hl] = u - v;
      }
    }
  }
  if (sign == -1)
    for (int i = 0; i < len; i++) f[i] = f[i] / len;
}
int n, len;
char str[500005];
Complex<double> A[N], B[N];
inline void init() {
  scanf("%d", &n);
  gets(str);
  gets(str);
  for (len = 1; len < (n << 1); len <<= 1)
    ;
  memset(A, 0, sizeof(Complex<double>) * (len + 1));
  memset(B, 0, sizeof(Complex<double>) * (len + 1));
  for (int i = 0; i < n; i++) {
    if (str[i] == 'V')
      A[n - i - 1].r = 1;
    else if (str[i] == 'K')
      B[i].r = 1;
  }
}
bool bad[N];
int res = 0;
inline void solve() {
  fft(A, len, 1);
  fft(B, len, 1);
  for (int i = 0; i < len; i++) A[i] = A[i] * B[i];
  fft(A, len, -1);
  memset(bad, false, sizeof(bool) * (n + 1));
  for (int i = 0; i < len; i++)
    if (A[i].r >= eps) bad[abs(i - n + 1)] = true;
  for (int i = 1; i < n; i++)
    if (!bad[i])
      for (int j = i << 1; j < n; j += i)
        if (bad[j]) {
          bad[i] = true;
          break;
        }
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (!bad[i]) res++;
  printf("%d\n", res);
  for (int i = 1; i <= n; i++) {
    if (!bad[i]) printf("%d ", i);
  }
  putchar('\n');
}
int T;
int main() {
  scanf("%d", &T);
  while (T--) {
    init();
    solve();
  }
  return 0;
}

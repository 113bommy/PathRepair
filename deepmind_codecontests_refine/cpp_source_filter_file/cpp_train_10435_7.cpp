#include <bits/stdc++.h>
using namespace std;
int sqr(int x) { return x * x; }
long long mround(double x) { return x + (x > 0 ? 0.5 : -0.5); }
namespace FFT {
struct Complex {
  double r, i;
  Complex(double _r = 0, double _i = 0) : r(_r), i(_i){};
  double real() { return r; }
  double imag() { return i; }
  Complex operator+(const Complex& b) { return Complex(r + b.r, i + b.i); }
  void operator+=(Complex b) {
    r += b.r;
    i += b.i;
  }
  Complex operator-(const Complex& b) { return Complex(r - b.r, i - b.i); }
  Complex operator*(const Complex& b) {
    return Complex(r * b.r - i * b.i, r * b.i + i * b.r);
  }
  void operator/=(double x) {
    r /= x;
    i /= x;
  }
};
const int LOG = 19;
const int N = 1 << LOG;
const double PI = acos(-1.0);
Complex w[N];
int rev[N];
bool init_flag = false;
void init() {
  init_flag = true;
  w[0] = Complex(1, 0);
  w[1] = Complex(cos(2 * PI / N), sin(2 * PI / N));
  for (int i = 2; i < N; ++i) {
    if (i % 1000) {
      w[i] = w[i - 1] * w[1];
    } else {
      double angle = 2 * i * PI / N;
      w[i] = Complex(cos(angle), sin(angle));
    }
  }
  rev[0] = 0;
  for (int i = 1, k = -1; i < N; ++i) {
    k += !(i & (i - 1));
    rev[i] = rev[i ^ (1 << k)] ^ (1 << (LOG - k - 1));
  }
}
void fft(Complex* A, int k, bool inverse) {
  assert(init_flag);
  int n = 1 << k;
  for (int i = 0; i < n; ++i)
    if (i < (rev[i] >> (LOG - k))) swap(A[i], A[rev[i] >> (LOG - k)]);
  for (int lvl = 0; lvl < k; ++lvl) {
    int len = 1 << lvl;
    for (int st = 0; st < n; st += 2 * len) {
      for (int i = st; i < st + len; ++i) {
        static Complex l, r;
        l = A[i];
        r = A[i + len] * w[(i - st) << (LOG - 1 - lvl)];
        A[i] = l + r;
        A[i + len] = l - r;
      }
    }
  }
  if (inverse) {
    reverse(A + 1, A + n);
    for (int i = 0; i < n; ++i) A[i] /= n;
  }
}
Complex A[N];
void multiply(int* a, int sza, int* b, int szb, Complex* c) {
  int ln = 32 - __builtin_clz(sza + szb);
  int n = 1 << ln;
  for (int i = 0; i < n; ++i) {
    int x = (i < sza ? a[i] : 0);
    int y = (i < szb ? b[i] : 0);
    A[i] = Complex(x, y);
  }
  fft(A, ln, false);
  for (int i = 0; i < n; ++i) c[i] += A[i] * A[i];
}
}  // namespace FFT
const int sigma = 26;
int p[sigma];
const int N = (int)2e5 + 5;
char strS[N], strT[N];
int a[N], b[N], t[N];
int fs[N], ft[N];
FFT::Complex fres[FFT::N];
int main() {
  FFT::init();
  for (int i = 0; i < sigma; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    p[x] = i;
  }
  scanf("%s %s", strT, strS);
  int m = strlen(strT);
  reverse(strT, strT + m);
  int n = strlen(strS);
  for (int i = 0; i < m; ++i) {
    t[i] = strT[i] - 'a';
  }
  for (int i = 0; i < n; ++i) {
    a[i] = strS[i] - 'a';
    b[i] = p[a[i]];
  }
  for (int i = 0; i < n; ++i) fs[i] = -2 * a[i] * b[i] * (a[i] + b[i]);
  for (int i = 0; i < m; ++i) ft[i] = t[i];
  FFT::multiply(fs, n, ft, m, fres);
  for (int i = 0; i < n; ++i) fs[i] = sqr(a[i]) + sqr(b[i]) + 4 * a[i] * b[i];
  for (int i = 0; i < m; ++i) ft[i] *= t[i];
  FFT::multiply(fs, n, ft, m, fres);
  for (int i = 0; i < n; ++i) fs[i] = -2 * (a[i] + b[i]);
  for (int i = 0; i < m; ++i) ft[i] *= t[i];
  FFT::multiply(fs, n, ft, m, fres);
  FFT::fft(fres, 32 - __builtin_clz(n + m), true);
  long long sum = 0;
  for (int i = 0; i < m; ++i) sum += sqr(sqr(t[i]));
  for (int i = 0; i < m; ++i) sum += sqr(a[i] * b[i]);
  for (int i = m - 1; i < n; ++i) {
    long long out = mround(fres[i].imag() * 0.5) + sum;
    printf("%d", !out);
    sum -= sqr(a[i - m + 1] * b[i - m + 1]);
    sum += sqr(a[i + 1] * b[i + 1]);
  }
}

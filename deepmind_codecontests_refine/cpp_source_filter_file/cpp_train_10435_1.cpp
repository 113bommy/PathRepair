#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
struct Comp {
  double re, im;
  Comp(double x = 0.0, double y = 0.0) : re(x), im(y) {}
  Comp operator+(const Comp& rhs) const {
    return Comp(re + rhs.re, im + rhs.im);
  }
  Comp operator-(const Comp& rhs) const {
    return Comp(re - rhs.re, im - rhs.im);
  }
  Comp operator*(const Comp& rhs) const {
    return Comp(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
  }
  Comp operator/(double x) const { return Comp(re / x, im / x); }
};
int fft_len, fft_lg;
vector<int> r;
void ensure_base(int deg) {
  fft_len = 2, fft_lg = 1;
  while (fft_len <= deg) fft_len <<= 1, fft_lg++;
  r = vector<int>(fft_len, 0);
  for (int i = 0; i < fft_len; ++i)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (fft_lg - 1));
}
void fft(vector<Comp>& A, int dft) {
  for (int i = 0; i < fft_len; ++i)
    if (i < r[i]) swap(A[i], A[r[i]]);
  for (int mid = 1; mid < fft_len; mid <<= 1) {
    Comp wn = Comp(cos(PI / mid), sin(PI / mid) * dft);
    for (int len = mid << 1, s = 0; s < fft_len; s += len) {
      Comp w(1, 0);
      for (int k = 0; k < mid; ++k, w = w * wn) {
        Comp x = A[s + k], y = w * A[s + k + mid];
        A[s + k] = x + y;
        A[s + k + mid] = x - y;
      }
    }
  }
  if (dft == -1)
    for (int i = 0; i < fft_len; ++i) A[i] = A[i] / fft_len;
}
void fft_pmul(vector<Comp>& A, int degA, vector<Comp>& B, int degB) {
  ensure_base(degA + degB);
  A.resize(fft_len, 0), B.resize(fft_len, 0);
  fft(A, 1);
  fft(B, 1);
  for (int i = 0; i < fft_len; ++i) A[i] = A[i] * B[i];
  fft(A, -1);
}
int p[26], q[26];
string s, t;
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 26; ++i) cin >> q[i], p[q[i] - 1] = i;
  cin >> t >> s;
  int n = s.length(), m = t.length();
  reverse(t.begin(), t.end());
  vector<Comp> ps1(n), ps2(n), ps3(n), pt1(m), pt2(m), pt3(m);
  vector<double> p0(n);
  for (int i = 0; i < n; ++i) {
    int v = s[i] - 'a';
    ps3[i].re = -(2 * v + 2 * p[v]);
    ps2[i].re = v * v + 4 * v * p[v] + p[v] * p[v];
    ps1[i].re = -2 * v * p[v] * (v + p[v]);
    p0[i] = v * v * p[v] * p[v];
    if (i) p0[i] += p0[i - 1];
  }
  double t4 = 0;
  for (int i = 0; i < m; ++i) {
    int v = t[i] - 'a';
    pt3[i].re = v * v * v;
    pt2[i].re = v * v;
    pt1[i].re = v;
    t4 += v * v * v * v;
  }
  fft_pmul(ps3, n, pt3, m);
  fft_pmul(ps2, n, pt2, m);
  fft_pmul(ps1, n, pt1, m);
  for (int i = m - 1; i < n; ++i) {
    double res = t4 + ps3[i].re + ps2[i].re + ps1[i].re + p0[i] -
                 (i - m < 0 ? 0 : p0[i - m]);
    putchar('0' + (fabs(res) < 1e-7));
  }
  return 0;
}

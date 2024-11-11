#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1},
          dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T &a, U b) {
  return a < b ? (a = b, true) : false;
}
template <typename T, typename U>
inline bool chmin(T &a, U b) {
  return a > b ? (a = b, true) : false;
}
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;
template <typename T>
vector<int> z_algorithm(const T &s) {
  int n = s.size();
  vector<int> res(n);
  res[0] = n;
  int j = 0;
  for (int i = 1; i < n;) {
    while (i + j < n && s[j] == s[i + j]) ++j;
    res[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < n && k + res[k] < j) {
      res[i + k] = res[k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return res;
}
namespace FFT {
using Real = double;
struct Complex {
  Real re, im;
  Complex(Real re = 0, Real im = 0) : re(re), im(im) {}
  inline Complex operator+(const Complex &x) const {
    return Complex(re + x.re, im + x.im);
  }
  inline Complex operator-(const Complex &x) const {
    return Complex(re - x.re, im - x.im);
  }
  inline Complex operator*(const Complex &x) const {
    return Complex(re * x.re - im * x.im, re * x.im + im * x.re);
  }
  inline Complex mul_real(Real r) const { return Complex(re * r, im * r); }
  inline Complex mul_pin(Real r) const { return Complex(-im * r, re * r); }
  inline Complex conj() const { return Complex(re, -im); }
};
vector<int> butterfly{0};
vector<vector<Complex>> zeta{{{1, 0}}};
void calc(int n) {
  int prev_n = butterfly.size();
  if (n <= prev_n) return;
  butterfly.resize(n);
  int prev_lg = zeta.size(), lg = __builtin_ctz(n);
  for (int i = (1); i < (prev_n); ++i) butterfly[i] <<= lg - prev_lg;
  for (int i = (prev_n); i < (n); ++i)
    butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
  zeta.resize(lg);
  for (int i = (prev_lg); i < (lg); ++i) {
    zeta[i].resize(1 << i);
    Real angle = -M_PI * 2 / (1 << (i + 1));
    for (int j = (0); j < (1 << (i - 1)); ++j) {
      zeta[i][j << 1] = zeta[i - 1][j];
      Real theta = angle * ((j << 1) + 1);
      zeta[i][(j << 1) + 1] = {cos(theta), sin(theta)};
    }
  }
}
void sub_dft(vector<Complex> &a) {
  int n = a.size();
  calc(n);
  int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);
  for (int i = (0); i < (n); ++i) {
    int j = butterfly[i] >> shift;
    if (i < j) swap(a[i], a[j]);
  }
  for (int block = 1; block < n; block <<= 1) {
    int den = __builtin_ctz(block);
    for (int i = 0; i < n; i += (block << 1))
      for (int j = (0); j < (block); ++j) {
        Complex tmp = a[i + j + block] * zeta[den][j];
        a[i + j + block] = a[i + j] - tmp;
        a[i + j] = a[i + j] + tmp;
      }
  }
}
template <typename T>
vector<Complex> dft(const vector<T> &a) {
  int sz = a.size(), lg = 1;
  while ((1 << lg) < sz) ++lg;
  vector<Complex> c(1 << lg);
  for (int i = (0); i < (sz); ++i) c[i].re = a[i];
  sub_dft(c);
  return c;
}
vector<Real> real_idft(vector<Complex> &a) {
  int n = a.size(), half = n >> 1, quarter = half >> 1;
  calc(n);
  a[0] = (a[0] + a[half] + (a[0] - a[half]).mul_pin(1)).mul_real(0.5);
  int den = __builtin_ctz(half);
  for (int i = (1); i < (quarter); ++i) {
    int j = half - i;
    Complex tmp1 = a[i] + a[j].conj(),
            tmp2 = ((a[i] - a[j].conj()) * zeta[den][j]).mul_pin(1);
    a[i] = (tmp1 - tmp2).mul_real(0.5);
    a[j] = (tmp1 + tmp2).mul_real(0.5).conj();
  }
  if (quarter > 0) a[quarter] = a[quarter].conj();
  a.resize(half);
  sub_dft(a);
  reverse(a.begin() + 1, a.end());
  Real r = 1.0 / half;
  vector<Real> res(n);
  for (int i = (0); i < (n); ++i)
    res[i] = (i & 1 ? a[i >> 1].im : a[i >> 1].re) * r;
  return res;
}
void idft(vector<Complex> &a) {
  int n = a.size();
  sub_dft(a);
  reverse(a.begin() + 1, a.end());
  Real r = 1.0 / n;
  for (int i = (0); i < (n); ++i) a[i] = a[i].mul_real(r);
}
template <typename T>
vector<Real> convolution(const vector<T> &a, const vector<T> &b) {
  int a_sz = a.size(), b_sz = b.size(), sz = a_sz + b_sz - 1, lg = 1;
  while ((1 << lg) < sz) ++lg;
  int n = 1 << lg;
  vector<Complex> c(n);
  for (int i = (0); i < (a_sz); ++i) c[i].re = a[i];
  for (int i = (0); i < (b_sz); ++i) c[i].im = b[i];
  sub_dft(c);
  int half = n >> 1;
  c[0] = Complex(c[0].re * c[0].im, 0);
  for (int i = (1); i < (half); ++i) {
    Complex i_square = c[i] * c[i], j_square = c[n - i] * c[n - i];
    c[i] = (j_square.conj() - i_square).mul_pin(0.25);
    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);
  }
  c[half] = Complex(c[half].re * c[half].im, 0);
  vector<Real> res = real_idft(c);
  res.resize(sz);
  return res;
}
};  // namespace FFT
int main() {
  const int X = 26;
  vector<int> p(X);
  for (int i = (0); i < (X); ++i) cin >> p[i], --p[i];
  vector<bool> visited(X, false);
  vector<vector<int>> cycle;
  for (int i = (0); i < (X); ++i) {
    if (visited[i]) continue;
    cycle.emplace_back();
    for (int pos = i; !visited[pos]; pos = p[pos]) {
      cycle.back().emplace_back(pos);
      visited[pos] = true;
    }
  }
  vector<char> rough(26);
  vector<FFT::Complex> for_s(26), for_t(26);
  for (int i = (0); i < (cycle.size()); ++i) {
    for (int e : cycle[i]) rough[e] = 'a' + i;
    int k = cycle[i].size();
    for (int j = (0); j < (k); ++j) {
      double a = 2 * M_PI * j / k, b = (1 - 2 * j) * M_PI / k;
      for_s[cycle[i][j]] = FFT::Complex(cos(a), sin(a));
      for_t[cycle[i][j]] = FFT::Complex(cos(b), sin(b));
    }
  }
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  vector<bool> ans(m - n + 1, true);
  string tmp = "";
  for (char c : s) tmp += rough[c - 'a'];
  tmp += '$';
  for (char c : t) tmp += rough[c - 'a'];
  vector<int> z = z_algorithm(tmp);
  for (int i = (0); i < (m - n + 1); ++i) {
    if (z[n + 1 + i] < n) ans[i] = false;
  }
  double ideal = 0;
  for (int i = (0); i < (n); ++i)
    ideal += (for_s[s[i] - 'a'] * for_t[s[i] - 'a']).re;
  reverse((s).begin(), (s).end());
  int lg = 1;
  while ((1 << lg) < n + m - 1) ++lg;
  int x = 1 << lg;
  vector<FFT::Complex> comp_s(x), comp_t(x);
  for (int i = (0); i < (n); ++i) comp_s[i] = for_s[s[i] - 'a'];
  for (int i = (0); i < (m); ++i) comp_t[i] = for_t[t[i] - 'a'];
  FFT::sub_dft(comp_s);
  FFT::sub_dft(comp_t);
  for (int i = (0); i < (x); ++i) comp_s[i] = comp_s[i] * comp_t[i];
  FFT::idft(comp_s);
  for (int i = (0); i < (m - n + 1); ++i) {
    if (abs(comp_s[n - 1 + i].re - ideal) > EPS) ans[i] = false;
  }
  for (int i = (0); i < (m - n + 1); ++i) cout << ans[i];
  cout << '\n';
  return 0;
}

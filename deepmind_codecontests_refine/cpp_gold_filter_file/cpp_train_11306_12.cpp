#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
const double PI = acos(-1);
int n, m, logn;
int rev[N], c[N];
bool a[N], b[N], d[N];
complex<double> fa[N], fb[N];
void fft(complex<double> f[], int invert) {
  for (int i = 0; i < n; ++i) {
    if (i < rev[i]) swap(f[i], f[rev[i]]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double alpha = 2 * PI / len * invert;
    complex<double> v = complex<double>(cos(alpha), sin(alpha));
    for (int i = 0; i < n; i += len) {
      complex<double> w = complex<double>(1);
      for (int j = 0; j < (len >> 1); ++j) {
        complex<double> x = f[i + j], y = f[i + j + (len >> 1)] * w;
        f[i + j] = x + y, f[i + j + (len >> 1)] = x - y, w *= v;
      }
    }
  }
  if (invert == -1) {
    for (int i = 0; i < n; ++i) f[i] /= n;
  }
}
void calRev() {
  for (int i = 0; i < n; ++i) {
    rev[i] = 0;
    for (int j = 0; j < logn; ++j) {
      if (i >> j & 1) rev[i] |= 1 << (logn - 1 - j);
    }
  }
}
void mul() {
  n = 1, logn = 0;
  while (n < m) n <<= 1, logn++;
  n <<= 1, logn++, calRev();
  for (int i = 0; i < n; ++i) fa[i] = complex<double>(a[i]);
  for (int i = 0; i < n; ++i) fb[i] = complex<double>(b[i]);
  fft(fa, 1), fft(fb, 1);
  for (int i = 0; i < n; ++i) fa[i] *= fb[i];
  fft(fa, -1);
  for (int i = 0; i < n; ++i) {
    c[i] = (int)(fa[i].real() + 0.5);
  }
}
void solve() {
  string s;
  cin >> m >> s;
  for (int i = 0; i < m; ++i) {
    if (s[i] == 'V')
      a[i] = 1;
    else if (s[i] == 'K')
      b[m - 1 - i] = 1;
  }
  mul();
  for (int i = 1; i <= m; ++i) d[i] = 0;
  for (int i = 0; i < m; ++i) {
    if (c[i]) d[(m - 1) - i] = 1;
  }
  for (int i = m; i < (m << 1); ++i) {
    if (c[i]) d[i - (m - 1)] = 1;
  }
  vector<int> res;
  for (int i = 1; i <= m; ++i) {
    bool flag = 0;
    for (int j = i; j <= m; j += i) {
      flag |= d[j] != 0;
    }
    if (!flag) res.push_back(i);
  }
  cout << res.size() << '\n';
  for (auto i : res) cout << i << ' ';
  cout << '\n';
  for (int i = 0; i < m; ++i) {
    a[i] = b[i] = 0;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

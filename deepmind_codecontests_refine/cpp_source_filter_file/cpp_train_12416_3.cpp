#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd>& a, bool invert) {
  long long n = a.size();
  for (long long i = 1, j = 0; i < n; i++) {
    long long bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (long long len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (long long i = 0; i < n; i += len) {
      cd w(1);
      for (long long j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (cd& x : a) x /= n;
  }
}
vector<double> multiply(vector<double> const& a, vector<double> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  long long n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (long long i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  vector<double> result(n);
  for (long long i = 0; i < n; i++) result[i] = fa[i].real();
  return result;
}
const long long N = 2e5 + 5;
long long n, x, y, q;
long long solveTestCase() {
  cin >> n >> x >> y;
  vector<double> a(x + 1), b(x + 1);
  for (long long i = 0; i < n + 1; i++) {
    long long temp;
    cin >> temp;
    a[temp] = 1.0;
    b[x - temp] = 1.0;
  }
  vector<double> c = multiply(a, b);
  cin >> q;
  while (q--) {
    long long l, ans = -1;
    cin >> l;
    {
      long long temp = l / 2 - y;
      if (temp > 0 && temp + x < c.size() && c[temp + x] > 1e-4) {
        ans = l;
        goto label;
      }
    }
    for (long long i = 1; i * i <= l; i++) {
      if (l % i) continue;
      long long i_ = l / i;
      if (i_ % 2) continue;
      long long temp = i_ / 2 - y;
      if (temp <= 0) continue;
      if (temp + x < c.size() && c[temp + x] > 1e-9) {
        ans = 2 * (temp + y);
        goto label;
      }
    }
    for (long long i = ceil(sqrt(l)); i >= 1; i--) {
      if (l % i || i % 2) continue;
      long long temp = i / 2 - y;
      if (temp <= 0) continue;
      if (temp + x < c.size() && c[temp + x] > 1e-9) {
        ans = 2 * (temp + y);
        break;
      }
    }
  label:;
    cout << ans << " ";
  }
  return 0;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(12);
  long long t = 1;
  while (t--) solveTestCase();
}

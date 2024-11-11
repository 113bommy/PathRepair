#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  int l = v.size();
  for (int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
const long double PI = 3.1415926535897932384626433832795;
const int N = 1 << 21;
complex<double> root[22];
complex<double> iroot[22];
void init() {
  for (int i = 1; i <= 21; i++) {
    root[i] = complex<double>(cos(2 * PI / (1 << i)), sin(2 * PI / (1 << i)));
    iroot[i] = complex<double>(root[i].real(), -root[i].imag());
  }
}
int rev(int num, int lg_n) {
  int res = 0;
  for (int i = 0; i < lg_n; ++i)
    if (num & (1 << i)) res |= 1 << (lg_n - 1 - i);
  return res;
}
void fft(vector<complex<double> >& a, bool invert) {
  int n = (int)a.size();
  int lg_n = 0;
  while ((1 << lg_n) < n) ++lg_n;
  for (int i = 0; i < n; ++i)
    if (i < rev(i, lg_n)) swap(a[i], a[rev(i, lg_n)]);
  int jj = 1;
  for (int len = 2; len <= n; len <<= 1, jj++) {
    complex<double> wlen = (invert) ? iroot[jj] : root[jj];
    for (int i = 0; i < n; i += len) {
      complex<double> w(1);
      for (int j = 0; j < len / 2; ++j) {
        complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; ++i) a[i] /= n;
}
vector<complex<double> > p1, p2;
int res[N];
void multiply() {
  size_t n = p1.size();
  fft(p1, false), fft(p2, false);
  for (size_t i = 0; i < n; ++i) p1[i] *= p2[i];
  fft(p1, true);
  for (size_t i = 0; i < n; ++i) res[i] = int(p1[i].real() + 0.5);
}
void solve() {
  int n;
  cin >> n;
  int sz = 1;
  while (sz < n) sz <<= 1;
  sz <<= 1;
  p1.clear();
  p2.clear();
  p1.resize(sz);
  p2.resize(sz);
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'V') {
      p1[n + i] = 1;
    } else if (s[i] == 'K') {
      p2[n - 1 - i] = 1;
    }
  }
  multiply();
  vector<bool> bad(n + 1, false);
  for (int i = n; i < sz; i++) {
    if (res[i]) {
      if (i >= 2 * n) {
        bad[i - (2 * n - 1)] = true;
      } else {
        bad[2 * n - 1 - i] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (bad[i]) continue;
    for (int j = 2 * i; j <= n; j += i) {
      if (bad[j]) {
        bad[i] = true;
        break;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (bad[i]) ++cnt;
  cout << n - cnt << endl;
  for (int i = 1; i <= n; i++) {
    if (!bad[i]) cout << i << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

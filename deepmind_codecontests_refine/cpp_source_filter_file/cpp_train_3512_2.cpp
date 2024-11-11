#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << "," << p.second << ')';
}
void fft(vector<complex<double> > &a, bool invert) {
  int n = (int)a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double angle = 2 * PI / len * (invert ? -1 : 1);
    complex<double> w_len(cos(angle), sin(angle)), w(1);
    complex<double> pow[len / 2];
    pow[0] = w;
    for (int i = 1; i < len / 2; ++i) pow[i] = pow[i - 1] * w_len;
    for (int i = 0; i < n; i += len) {
      for (int j = 0; j < len / 2; ++j) {
        complex<double> u = a[i + j], v = a[i + j + len / 2] * pow[j];
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; ++i) a[i] /= n;
}
void multiply(vector<long long> &a, vector<long long> &b,
              vector<long long> &res) {
  int x = max((int)a.size(), (int)b.size());
  int n = 1;
  vector<complex<double> > fa(a.begin(), a.end()), fb(b.begin(), b.end());
  while (n < x) n <<= 1;
  n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; ++i) fa[i] *= fb[i];
  fft(fa, true);
  res.resize(n);
  for (int i = 0; i < n; ++i) {
    res[i] = (long long)(fa[i].real() + 0.5);
  }
}
int _runtimeTerror_() {
  int n, x;
  cin >> n >> x;
  vector<long long> cnt(n + 1, 0);
  vector<long long> y(1, 0);
  int sum = 0, u;
  for (int i = 0; i < n; ++i) {
    cin >> u;
    sum += u < x;
    ++cnt[sum];
    y.push_back(sum);
  }
  long long ans0 = 0, val = 0;
  for (int i = 1; i <= n; ++i) {
    if (y[i] == y[i - 1])
      ans0 += val, ++val;
    else
      val = 1;
  }
  vector<long long> rev = cnt, ans;
  ++rev[0], --rev[sum];
  reverse(rev.begin(), rev.end());
  multiply(cnt, rev, ans);
  cout << ans0 << " ";
  for (int i = 1; i <= n; ++i) {
    cout << ans[n + i] << " ";
  }
  cout << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}

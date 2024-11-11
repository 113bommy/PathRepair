#include <bits/stdc++.h>
using namespace std;
int inf_int = 1e9;
long long inf_ll = 1e17;
const double pi = 3.1415926535898;
const int mod = 1e9 + 7;
const int MAXN = 1e6 + 10;
bool debug = false;
int tail[1 << 22];
int last_tail;
int a[MAXN];
void fft(vector<complex<double> > &a, bool invert) {
  int n = a.size();
  if (last_tail != n) {
    int k = 0;
    while ((1 << k) < n) ++k;
    for (int i = 1; i < n; ++i) {
      tail[i] = ((i & 1) << (k - 1)) | (tail[i >> 1] >> 1);
    }
    last_tail = n;
  }
  for (int i = 0; i < n; ++i) {
    if (i < tail[i]) swap(a[i], a[tail[i]]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double angle = 2 * pi / len * (invert ? -1 : 1);
    complex<double> wlen(cos(angle), sin(angle));
    int len2 = len >> 1;
    for (int i = 0; i < n; i += len) {
      complex<double> w(1);
      for (int j = 0; j < len2; ++j) {
        complex<double> u = a[i + j], v = w * a[i + j + len2];
        a[i + j] = u + v;
        a[i + j + len2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (int i = 0; i < n; ++i) {
      a[i] /= n;
    }
  }
}
void multiply(vector<int> &a, vector<int> &b, vector<int> &res) {
  vector<complex<double> > fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < max(a.size(), b.size())) n <<= 1;
  n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; ++i) {
    fa[i] *= fb[i];
  }
  fft(fa, true);
  res.resize(n);
  for (int i = 0; i < n; ++i) {
    res[i] = fa[i].real() + 0.5;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m + 1);
  for (int i = 1; i <= n; ++i) {
    b[a[i]] = 1;
  }
  vector<int> res;
  multiply(b, b, res);
  vector<int> ans;
  for (int i = 0; i <= m; ++i) {
    if (b[i] == 1 && res[i] == 0) {
      ans.push_back(i);
    }
    if (b[i] == 0 && res[i] >= 1) {
      cout << "NO";
      return;
    }
  }
  cout << "YES\n";
  cout << ans.size() << "\n";
  for (int v : ans) {
    cout << v << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}

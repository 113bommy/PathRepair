#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int inf_int = 1e9 + 100;
const long long inf_ll = 1e18;
const double pi = 3.1415926535898;
bool debug = 0;
const int MAXN = 1e6 + 100;
const int LOG = 25;
const int mod = 1e9 + 7;
const int MX = 2e6 + 100;
const long long MOD = 1000000000949747713ll;
namespace FFT {
struct base {
  double re, im;
  base() { re = im = 0; }
  base(double x, double y) {
    re = x;
    im = y;
  }
};
inline base conj(const base &a) { return base(a.re, -a.im); }
inline base operator+(const base &a, const base &b) {
  return base(a.re + b.re, a.im + b.im);
}
inline base operator-(const base &a, const base &b) {
  return base(a.re - b.re, a.im - b.im);
}
inline base operator*(const base &a, const base &b) {
  return base(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
}
int tail[1 << 21];
int last_tail = 0;
base fa[1 << 21], fb[1 << 21];
base ww[1 << 21];
void fft(base a[], int n, bool invert) {
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
  ww[0] = {1, 0};
  for (int len = 2; len <= n; len <<= 1) {
    double angle = 2 * pi / len * (invert ? -1 : 1);
    base wlen(cos(angle), sin(angle));
    int len2 = len >> 1;
    for (int i = 1; i < len2; ++i) ww[i] = ww[i - 1] * wlen;
    for (int i = 0; i < n; i = i + len) {
      for (int j = 0; j < len2; ++j) {
        base u = a[i + j], v = ww[j] * a[i + j + len2];
        a[i + j] = u + v;
        a[i + j + len2] = u - v;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; ++i) {
      a[i].re /= n;
      a[i].im /= n;
    }
}
void multiply(vector<int> &a, vector<int> &b, vector<int> &res) {
  int n = 1;
  while (n < max(a.size(), b.size())) n <<= 1;
  n <<= 1;
  for (int i = 0; i < n; ++i) fa[i] = fb[i] = {0, 0};
  for (int i = 0; i < a.size(); ++i) fa[i] = {double(a[i]), 0};
  for (int i = 0; i < b.size(); ++i) fb[i] = {double(b[i]), 0};
  fft(fa, n, false);
  fft(fb, n, false);
  for (int i = 0; i < n; ++i) {
    fa[i] = fa[i] * fb[i];
  }
  fft(fa, n, true);
  res.resize(n);
  for (int i = 0; i < n; ++i) {
    res[i] = fa[i].re + 0.1;
  }
}
}  // namespace FFT
int a[MAXN];
int cnt[1 << 12];
string s;
int val[1 << 12];
int cnt_pairs[MX];
int w;
int ans = 0;
int P[100];
vector<int> c[500];
void dfs(int i, int val = 0) {
  if (i == w) {
    ans += cnt_pairs[val];
    return;
  }
  for (int x : c[s[i]]) {
    dfs(i + 1, val + P[i] * x);
  }
}
void solve() {
  P[0] = 1;
  for (int i = 1; i < 20; ++i) {
    P[i] = P[i - 1] * 3;
  }
  c['A'].push_back(0);
  c['A'].push_back(1);
  c['O'].push_back(0);
  c['X'].push_back(0);
  c['X'].push_back(2);
  c['a'].push_back(2);
  c['o'].push_back(1);
  c['o'].push_back(2);
  c['x'].push_back(1);
  int n, m;
  cin >> w >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 0; i < (1 << w); ++i) {
    int x = i;
    int k = 1;
    for (int e = 0; e < w; ++e) {
      if (x & (1 << e)) {
        val[i] += k;
      }
      k = k * 3;
    }
  }
  int mx = 0;
  for (int i = 0; i < (1 << w); ++i) {
    if (cnt[i]) {
      mx = max(mx, val[i]);
    }
  }
  vector<int> a(mx + 1, 0);
  for (int i = 0; i < (1 << w); ++i) {
    if (cnt[i]) {
      a[val[i]] = cnt[i];
    }
  }
  vector<int> res;
  FFT::multiply(a, a, res);
  for (int i = 0; i < (int(res.size())); ++i) {
    cnt_pairs[i] = res[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> s;
    reverse(s.begin(), s.end());
    ans = 0;
    dfs(0);
    cout << ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  int t = 1;
  while (t--) solve();
  if (debug)
    cerr << endl << "time : " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}

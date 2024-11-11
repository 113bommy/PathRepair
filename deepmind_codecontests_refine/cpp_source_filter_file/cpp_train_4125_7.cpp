#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
const long long N = 107;
long long test;
long long n, l, mod;
long long a[N], b[N], c[N], res[N], e[N];
struct mat {
  long long t[N][N];
  mat() { memset(t, 0, sizeof t); }
} base;
mat operator*(mat a, mat b) {
  mat cc;
  for (long long i = 0; i < (mod); ++i) {
    for (long long j = 0; j < (mod); ++j) {
      for (long long k = 0; k < (mod); ++k) {
        cc.t[i][j] += a.t[i][k] * b.t[k][j];
        cc.t[i][j] %= 1000000007;
      }
    }
  }
  return cc;
}
mat pot(mat a, long long x) {
  mat res;
  for (long long i = 0; i < (mod); ++i) {
    res.t[i][i] = 1;
  }
  for (long long i = 0; i < (30); ++i) {
    if ((1 << i) & x) res = res * a;
    a = a * a;
  }
  return res;
}
void solve() {
  cin >> n >> l >> mod;
  for (long long i = 1; i <= (n); ++i) {
    long long x;
    cin >> x;
    a[x]++;
  }
  for (long long i = 1; i <= (n); ++i) {
    long long x;
    cin >> x;
    e[i] = x;
    for (long long j = 0; j < (mod); ++j) {
      base.t[(x + j) % mod][j]++;
    }
  }
  mat d = pot(base, l - 2);
  for (long long i = 0; i < (mod); ++i) {
    for (long long j = 0; j < (mod); ++j) {
      b[i] += a[j] * d.t[i][j];
      b[i] %= 1000000007;
    }
  }
  for (long long i = 1; i <= (n); ++i) {
    long long x;
    cin >> x;
    c[(x + e[i]) % mod]++;
  }
  for (long long i = 0; i < (mod); ++i) {
    for (long long j = 0; j < (mod); ++j) {
      res[(i + j) % mod] += b[i] * c[j];
      res[(i + j) % mod] %= 1000000007;
    }
  }
  cout << res[0];
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  test = 1;
  for (long long i = 1; i <= test; i++) {
    solve();
  }
  return 0;
}

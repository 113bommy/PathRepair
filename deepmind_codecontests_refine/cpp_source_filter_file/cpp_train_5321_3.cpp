#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() { return abs((int)mt()); }
const int maxn = 100 + 5;
int n;
long double c, t;
int a[maxn];
int p[maxn];
long double f[maxn];
int ff() {
  static long double dp[2][maxn][maxn * 10];
  int pv = 0, nx = 1;
  dp[pv][0][0] = 0;
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (i + 2); ++j)
      for (int k = (0); k < ((i + 1) * 10 + 1); ++k) {
        dp[nx][j][k] = 1e18;
      }
    for (int j = (0); j < (i + 1); ++j)
      for (int k = (0); k < (i * 10 + 1); ++k) {
        chkmin(dp[nx][j][k], dp[pv][j][k]);
        chkmin(dp[nx][j + 1][k + p[i]], dp[pv][j][k] + a[i] / f[j + 1]);
      }
    swap(pv, nx);
  }
  for (int k = (n * 10 + 1) - 1; k >= (0); --k)
    for (int j = (0); j < (n + 1); ++j) {
      long double a = dp[pv][j][k];
      long double b = t - 10 * j;
      if (b >= 0) {
        long double x = 0.0;
        if (a * c > 1) {
          x = (sqrt(a * c) - 1) / c;
        }
        if (sign(x + a / (c * x + 1), b) <= 0) {
          return k;
        }
      }
    }
}
void chemthan() {
  f[0] = 1;
  for (int i = (1); i < (maxn); ++i) f[i] = f[i - 1] * 0.9;
  int test;
  cin >> test;
  while (test--) {
    cin >> n >> c >> t;
    vector<pair<int, int> > vals;
    for (int i = (0); i < (n); ++i)
      cin >> a[i] >> p[i], vals.push_back(make_pair(a[i], p[i]));
    sort((vals).begin(), (vals).end());
    for (int i = (0); i < (n); ++i) a[i] = vals[i].first, p[i] = vals[i].second;
    cout << ff() << "\n";
  }
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}

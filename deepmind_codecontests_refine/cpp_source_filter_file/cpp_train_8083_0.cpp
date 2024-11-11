#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int FFTMOD = 1007681537;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
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
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
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
const int maxn = 1e5 + 5;
int n;
int a[maxn];
int st[4][maxn << 1];
void upd(int st[], int p, int val) {
  for (st[p += maxn] = val; p > 1;)
    p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]);
}
int query(int st[], int l, int r) {
  int res = INF;
  for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) chkmin(res, st[l]);
    if (r & 1) chkmin(res, st[r]);
  }
  return res;
}
void chemthan() {
  cin >> n;
  for (int i = (1); i < (n + 1); ++i) {
    cin >> a[i];
    upd(st[0], i, a[i] - (i - 1) - i);
    upd(st[1], i, a[i] - (i - 1) + i);
    upd(st[2], i, a[i] - i);
    upd(st[3], i, a[i] + i);
  }
  int ans = INF;
  for (int k = (2); k < (n + 1); ++k) {
    int lo = 2, hi = n + 1;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      int mn = INF;
      chkmin(mn, query(st[0], 1, min(mi, k)) + k);
      chkmin(mn, query(st[1], k, mi) - k);
      if (mn > 0) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    int mi = lo + hi >> 1;
    if (mi <= n) {
      int mn1 = INF;
      chkmin(mn1, query(st[2], 1, min(mi - 1, k)) + k);
      chkmin(mn1, query(st[3], k, mi - 1) - k);
      int mn2 = INF;
      chkmin(mn2, query(st[2], mi, k) + k);
      chkmin(mn2, query(st[3], max(mi, k), n) - k);
      chkmin(ans, max(mn1, mn2));
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << "\n";
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

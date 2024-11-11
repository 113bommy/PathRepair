#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void umin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <class T>
inline T gcd(T a, T b) {
  return __gcd(a, b);
}
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long modpow(long long a, long long n, long long temp) {
  long long res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
long long ison(long long mask, long long pos) { return (mask & (1 << pos)); }
long long cbit(long long n) {
  long long k = 0;
  while (n) n &= (n - 1), k++;
  return k;
}
long long nbit(long long n) {
  long long k = 0;
  while (n) n /= 2, k++;
  return k;
}
long long mod = 1e9 + 7;
int sgn(long long x) { return x < 0 ? -1 : !!x; }
const double eps = 1e-7;
const double pi = acos(-1.0);
inline void inc(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void dec(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
inline void chmax(long long &x, long long y) {
  if (y > x) x = y;
}
inline void mulm(long long &x, long long y) {
  x *= y;
  if (x >= mod) x -= mod;
}
long long xo(long long i) {
  if ((i & 3) == 0) return i;
  if ((i & 3) == 1) return 1;
  if ((i & 3) == 2) return i + 1;
  return 0;
}
pair<long long, long long> a[100005];
int main() {
  long long p, x, t, k, n, m, i, j, l;
  long long pl = 0, pr = 0;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  for (i = 1; i <= n; i++) pl += a[i].first, pr += a[i].second;
  long long z = abs(pl - pr);
  long long ans = 0, pv = z;
  for (i = 1; i <= n; i++) {
    long long nl = pl - a[i].first + a[i].second;
    long long nr = pr - a[i].second + a[i].first;
    if (abs(nl - nr) > pv) ans = i, pv = (abs(nl - nr));
  }
  cout << ans;
}

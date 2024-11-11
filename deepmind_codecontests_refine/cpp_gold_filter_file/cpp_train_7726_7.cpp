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
long long getbit(long long j, long long i) { return ((i >> (j - 1ll)) & 1ll); }
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
const double eps = 6 * 1e-8;
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
vector<long long> num;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    map<long long, long long> help;
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= m; i++) {
      long long j;
      cin >> j;
      help[j]++;
    }
    long long ans = 0;
    long long f = 1;
    for (long long i = 0; i <= 60; i++) {
      if (n & (1ll << i)) {
        if (help[(1ll << i)] == 0) {
          long long req = 1ll << i;
          for (long long j = i - 1; j >= 0; j--) {
            long long p = help[1ll << j];
            long long u = min(req, p * (1ll << j));
            req -= u;
            help[1ll << j] -= u / (1ll << j);
          }
          if (req > 0) {
            for (long long j = i + 1; j <= 60; j++) {
              if (help[(1ll << j)]) {
                ans += (j - i);
                req = 0;
                help[1ll << j]--;
                long long x = (1ll << (j - i));
                help[(1ll << i)] += (x - 1ll);
                break;
              }
            }
          }
          if (req) f = 0;
        } else
          help[1ll << i]--;
      }
    }
    if (f)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
}

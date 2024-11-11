#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a, long long b, long long p) {
  long long ret = 1;
  for (a %= p; b; b >>= 1, a = a * a % p)
    if (b & 1) ret = ret * a % p;
  return ret;
}
long long qpow(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, a *= a)
    if (b & 1) ret *= a;
  return ret;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
pair<long long, long long> exgcd(long long a, long long b) {
  if (!b) return {1, 0};
  pair<long long, long long> ret = exgcd(b, a % b);
  return {ret.second, ret.first - a / b * ret.second};
}
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
signed main() {
  long long _;
  cin >> _;
  for (; _--;) {
    long long n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 || y1 == y2) {
      cout << 0 << '\n';
    } else if (x1 < x2) {
      if (y1 < y2) {
        cout << min(x2 - x1, y2 - y1) << '\n';
      } else {
        cout << min(x2 - x1, 2 * n - y2 - y1) << '\n';
      }
    } else {
      if (y1 < y2) {
        cout << min(2 * m - x1 - x2, y2 - y1) << '\n';
      } else {
        cout << min(2 * m - x1 - x2, 2 * n - y2 - y1) << '\n';
      }
    }
  }
}

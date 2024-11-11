#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
long double pi = 3.1415926535897932384626433832795;
long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long _gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long _x1, _y1;
  long long d = _gcd(b % a, a, _x1, _y1);
  x = _y1 - (b / a) * _x1;
  y = _x1;
  return d;
}
long double binpow(long double a, long long n) {
  long double res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
const int N = 3e5 + 10;
long long a[N], b[N], sa = 0, sb = 0;
long long n, p;
bool ok(long double t) {
  long double have = t * p;
  long double need = 0;
  for (int i = 0; i < n; i++) {
    need += max((long double)0, a[i] * t - b[i]);
  }
  return need <= have;
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sa += a[i];
    sb += b[i];
  }
  if (p >= sa) {
    cout << -1;
  } else {
    long double l = 0, r = 1e18;
    for (int ii = 0; ii < 200; ii++) {
      long double mid = (l + r) / 2;
      if (ok(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%.9lf", l);
  }
  return 0;
}

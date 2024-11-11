#include <bits/stdc++.h>
void e_gcd(long long a, long long b, long long &d, long long &x, long long &y) {
  long long tmp;
  if (b == 0) {
    x = 1;
    y = 0;
    d = a;
    return;
  }
  e_gcd(b, a % b, d, x, y);
  tmp = x;
  x = y;
  y = tmp - (a / b) * y;
}
int main() {
  long long n, m, x, y, vx, vy, rex, rey, _a, _b, a, b, d, t, _n, _m, ansx,
      ansy;
  scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &n, &m, &x, &y, &vx, &vy);
  if (vx == 0LL) {
    if (x == 0LL || x == n) {
      if (vy == 1LL) {
        printf("%I64d %I64d\n", x, m);
      } else {
        printf("%I64d %I64d\n", x, 0LL);
      }
      return 0;
    } else {
      printf("-1\n");
      return 0;
    }
  }
  if (vy == 0LL) {
    if (y == 0LL || y == m) {
      if (vx == 1LL) {
        printf("%I64d %I64d\n", n, y);
      } else {
        printf("%I64d %I64d\n", 0LL, y);
      }
      return 0;
    } else {
      printf("-1\n");
      return 0;
    }
  }
  rex = 0;
  rey = 0;
  if (vx == -1) {
    rex = 1;
    x = n - x;
  }
  if (vy == -1) {
    rey = 1;
    y = m - y;
  }
  e_gcd(n, m, d, a, b);
  if ((x - y) % d) {
    printf("-1\n");
    return 0;
  }
  t = (x - y) / d;
  a *= t;
  b *= t;
  _m = m / d;
  _n = n / d;
  _a = (a % _m + _m + _m - 1) % _m + 1;
  _b = -((x - y) - _a * n) / m;
  ansx = n;
  ansy = m;
  if (_a % 2 == 0) {
    ansx = n - ansx;
  }
  if (_b % 2 == 0) {
    ansy = m - ansy;
  }
  if (rex == 1) {
    ansx = n - ansx;
  }
  if (rey == 1) {
    ansy = m - ansy;
  }
  printf("%I64d %I64d\n", ansx, ansy);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long down(long long a, long long b) {
  if (a >= 0) return a / b;
  return (a % b == 0) ? a / b : a / b - 1;
}
long long up(long long a, long long b) {
  if (a >= 0) return (a + b - 1) / b;
  return a / b;
}
long long gcdmax(long long a, long long b, long long c, long long &x,
                 long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcdmax(b % a, a, c, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
int32_t main() {
  long long a1, b1, a2, b2, l, r;
  cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
  long long x0, y0;
  long long d = gcd(a1, a2);
  if ((b2 - b1) % d != 0) {
    cout << 0 << endl;
    return 0;
  }
  d = gcdmax(a1, a2, d, x0, y0);
  if (b2 < b1) {
    x0 *= -1;
    y0 *= -1;
  }
  y0 *= -1;
  x0 *= abs(b2 - b1) / d;
  y0 *= abs(b2 - b1) / d;
  long long n = min(down(x0 * d, a2), down(y0 * d, a1));
  x0 -= (a2 * n) / d;
  y0 -= (a1 * n) / d;
  n = 0;
  long long l1 = up(a1 * x0 + b1 - r, a1 * (a2 / d));
  long long r1 = down(a1 * x0 + b1 - l, a1 * (a2 / d));
  if (n < l1) {
    cout << 0 << endl;
  } else if (n > r1) {
    cout << r1 - l1 + 1 << endl;
  } else {
    cout << n - l1 + 1 << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (x % y == 0)
    return y;
  else
    return gcd(y, x % y);
}
int main() {
  int n, m, x, y, a, b;
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
  int t = gcd(a, b);
  a /= t;
  b /= t;
  t = min(n / a, m / b);
  a *= t;
  b *= t;
  int x1, x2, y1, y2;
  x1 = x - a / 2;
  x2 = x + a / 2;
  if (a % 2 == 1) x1--;
  y1 = y - b / 2;
  y2 = y + b / 2;
  if (b % 2 == 1) x1--;
  if (x1 < 0) {
    x2 += (0 - x1);
    x1 = 0;
  }
  if (x2 > n) {
    x1 -= (x2 - n);
    x2 = n;
  }
  if (y1 < 0) {
    y2 += (0 - y1);
    y1 = 0;
  }
  if (y2 > m) {
    y1 -= (y2 - m);
    y2 = m;
  }
  printf("%d %d %d %d", x1, y1, x2, y2);
  return 0;
}

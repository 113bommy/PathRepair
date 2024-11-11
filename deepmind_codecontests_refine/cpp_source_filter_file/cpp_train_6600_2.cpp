#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y == 0) return 1;
  while (x % y != 0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return y;
}
int main() {
  int a, b, c, d, x, y, x1, y1, x2, y2, g;
  cin >> a >> b >> c >> d;
  x1 = abs((b * c) - (d * a));
  y1 = c * b;
  x2 = abs((a * d) - c * b);
  y2 = d * a;
  if (x1 > y1)
    g = gcd(x1, y1);
  else
    g = gcd(y1, x1);
  x1 = x1 / g;
  y1 = y1 / g;
  if (x2 > y2)
    g = gcd(x2, y2);
  else
    g = gcd(y2, x2);
  x2 = x2 / g;
  y2 = y2 / g;
  if ((float)x1 / y1 < (float)x2 / y2) {
    x = x1;
    y = y1;
  } else {
    x = x2;
    y = y2;
  }
  if (x != 0)
    cout << x << "/" << y;
  else
    cout << 0 << "/" << y;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a, b;
int GCD(int x, int y) {
  while (y) {
    register int r = x % y;
    x = y, y = r;
  }
  return x;
}
int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
  int d = GCD(a, b);
  a /= d, b /= d;
  int k, x1, y1, x2, y2, w, h;
  k = min(n / a, m / b);
  w = a * k, h = b * k;
  x1 = x - (w + 1) / 2, x2 = x + w / 2;
  y1 = y - (h + 1) / 2, y2 = y + h / 2;
  if (x1 < 0) {
    int t = -x1;
    x1 += t, x2 += t;
  }
  if (y1 < 0) {
    int t = -y1;
    y1 += t, y2 += t;
  }
  if (x2 > n) {
    int t = x2 - n;
    x1 -= t, x2 -= t;
  }
  if (y2 > m) {
    int t = y2 - m;
    y1 -= t, y2 -= t;
  }
  printf("%d %d %d %d", x1, y1, x2, y2);
  return 0;
}

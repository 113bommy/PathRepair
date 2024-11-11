#include <bits/stdc++.h>
using namespace std;
const char fi[] = "vd.inp";
const char fo[] = "vd.out";
long n, m, x, y, a, b;
long u, v;
long xa, ya, xb, yb;
long ucln(long a, long b) {
  long r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return (b);
}
int main() {
  scanf("%ld%ld%ld%ld%ld%ld", &n, &m, &x, &y, &a, &b);
  long tg = ucln(a, b);
  a /= tg;
  b /= tg;
  tg = min(n / a, m / b);
  u = tg * a;
  v = tg * b;
  if (u % 2 == 0)
    xa = x - u / 2;
  else
    xa = x - u / 2 - 1;
  xb = xa + u;
  if (xa < 0) {
    xa = 0;
    xb = xa + u;
  }
  if (xb > n) {
    xb = n;
    xa = xb - u;
  }
  if (v % 2 == 0)
    ya = y - v / 2;
  else
    ya = y - v / 2 - 1;
  yb = ya + v;
  if (ya < 0) {
    ya = 0;
    yb = ya + v;
  }
  if (yb > m) {
    yb = n;
    ya = yb - v;
  }
  printf("%ld %ld %ld %ld", xa, ya, xb, yb);
}

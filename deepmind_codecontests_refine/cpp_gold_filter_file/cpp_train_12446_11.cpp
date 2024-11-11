#include <bits/stdc++.h>
long long x, y;
long long gcd(long long a, long long b) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long t1 = gcd(b, a % b);
  long long t2 = x;
  x = y;
  y = t2 - a / b * y;
  return t1;
}
int main() {
  long long a1, b1, a2, b2, l, r, g, t;
  double dl, dr;
  scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &a1, &b1, &a2, &b2, &l, &r);
  g = gcd(a1, a2);
  if ((b2 - b1) % g != 0) {
    printf("0\n");
    return 0;
  }
  x *= (b2 - b1) / g;
  y *= (b2 - b1) / g;
  t = ceil((double)g * (-x) / a2);
  x += a2 / g * t;
  y -= a1 / g * t;
  if (y > 0) {
    t = floor((double)g * (-y) / a1);
    x -= a2 / g * t;
    y += a1 / g * t;
  }
  dl = ((double)(l - b1) / a1 - x) * (double)g / a2;
  dr = ((double)(r - b1) / a1 - x) * (double)g / a2;
  dl = (dl - 0 > 1e-20 ? dl : 0);
  long long ans = floor(dr) - ceil(dl) + 1;
  if (dr < 0) {
    printf("0\n");
    return 0;
  }
  printf("%I64d\n", ans);
}

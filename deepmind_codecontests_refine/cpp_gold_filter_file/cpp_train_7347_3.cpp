#include <bits/stdc++.h>
using ll = long long;
std::pair<ll, ll> Euclid(int a, int b) {
  ll x1 = 0, x2 = 1, y1 = 1, y2 = 0, q = a / b, r = a - q * b, x, y, wynn;
  x = 1, y = y2 - (q - 1) * y1;
  while (r != 0) {
    a = b, b = r;
    x = x2 - q * x1, x2 = x1, x1 = x;
    y = y2 - q * y1, y2 = y1, y1 = y;
    wynn = r, q = a / b, r = a - q * b;
  }
  return std::make_pair(x, y);
}
int main() {
  ll a, h, w, v1, v2, b, c, d, s1, s2, gcd, stable;
  std::pair<ll, ll> eucl;
  scanf("%lld %lld %lld", &a, &h, &w);
  c = w + a;
  b = w - h;
  d = h + a;
  eucl = Euclid(c, d);
  gcd = c * eucl.first + d * eucl.second;
  if (b % gcd != 0) {
    printf("-1\n");
    return 0;
  }
  b /= gcd, c /= gcd, d /= gcd;
  v1 = eucl.first * (-b);
  v1 = v1 % d;
  if (v1 <= 0) v1 += d;
  v2 = (c * v1 + b) / d;
  if (h - a * v1 < 0 || w - a * v2 < 0) {
    printf("-1\n");
    return 0;
  }
  s1 = (h - a * v1) / (a * d);
  s2 = (w - a * v2) / (a * c);
  stable = (((s1) < (s2)) ? (s1) : (s2));
  v1 = v1 + stable * d;
  v2 = v2 + stable * c;
  printf("%lf\n", 1.0f * (w - a * v2) / (v2 + 1));
  return 0;
}

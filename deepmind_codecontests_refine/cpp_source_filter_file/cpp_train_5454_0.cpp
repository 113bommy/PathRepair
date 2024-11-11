#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int calc(int n, int x, int a) {
  int res = 0;
  n *= 2;
  x *= 2;
  if (x < a)
    res = 0;
  else if (x + a > n)
    res = n / 2 - a;
  else
    res = (x - a) / 2;
  return res;
}
int main() {
  int n, m, x, y, a, b, t;
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
  t = gcd(a, b);
  a /= t;
  b /= t;
  t = min(n / a, m / b);
  a *= t;
  b *= t;
  int X = calc(n, x, a), Y = calc(m, y, b);
  printf("%d %d %d %d\n", X, Y, X + a, Y + b);
  return 0;
}

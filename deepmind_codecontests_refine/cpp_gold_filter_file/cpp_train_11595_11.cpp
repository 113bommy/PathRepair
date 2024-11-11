#include <bits/stdc++.h>
using namespace std;
long long mo;
long long mul(long long x, long long y, long long z) {
  x %= z;
  y %= z;
  return (x * y - (long long)(x / (long double)z * y + 1e-3) * z + z) % z;
}
long long sqrsum(long long n) {
  if (n & 1)
    return mul(mul((n - 1) >> 1, n + 1, mo) + 1, mul(n, n, mo), mo);
  else
    return mul(mul(n, n, mo) + 1, mul(n, n >> 1, mo), mo);
}
long long lsum(long long n) {
  if (n & 1)
    return mul((n - 1) >> 1, n, mo);
  else
    return mul(n >> 1, n - 1, mo);
}
long long com3(long long n) {
  if (n < 3) return 0;
  long long a = n, b = n - 1, c = n - 2;
  if (a % 3 == 0)
    a /= 3;
  else if (b % 3 == 0)
    b /= 3;
  else
    c /= 3;
  if (a % 2 == 0)
    a /= 2;
  else if (b % 2 == 0)
    b /= 2;
  else
    c /= 2;
  return mul(mul(a, b, mo), c, mo);
}
long long work(int x, int y) {
  if (!x || !y) return 0;
  long long sum = 0, t, k, n;
  if (x < y) {
    t = y - x;
    k = (mul(x + 1, x + 1, mo) - mul(x, x, mo)) % mo;
    n = mul(x, x, mo) + 1;
    sum = (mul(t, n, mo) + mul(k, lsum(t), mo) + 2LL * com3(t)) % mo;
    if (x & 1)
      sum = mul(sum + mul(((x - 1) >> 1), t, mo), x, mo);
    else
      sum = mul(2LL * sum + mul(t, x - 1, mo), x >> 1, mo);
    return (sum + sqrsum(x)) % mo;
  } else {
    t = x - y;
    k = (mul(y + 2, y + 2, mo) - mul(y + 1, y + 1, mo)) % mo;
    n = mul(y + 1, y + 1, mo);
    sum = (mul(t, n, mo) + mul(k, lsum(t), mo) + 2LL * com3(t)) % mo;
    if (y & 1)
      sum = mul(sum + mul(((1 - y) >> 1), t, mo), y, mo);
    else
      sum = mul(2LL * sum + mul(1 - y, t, mo), y >> 1, mo);
    return (sum + sqrsum(y)) % mo;
  }
}
long long solve(int x1, int y1, int x2, int y2) {
  return ((work(x2, y2) - work(x2, y1 - 1) - work(x1 - 1, y2) +
           work(x1 - 1, y1 - 1)) %
              mo +
          mo) %
         mo;
}
int main() {
  int tc, x1, y1, x2, y2;
  long long an, bn;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    mo = 10000000000LL;
    an = solve(x1, y1, x2, y2);
    mo = 19739184197LL;
    bn = solve(x1, y1, x2, y2);
    if (an != bn)
      printf("...%010I64d\n", an);
    else
      printf("%I64d\n", an);
  }
  return 0;
}

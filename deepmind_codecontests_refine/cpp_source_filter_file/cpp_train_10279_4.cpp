#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int modu = (1 << 30);
const int maxn = 1000000 + 5;
long long n, m, x, y;
int vx, vy;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long tx, ty;
  long long g = exgcd(b, a % b, tx, ty);
  x = ty;
  y = tx - a / b * ty;
  return g;
}
int main() {
  cin >> n >> m >> x >> y >> vx >> vy;
  if (vx == 0) {
    if (x != n && x != 0)
      puts("-1");
    else {
      if (vy == 1)
        printf("%lld %lld\n", x, m);
      else
        printf("%lld 0\n", x);
    }
    return 0;
  }
  if (vy == 0) {
    if (y != n && y != 0)
      puts("-1");
    else {
      if (vx == 1)
        printf("%lld %lld\n", n, y);
      else
        printf("0 %lld\n", y);
    }
    return 0;
  }
  if (vx == -1) x = n - x;
  if (vy == -1) y = m - y;
  long long a = n, b = m, c = x - y;
  long long k1, k2;
  long long g = exgcd(a, b, k1, k2);
  bool flag = false;
  if (c == 0) {
    k1 = b / g;
    k2 = a / g;
  } else {
    if (c % g)
      flag = true;
    else {
      a /= g;
      b /= g;
      k1 *= c / g;
      k2 *= c / g;
      if (k1 < 0) {
        long long tmp = (-k1) / b + 1;
        k1 += tmp * b;
        k2 -= tmp * a;
      }
      if (k2 > 0) {
        long long tmp = k2 / a + 1;
        k1 += tmp * b;
        k2 -= tmp * a;
      }
      long long tmp = min(k1 / b, k2 / a);
      k1 -= tmp * b;
      k2 -= tmp * a;
    }
  }
  if (flag)
    puts("-1");
  else
    printf("%lld %lld\n", ((k1 & 1) ^ (vx == -1)) * n,
           ((k2 & 1) ^ (vy == -1)) * m);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, vx, vy;
long long exgcd(long long a, long long b, long long &x1, long long &y1) {
  if (!b) {
    x1 = 1, y1 = 0;
    return a;
  }
  long long k = exgcd(b, a % b, x1, y1);
  long long tmp = x1;
  x1 = y1;
  y1 = tmp - a / b * y1;
  return k;
}
signed main() {
  scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &x, &y, &vx, &vy);
  if (vx == 0) {
    if (x == 0 || x == n) {
      if (vy > 0)
        printf("%lld %lld\n", x, m);
      else
        printf("%lld 0\n", x);
    } else
      printf("-1\n");
    return 0;
  }
  if (vy == 0) {
    if (y == 0 || y == m) {
      if (vx > 0)
        printf("%lld %lld\n", n, y);
      else
        printf("0 %lld\n", y);
    } else
      printf("-1\n");
    return 0;
  }
  long long f_x = 0, f_y = 0;
  if (vx == -1) f_x = 1, x = n - x;
  if (vy == -1) f_y = 1, y = m - y;
  long long a, b, gcd, ans_x = n, ans_y = m;
  gcd = exgcd(n, m, a, b);
  if ((x - y) % gcd) {
    printf("-1\n");
    return 0;
  }
  a *= (x - y) / gcd, b *= (x - y) / gcd;
  long long n_step = n / gcd, m_step = m / gcd;
  long long nw_a = (a % m_step + m_step - 1) % m_step + 1;
  long long nw_b = -((x - y) - nw_a * n) / m;
  if (nw_a % 2 == 0) ans_x = n - ans_x;
  if (f_x) ans_x = n - ans_x;
  if (nw_b % 2 == 0) ans_y = m - ans_y;
  if (f_y) ans_y = m - ans_y;
  printf("%lld %lld\n", ans_x, ans_y);
}

#include <bits/stdc++.h>
using namespace std;
int k, m;
long long exgcd(long long x, long long y, long long& a, long long& b,
                long long d) {
  if (x == 0) {
    a = 0, b = d / y;
    return y;
  }
  long long dd = exgcd(y % x, x, b, a, d);
  if (d % dd) return dd;
  a -= b * (y / x);
  long long xx = x / dd, yy = y / dd;
  if (a < 0) {
    long long t = -a / yy + 1;
    a += t * yy;
    b -= t * xx;
  }
  long long t = a / yy;
  a -= t * yy;
  b += t * xx;
  return dd;
}
int main() {
  scanf("%d", &k);
  for (m = 1; m < 2000; m++) {
    long long a, b;
    exgcd(m, m + 1, a, b, k);
    b = -b;
    if (a <= b) {
      long long t = b - a + 1;
      a += t * (m + 1);
      b += t * m;
    }
    if (b <= 0) {
      long long t = -b / m + 1;
      b += t * m;
      a += t * (m + 1);
    }
    if (a > 1000000) continue;
    printf("%d\n", m + 1);
    for (int i = 1; i < m; i++) printf("0 ");
    printf("%I64d ", -b);
    printf("%I64d\n", a);
    return 0;
  }
  printf("-1\n");
  return 0;
}

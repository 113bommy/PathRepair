#include <bits/stdc++.h>
using namespace std;
int exgcd(long long a, long long b, long long &x, long long &y) {
  long long d, tmp;
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  };
  d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
int main() {
  long long a, b, c, x, y, d;
  scanf("%lld%lld%lld", &a, &b, &c);
  c = -c;
  d = exgcd(a, b, x, y);
  if (c % d != 0)
    printf("-1");
  else {
    a = a / d;
    b = b / d;
    c = c / d;
    x = 0, y = 0;
    long long dd = exgcd(a, b, x, y);
    printf("%lld %lld", x * c, y * c);
  }
}

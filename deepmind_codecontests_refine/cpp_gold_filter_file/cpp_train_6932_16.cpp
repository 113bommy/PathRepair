#include <bits/stdc++.h>
using namespace std;
long long a, b, c, x, y, d;
int exgcd(int a, int b) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
int main() {
  scanf("%lld%lld%lld", &a, &b, &c);
  c = -c;
  int d = exgcd(a, b);
  if (c % d) {
    printf("-1\n");
    return 0;
  }
  x = c / d * x;
  y = c / d * y;
  printf("%lld %lld\n", x, y);
  return 0;
}

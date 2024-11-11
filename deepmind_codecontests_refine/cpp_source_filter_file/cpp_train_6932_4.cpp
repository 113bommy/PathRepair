#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, x, y), t;
  t = x;
  x = y;
  y = t - (a / b) * y;
  return g;
}
int main() {
  long long a, b, c, x, y;
  cin >> a >> b >> c;
  long long t = exgcd(a, b, x, y);
  if (c % t == 0)
    printf("%lld %lld\n", x * c / t, y * c / t);
  else
    puts("-1");
}

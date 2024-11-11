#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  while (y) {
    long long g = x % y;
    x = y;
    y = g;
  }
  return x;
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long x;
    scanf("%lld", &x);
    long long g = 1;
    long long ans = -1;
    while (g < x) {
      if ((g & x) == 0) ans = g;
      g <<= 1;
    }
    if (ans == -1) {
      ans = 1;
      for (long long i = 2; i * i <= x; i++)
        if (x % i == 0) {
          ans = x / i;
          break;
        }
      printf("%lld\n", ans);
    } else
      printf("%lld\n", (ans | x));
  }
  return 0;
}

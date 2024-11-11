#include <bits/stdc++.h>
using namespace std;
long long a, b, c, sq, ans = LLONG_MAX, ansk;
int main() {
  scanf("%lld%lld", &a, &b);
  if (a == b) {
    printf("%lld", a);
    return 0;
  }
  c = abs(b - a);
  sq = sqrt(c);
  for (long long i = 1; i <= sq; i++) {
    if (c % i == 0) {
      long long i2 = i, k = 0, t = 0;
      if (a % i2 > 0) k += i2 - (a % i2);
      t = (a + k) * (b + k) / i2;
      if (t == ans) {
        ansk = min(ansk, k);
      }
      if (t < ans) {
        ans = t;
        ansk = k;
      }
      i2 = c / i;
      k = 0;
      if (a % i2 > 0) k += i2 - (a % i2);
      t = (a + k) * (b + k) / i2;
      if (t == ans) {
        ansk = min(ansk, k);
      }
      if (t < ans) {
        ans = t;
        ansk = k;
      }
    }
  }
  printf("%lld", ansk);
}

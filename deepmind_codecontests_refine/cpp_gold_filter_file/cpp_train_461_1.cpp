#include <bits/stdc++.h>
using namespace std;
const long long inf = (1LL << 63) - 2;
int c1, c2, x, y;
bool ok(long long mi) {
  long long num = mi / (x * y);
  long long n1 = c1 - mi / y + num, n2 = c2 - mi / x + num;
  if (n1 < 0) n1 = 0;
  if (n2 < 0) n2 = 0;
  num = mi - mi / y - mi / x + num;
  if (n1 + n2 > num) return false;
  return true;
}
int main() {
  while (scanf("%d%d%d%d", &c1, &c2, &x, &y) != EOF) {
    long long ans = inf, mi, l = 1, r = inf;
    while (l <= r) {
      mi = (l + r) >> 1;
      if (ok(mi)) {
        ans = mi;
        r = mi - 1;
      } else
        l = mi + 1;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}

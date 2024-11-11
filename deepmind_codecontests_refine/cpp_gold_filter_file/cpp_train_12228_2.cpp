#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int main() {
  bool flag = false;
  long long n, a, b, ans = INF, l, r;
  scanf("%lld%lld%lld", &n, &a, &b);
  n *= 6;
  if (a > b) {
    swap(a, b);
    flag = true;
  }
  for (long long i = 1; i <= n; i++) {
    long long x = i, y = (long long)ceil(1.0 * n / i);
    if (x > y) break;
    x = max(x, a);
    y = max(y, b);
    if (x * y < ans) {
      ans = x * y;
      l = x;
      r = y;
    }
  }
  if (flag) swap(l, r);
  printf("%lld\n%lld %lld\n", ans, l, r);
  return 0;
}

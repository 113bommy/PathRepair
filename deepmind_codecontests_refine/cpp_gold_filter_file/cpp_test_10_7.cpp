#include <bits/stdc++.h>
using namespace std;
long long Fast(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % 1000000007;
    x = (x * x) % 1000000007, y >>= 1;
  }
  return ret;
}
signed main() {
  long long n, m, r, c, ax, ay, bx, by, k;
  scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &r, &c);
  scanf("%lld%lld%lld%lld", &ax, &ay, &bx, &by);
  if (ax == bx && ay == by)
    printf("%lld\n", Fast(k, n * m));
  else
    printf("%lld\n", Fast(k, n * m - r * c));
  return 0;
}

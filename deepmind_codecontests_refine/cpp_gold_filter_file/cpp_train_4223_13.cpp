#include <bits/stdc++.h>
const long long mod = 1000000007;
const long long Inf = 1e9;
using namespace std;
long long a, b, d, k, t;
double f(long long x) {
  double res = 0;
  res = (double)x * (double)a +
        (double)(max(x / k - (x % k == 0 ? 1 : 0), (long long)0)) * (double)t +
        (double)(d - x) * (double)b;
  return res;
}
int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &d, &k, &a, &b, &t);
  long long l = 1, r = d;
  double ans = 1e18;
  while (r - l > 2000000) {
    long long x1 = l + (r - l) / 3;
    long long x2 = r - (r - l) / 3;
    if (f(x1) > f(x2))
      l = x1;
    else if (f(x1) < f(x2))
      r = x2;
    else {
      l = x1;
      r = x2;
    }
  }
  for (long long i = l; i <= r; ++i) {
    ans = min(ans, f(i));
  }
  printf("%0.lf", ans);
  return 0;
}

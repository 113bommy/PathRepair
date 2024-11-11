#include <bits/stdc++.h>
using namespace std;
int main() {
  long long d, k, a, b, t;
  scanf("%lld%lld%lld%lld%lld", &d, &k, &a, &b, &t);
  if (d <= k)
    printf("%lld\n", d * a);
  else {
    long long ans = 0;
    if (k * a + t > k * b) {
      ans = k * a + (d - k) * b;
    } else {
      int n = d / k;
      ans = min(n * k * a + (n - 1) * t + (d % k) * b, d * a + n * t);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

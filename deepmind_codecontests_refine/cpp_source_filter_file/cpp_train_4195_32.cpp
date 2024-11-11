#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a, b, c, d, t, n;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if (a > b * c) {
      printf("-1\n");
      continue;
    }
    n = (a - 1) / b / d;
    printf("%lld\n", (n + 1) * a - d * (n)*n / 2 * b);
  }
}

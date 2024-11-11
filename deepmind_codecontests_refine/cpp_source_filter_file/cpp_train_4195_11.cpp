#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, n;
long long answer(long long k) {
  long long x = a * k;
  if (c > d) {
    long long y = (k * d - d - c) / d;
    y = max(y, 0ll);
    x = x - c * b * y;
    y = k - 1 - y;
    x = x - d * b * y * (y + 1) / 2;
  } else {
    x = x - c * b * (k - 1);
  }
  return x;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if (a > b * c) {
      printf("-1\n");
      continue;
    }
    long long ans = 0;
    long long l = 1;
    long long r = 1000010;
    int siz = 28;
    while (siz--) {
      long long mid = (l + r) / 2;
      long long mmid = (mid + r) / 2;
      long long x = answer(mid);
      long long y = answer(mmid);
      if (x >= y) {
        r = mmid;
        ans = max(x, ans);
      } else {
        l = mid;
        ans = max(y, ans);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}

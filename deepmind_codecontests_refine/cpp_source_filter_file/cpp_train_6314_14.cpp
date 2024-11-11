#include <bits/stdc++.h>
using namespace std;
long long i, n, m, x, l, r, mid, p, y, ans;
signed main() {
  scanf("%I64d%I64d", &n, &m);
  while (m--) {
    scanf("%I64d", &x);
    if (x & 1) {
      printf("%I64d\n", x / 2 + 1);
      continue;
    }
    l = 1, r = 2 * n - 1;
    while (l <= r) {
      mid = (l + r) / 2;
      y = x;
      p = mid;
      while (p % 2 == 0) {
        y += p;
        p >>= 1;
      }
      y += p;
      if (2 * n - 1 - y == p - 1) {
        ans = y / 2 + 1;
        break;
      }
      if (2 * n - 1 - y > p - 1)
        l = mid + 1;
      else
        r = mid - 1;
    }
    printf("%d\n", ans);
  }
}

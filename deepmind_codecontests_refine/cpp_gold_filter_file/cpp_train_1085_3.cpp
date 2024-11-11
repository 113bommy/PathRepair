#include <bits/stdc++.h>
using namespace std;
int x1, r1, x2, r2, i, l, r;
long long ans;
int main() {
  scanf("%d%d%d%d", &r1, &x1, &r2, &x2);
  if (x2 < x1) swap(x1, x2), swap(r1, r2);
  if (x1 == x2) return printf("%d\n", max(r1, r2) + 1), 0;
  for (i = 1; i <= r2; ++i) {
    if (x1 + r1 <= x2 - i || x1 - r1 > x2 - i) continue;
    if (x2 - x1 - i >= 0)
      l = x2 - x1 - i + 2, ans++;
    else {
      l = x2 - x1 - i;
      if (l < -r1)
        l = r1;
      else
        ans++, l = -l + 1;
    }
    r = x2 - x1 + i;
    if (r > r1)
      r = r1;
    else
      r--, ans++;
    ans += (r - l + 1) * 2;
  }
  ans +=
      max(0, min(x2 - r2 - x1 + r1, r1)) + max(0, min(x2 + r2 - x1 - r1, r2));
  printf("%I64d\n", ans + 1);
}

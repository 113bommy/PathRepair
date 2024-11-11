#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005], n, m, pos;
inline bool check(long long x) {
  long long p = 1;
  for (long long i = 1; i <= n; i++) {
    while (abs(a[i] - b[p]) + abs(pos - b[p]) > x) {
      p++;
      if (p > m) break;
    }
    if (abs(a[i] - b[p]) + abs(pos - b[p]) > x) return 0;
    if (p > m) return 0;
  }
  return 1;
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &pos);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1; i <= m; i++) scanf("%lld", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  long long l = 0;
  long long r = 2e9 + 10;
  long long ans = 2e9 + 10;
  while (l + 1 < r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid;
    else
      l = mid;
  }
  if (check(l)) ans = min(ans, l);
  if (check(r)) ans = min(ans, r);
  printf("%lld\n", ans);
  return 0;
}

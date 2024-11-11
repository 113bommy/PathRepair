#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, s, d[N], cnt[N];
bool check(long long x) {
  for (long long i = 1; i <= n; i++) d[i] = 1;
  long long full = 2, last = n;
  long long rest = n * (n + 1) / 2 - s;
  if (!rest) return 1;
  while (rest) {
    while (d[full] == d[full - 1] * x) full++;
    while (!d[last]) last--;
    if (last <= full) return 0;
    while (rest < last - full) full++;
    d[last]--;
    d[full]++;
    rest -= last - full;
    if (!rest) return 1;
  }
  return 0;
}
signed main() {
  scanf("%d%d", &n, &s);
  if (s < 2 * n - 1 || s > n * (n + 1) / 2) {
    printf("No\n");
    return 0;
  }
  long long l = 1, r = n - 1, ans = 1;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  check(ans);
  for (long long i = 1; d[i]; i++) cnt[i] = cnt[i - 1] + d[i];
  printf("Yes\n");
  for (long long i = 2; d[i]; i++) {
    for (long long j = 1; j <= d[i]; j++) {
      printf("%d ", cnt[i - 2] + 1 + (j - 1) / ans);
    }
  }
  return 0;
}

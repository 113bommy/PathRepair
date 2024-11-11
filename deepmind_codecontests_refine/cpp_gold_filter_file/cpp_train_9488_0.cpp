#include <bits/stdc++.h>
using namespace std;
int n, l, r, mid;
long long a[200005], m;
inline bool cmp(long long x, long long y) { return x > y; }
int main() {
  scanf("%d%I64d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  sort(a + 1, a + n + 1, cmp);
  int ans = -1;
  l = 1, r = m;
  while (l <= r) {
    mid = (l + r) >> 1;
    long long sum = 0;
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
      sum += max((long long)0, a[i] - ((i % mid == 0) ? i / mid - 1 : i / mid));
      if (sum >= m) {
        flag = true;
        break;
      }
    }
    if (flag) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d", ans);
  return 0;
}

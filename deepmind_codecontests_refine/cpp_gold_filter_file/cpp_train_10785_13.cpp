#include <bits/stdc++.h>
using namespace std;
long long a[2005], b[2005], pos;
int n, m;
inline long long mabs(long long x) { return x > 0 ? x : -x; }
inline bool judge(long long x) {
  int p = 1;
  for (int i = 1; i <= n; i++) {
    while (p <= m && mabs(b[p] - a[i]) + mabs(b[p] - pos) > x) p++;
    if (p > m) return false;
    p++;
  }
  return true;
}
int main() {
  scanf("%d%d%I64d", &n, &m, &pos);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%I64d", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  long long l = 0, r = 3e9, ans = 3e9;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (judge(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}

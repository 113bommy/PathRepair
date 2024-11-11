#include <bits/stdc++.h>
using namespace std;
int n, m;
long long vl[200010], ans = 0, b[200010];
void solve(long long cnt) {
  long long amin = 1ll * cnt * (cnt - 1) / 2 + cnt;
  long long tmp = amin;
  for (int i = 1; i <= n; i++) {
    if (vl[i] < tmp) return;
    tmp += cnt;
  }
  b[n] = min(vl[n], cnt * m - cnt * (cnt - 1) / 2 * n);
  for (int i = n - 1; i >= 1; i--) b[i] = min(vl[i], b[i + 1] - cnt);
  long long buy = b[1], cur = b[1];
  long long st = max(1ll, b[1] - (cnt - 1) * (m + 1) + cnt * (cnt - 1) / 2 * n);
  long long free = m - n * cnt - st + 1;
  for (int i = 2; i <= n; i++) {
    buy += cnt;
    long long shift = min(free, b[i] - buy);
    buy += shift;
    free -= shift;
    cur += buy;
  }
  ans = max(ans, cur);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &vl[i]);
  for (long long c = 1; c * n <= m; c++) solve(c);
  printf("%lld\n", ans);
  return 0;
}

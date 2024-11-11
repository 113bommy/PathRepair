#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n, d, dp[500005], N, cnt, _;
pair<pair<int, int>, int> p[500005];
int main() {
  scanf("%d%d", &N, &d);
  for (int i = 1; i <= N; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < d) continue;
    y = max(y, d);
    if (x < y)
      p[++n] = make_pair(make_pair(x, y), 0);
    else
      p[++n] = make_pair(make_pair(y, x), 1);
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    _ = max(_, p[i].first.second);
    if (!p[i].second) {
      if (p[i].first.second >= _) {
        int o = 1;
        for (int z = 262144; z; z >>= 1)
          if ((o | z) <= n && p[o | z].first.first <= p[i].first.second) o |= z;
        dp[i] = max(dp[i], dp[o] + 1);
      }
    } else
      ++cnt;
  }
  printf("%d\n", dp[n] + cnt);
  return 0;
}

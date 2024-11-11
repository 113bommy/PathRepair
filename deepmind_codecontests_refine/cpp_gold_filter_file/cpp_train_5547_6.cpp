#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];
struct xx {
  int t, x, y;
} a[N];
int dis(xx a1, xx a2) { return abs(a1.x - a2.x) + abs(a1.y - a2.y); }
int main() {
  memset(dp, -1, sizeof dp);
  int r, n;
  scanf("%d%d", &r, &n);
  a[0].x = 1, a[0].y = 1;
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) scanf("%d%d%d", &a[i].t, &a[i].x, &a[i].y);
  for (int i = 1; i <= n; ++i) {
    for (int j = max(0, i - 1 - r * 4); j < i; ++j) {
      if (dp[j] != -1 && a[i].t - a[j].t >= dis(a[i], a[j]))
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
  printf("%d\n", ans);
  return 0;
}

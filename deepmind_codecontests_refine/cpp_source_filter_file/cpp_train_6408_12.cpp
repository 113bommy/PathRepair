#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int dp[N], dis[N], m, n;
inline void rotate(int pos) {
  static int nw[N];
  int tp = 0;
  for (int i = pos; i <= n; i++) nw[++tp] = dis[i] - dis[pos] + 1;
  for (int i = 1; i < pos; i++) nw[++tp] = m - (dis[pos] - dis[i]) + 1;
  for (int i = 1; i <= tp; i++) dis[i] = nw[i];
}
inline int wkr() {
  int mx = 0, pos = 0;
  dis[n + 1] = m + dis[1];
  for (int i = 1; i <= n; i++) {
    int nxt = dis[i + 1] - dis[i];
    if (nxt > mx) mx = nxt, pos = i == n ? 1 : i + 1;
  }
  return pos;
}
inline bool check(int mid) {
  memset(dp, 0, sizeof(dp));
  for (int st = 1; st <= 2; st++) {
    dp[st] = st == 1 ? 0 : max(mid + 1, dis[2]);
    for (int i = st + 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      if (dp[i - 1] >= dis[i] - 1) dp[i] = dis[i] + mid;
      if (dp[i - 1] >= dis[i] - mid - 1) dp[i] = max(dp[i], dis[i]);
      if (i > st + 1 && dp[i - 2] >= dis[i] - mid - 1)
        dp[i] = max(dp[i], dis[i - 1] + mid);
    }
    if (dp[n] >= min(m, m + dis[st] - mid - 1)) return true;
  }
  return false;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &dis[i]);
  rotate(wkr());
  int l = 1, r = m, mid, res = 0;
  while (l <= r) {
    if (check(mid = (l + r) >> 1))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", res);
  return 0;
}

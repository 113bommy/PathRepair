#include <bits/stdc++.h>
using namespace std;
int t, n, m, l[3010], r[3010], cnt, a[6010];
int dp[6010][6010];
vector<int> v[6010];
inline int cal(int l, int r) {
  if (dp[l][r] != -1) return dp[l][r];
  dp[l][r] = 0;
  int pd = count(v[l].begin(), v[l].end(), r);
  dp[l][r] = max(dp[l][r], pd + (l == r ? 0 : cal(l + 1, r)));
  int mx = v[l].size();
  for (int i = 0; i < mx; ++i) {
    int ri = v[l][i];
    if (ri >= r) continue;
    dp[l][r] = max(dp[l][r], pd + cal(l, ri) + cal(ri + 1, r));
  }
  return dp[l][r];
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &l[i], &r[i]);
      a[++cnt] = l[i];
      a[++cnt] = r[i];
    }
    sort(a + 1, a + cnt + 1);
    m = unique(a + 1, a + cnt + 1) - a - 1;
    for (int i = 1; i <= n; ++i) {
      l[i] = lower_bound(a + 1, a + m + 1, l[i]) - a;
      r[i] = lower_bound(a + 1, a + m + 1, r[i]) - a;
      v[l[i]].push_back(r[i]);
    }
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= m; ++j) dp[i][j] = -1;
    printf("%d\n", cal(1, m));
    for (int i = 1; i <= n; ++i) v[l[i]].clear();
    for (int i = 1; i <= cnt; ++i) a[i] = 0;
  }
  return 0;
}

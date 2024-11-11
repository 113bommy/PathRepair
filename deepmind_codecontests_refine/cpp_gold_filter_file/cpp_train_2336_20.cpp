#include <bits/stdc++.h>
using namespace std;
int n, m, b;
struct poi {
  int x, k, a;
} P[106];
bool cmp(poi a, poi b) { return a.k < b.k; }
long long dp[2][1 << 20];
signed main() {
  cin >> n >> m >> b;
  for (int i = 1, c, x; i <= n; ++i) {
    scanf("%d%d%d", &P[i].x, &P[i].k, &c);
    while (c-- > 0) scanf("%d", &x), P[i].a |= (1 << x - 1);
  }
  sort(P + 1, P + 1 + n, cmp);
  int cur = 0, pre = 1;
  long long res = 0x3f3f3f3f3f3f3f3f;
  memset(dp[0], 0x3f3f, sizeof dp[0]);
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    cur ^= 1, pre ^= 1;
    memset(dp[cur], 0x3f3f, sizeof dp[cur]);
    for (int sta = 0; sta < (1 << m); ++sta) {
      dp[cur][sta] = min(dp[cur][sta], dp[pre][sta]);
      dp[cur][sta | P[i].a] = min(dp[cur][sta | P[i].a], dp[pre][sta] + P[i].x);
    }
    res = min(res, dp[cur][(1 << m) - 1] + 1ll * P[i].k * b);
  }
  cout << (res == 0x3f3f3f3f3f3f3f3f ? -1 : res) << endl;
}

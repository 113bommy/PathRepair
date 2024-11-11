#include <bits/stdc++.h>
using namespace std;
int n;
int tot;
int cost[200050 << 1];
int head[200050], edge[200050 << 1], nxt[200050 << 1];
void join(int u, int v, int w) {
  cost[tot] = w;
  edge[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
  cost[tot] = w;
  edge[tot] = u;
  nxt[tot] = head[v];
  head[v] = tot++;
}
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    join(u, v, w);
  }
}
long long ans;
long long dp[200050][4];
void dfs(int i, int fa = 0) {
  long long tmp = 0;
  for (int k = head[i]; ~k; k = nxt[k]) {
    int j = edge[k], w = cost[k];
    if (fa == j) continue;
    dfs(j, i);
    long long t = 0;
    if (!w) {
      ++dp[j][0];
      t += dp[j][0] * 2 + dp[j][2] + dp[j][1];
      t += dp[i][0] * dp[j][0] * 2;
      t += dp[i][0] * (dp[j][2] + dp[j][1]) + (dp[i][1] + dp[i][2]) * dp[j][0];
      dp[i][0] += dp[j][0];
      dp[i][2] += dp[j][1] + dp[j][2];
    } else {
      ++dp[j][1];
      t += dp[j][1] * 2 + dp[j][3] + dp[j][0];
      t += dp[i][1] * dp[j][1] * 2;
      t += dp[i][1] * (dp[j][0] + dp[j][3]) + (dp[i][0] + dp[i][3]) * dp[j][1];
      dp[i][1] += dp[j][1];
      dp[i][3] += dp[j][0] + dp[j][3];
    }
    tmp += t;
  }
  ans += tmp;
}
void solve() {
  dfs(1);
  cout << ans << endl;
}
int main() {
  init();
  solve();
}

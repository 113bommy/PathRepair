#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
const int INF = 0x3f3f3f3f;
int dp[maxn][maxn], sz[maxn], fa[maxn], pre[maxn][maxn];
vector<int> vec[maxn];
int mp[maxn][maxn], a[maxn], b[maxn][maxn];
void dfs2(int u, int p, int sum) {
  int tot = 0;
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == p) continue;
    tot++;
    dfs2(v, u, sum);
    for (int j = sz[u]; j >= 0; j--) {
      for (int k = min(sz[v], j); k >= 0; k--) {
        if (dp[u][j - k] + dp[v][k] < dp[u][j]) {
          pre[u][j] = j - k;
          b[u][j] = v;
        }
        dp[u][j] = min(dp[u][j], dp[u][j - k] + dp[v][k]);
      }
    }
  }
  if (u != 1) {
    if (tot == 0) dp[u][1] = 1;
    dp[u][sz[u]] = 1;
  }
}
void dfs(int u, int p) {
  sz[u] = 1;
  for (int i = 0; i < vec[u].size(); i++) {
    int v = vec[u][i];
    if (v == p) continue;
    fa[v] = u;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
void pt(int u, int x) {
  if (sz[u] == x) {
    printf("%d ", mp[u][fa[u]]);
    return;
  }
  while (x) {
    int v = b[u][x];
    pt(v, x - pre[u][x]);
    x = pre[u][x];
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    vec[u].push_back(v);
    vec[v].push_back(u);
    mp[u][v] = i;
    mp[v][u] = i;
  }
  dfs(1, 1);
  memset(dp, INF, sizeof(dp));
  dp[1][0] = 0;
  for (int i = 1; i < maxn; i++) dp[i][0] = 0;
  dfs2(1, 1, k);
  int ans = INF;
  int id = 1;
  for (int i = 1; i <= n; i++) {
    if (i != 1) dp[i][sz[i] - k]++;
    if (sz[i] >= k) {
      if (dp[i][sz[i] - k] < ans) {
        id = i;
        ans = min(ans, dp[i][sz[i] - k]);
      }
    }
  }
  cout << ans << endl;
  if (id != 1) cout << mp[id][fa[id]] << " ";
  pt(id, sz[id] - k);
}

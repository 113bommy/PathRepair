#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int n, m;
char s[maxn];
int vis[maxn];
int dp[maxn][27];
vector<int> G[maxn];
int ans = 0;
void dfs(int u) {
  vis[u] = 1;
  dp[u][s[u] - 'a'] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (vis[v] == 1) {
      cout << "-1" << endl;
      exit(0);
    } else {
      if (!vis[v]) dfs(v);
      for (int j = 0; j < 26; j++) {
        dp[u][j] = max(dp[u][j], dp[v][j] + (s[u] - 'a' == j));
      }
    }
  }
  vis[u] = 2;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
  }
  memset(vis, 0, sizeof(vis));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
      for (int j = 0; j < 26; j++) {
        ans = max(ans, dp[i][j]);
      }
    }
  }
  cout << ans << endl;
}

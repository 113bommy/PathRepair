#include <bits/stdc++.h>
using namespace std;
int ti = 1;
int low[300005], vis[300005], p[300005];
bool idx[300005];
vector<pair<int, int> > g[300005], g2[300005];
int v[300005], w[300005];
long long c[30005];
int s[300005];
int root(int a) { return p[a] == a ? a : (p[a] = root(p[a])); }
void merge(int a, int b) {
  a = root(a), b = root(b);
  if (a != b) {
    p[a] = b;
    c[b] += c[a];
    s[b] += s[a];
  }
}
void dfs1(int u, int p) {
  vis[u] = low[u] = ti++;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i].first;
    if (v != p) {
      if (vis[v])
        low[u] = min(low[u], vis[v]);
      else {
        dfs1(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] > vis[u]) idx[g[u][i].second] = 1;
      }
    }
  }
}
long long dp[300005];
int n, m, k;
void dfs2(int u, int p) {
  for (int i = 0; i < (int)(g2[u]).size(); i++) {
    int v = g2[u][i].first, idx = g2[u][i].second;
    if (v != p) {
      dfs2(v, u);
      s[u] += s[v];
    }
  }
  dp[u] = c[u];
  bool ok = 0;
  for (int i = 0; i < (int)(g2[u]).size(); i++) {
    int v = g2[u][i].first, idx = g2[u][i].second;
    if (v != p) {
      long long sum = max(0 * 1ll, dp[v] - w[idx]);
      if (s[v] == k)
        ok = 1;
      else if (s[v] == 0)
        sum = max(sum, dp[v]);
      dp[u] += sum;
    }
  }
  if (ok) {
    dp[u] = c[u];
    for (int i = 0; i < (int)(g2[u]).size(); i++) {
      int v = g2[u][i].first, idx = g2[u][i].second;
      if (v != p) dp[u] += dp[v];
    }
  }
}
void dfs3(int u, int p) {
  for (int i = 0; i < (int)(g2[u]).size(); i++) {
    int v = g2[u][i].first, idx = g2[u][i].second;
    if (v != p) {
      if (s[v] == 0 || s[v] == k) {
        dp[v] = dp[u];
        dfs3(v, u);
      } else {
        long long sum = max(0 * 1ll, dp[v] - w[idx]);
        dp[v] = max(dp[v], dp[u] - sum - w[idx] + dp[v]);
        dfs3(v, u);
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= k; i++) scanf("%d", &v[i]), s[v[i]] = 1;
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].emplace_back(make_pair(b, i));
    g[b].emplace_back(make_pair(a, i));
  }
  dfs1(1, 0);
  for (int u = 1; u <= n; u++) {
    for (int j = 0; j < g[u].size(); j++) {
      int v = g[u][j].first, i = g[u][j].second;
      if (!idx[i]) merge(u, v);
    }
  }
  for (int u = 1; u <= n; u++) {
    for (int j = 0; j < g[u].size(); j++) {
      int v = g[u][j].first, i = g[u][j].second;
      int a = root(u), b = root(v);
      if (idx[i]) {
        g2[a].emplace_back(make_pair(b, i));
      }
    }
  }
  dfs2(root(1), 0);
  dfs3(root(1), 0);
  for (int i = 1; i <= n; i++) printf("%lld ", dp[root(i)]);
}

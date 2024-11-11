#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, m, a, b;
vector<int> g[MAXN];
int sz[MAXN], dp[MAXN];
int cnt[MAXN];
vector<int> *vec[MAXN];
int par[MAXN][17];
vector<pair<int, int>> q[MAXN];
int ans[MAXN];
void get_size_depth(int u, int f) {
  sz[u] = 1;
  dp[u] = dp[f] + 1;
  for (auto &v : g[u]) {
    if (v == f) continue;
    get_size_depth(v, u);
    sz[u] += sz[v];
  }
}
void dfs(int u, int f, bool keep) {
  int mx = -1, big = -1;
  for (auto &v : g[u]) {
    if (v == f) continue;
    if (mx < sz[v]) big = v, mx = sz[v];
  }
  for (auto &v : g[u]) {
    if (v == f || v == big) continue;
    dfs(v, u, 0);
  }
  if (big != -1)
    dfs(big, u, 1), vec[u] = vec[big];
  else
    vec[u] = new vector<int>();
  vec[u]->push_back(u);
  cnt[dp[u]]++;
  for (auto &v : g[u]) {
    if (v == f || v == big) continue;
    for (auto &x : *vec[v]) {
      vec[u]->push_back(x);
      cnt[dp[x]]++;
    }
  }
  for (auto &p : q[u])
    ans[p.second] = (cnt[p.first + dp[u]] > 0) ? cnt[p.first + dp[u]] - 1 : 0;
  if (!keep)
    for (auto &x : *vec[u]) cnt[dp[x]]--;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    g[a].push_back(i);
    g[i].push_back(a);
    par[i][0] = a;
  }
  for (auto &p : g[0]) get_size_depth(p, 0);
  for (int u = 1; u <= n; u++)
    for (int i = 1; i < 17; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    int vh = dp[a];
    for (int j = 0; j < 17; j++)
      if ((vh - b - dp[a]) >> j & 1) a = par[a][j];
    q[a].push_back(make_pair(b, i));
  }
  for (auto &p : g[0]) dfs(p, 0, 0);
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
}

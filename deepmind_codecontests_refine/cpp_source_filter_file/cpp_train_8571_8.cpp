#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAXN = 100010;
const int MAXK = 20;
vector<int> graph[MAXN];
int marc[MAXN];
int dp[MAXN][MAXK];
int prof[MAXN];
int aux[MAXN];
int subtree[MAXN];
pii arcs[MAXN];
void init_dfs(int u) {
  marc[u] = 1;
  for (int v : graph[u]) {
    if (marc[v]) continue;
    dp[v][0] = u;
    for (int i = 1; i < MAXK; ++i) dp[v][i] = dp[dp[v][i - 1]][i - 1];
    prof[v] = prof[u] + 1;
    init_dfs(v);
  }
}
void last_dfs(int u) {
  marc[u] = 2;
  subtree[u] = aux[u];
  for (int v : graph[u]) {
    if (marc[v] == 2) continue;
    last_dfs(v);
    subtree[u] += subtree[v];
  }
}
inline int lca(int u, int v) {
  if (prof[u] > prof[v]) swap(u, v);
  int d = prof[v] - prof[u];
  for (int i = 0; i < MAXK; ++i)
    if (d & (1 << i)) v = dp[v][i];
  if (u == v) return u;
  for (int i = MAXK - 1; i >= 0; --i)
    if (dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][v];
    }
  return dp[u][0];
}
inline void add_path(int u, int v) {
  ++aux[u];
  --aux[v];
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
    arcs[i] = {u, v};
  }
  init_dfs(1);
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    int w = lca(u, v);
    add_path(u, w);
    add_path(v, w);
  }
  last_dfs(1);
  for (int i = 0; i < n - 1; ++i) {
    auto [u, v] = arcs[i];
    if (prof[u] < prof[v]) swap(u, v);
    printf("%d ", subtree[u]);
  }
  printf("\n");
}

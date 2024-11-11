#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> adj[maxn], ans[2];
bool mark[maxn];
void dfs(int u = 1, int ind = 0) {
  mark[u] = 1;
  ans[ind].push_back(u);
  for (auto v : adj[u])
    if (!mark[v]) dfs(v, (ind + 1) % 2);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) adj[i].clear(), mark[i] = 0;
    ans[0].clear();
    ans[1].clear();
    for (int i = 0, u, v; i < m; i++)
      scanf("%d%d", &u, &v), adj[u].push_back(v), adj[v].push_back(u);
    dfs();
    if (ans[0].size() < ans[1].size()) {
      printf("%d\n", ans[0].size());
      for (auto u : ans[0]) printf("%d ", u);
      printf("\n");
    } else {
      printf("%d\n", ans[1].size());
      for (auto u : ans[1]) printf("%d ", u);
      printf("\n");
    }
  }
  return 0;
}

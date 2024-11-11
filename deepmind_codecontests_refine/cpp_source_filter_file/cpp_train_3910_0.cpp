#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
bool is[maxn];
vector<int> adj[maxn];
int sz[maxn];
bool mark[maxn];
void dfs(int u) {
  mark[u] = 1;
  if (is[u]) sz[u] = 1;
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (mark[v]) continue;
    dfs(v);
    sz[u] += sz[v];
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 2 * m; ++i) {
    int t;
    scanf("%d", &t);
    is[t] = 1;
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  int res = 0;
  for (int i = 2; i <= n; ++i) res += min(sz[i], 2 * m - sz[i]);
  cout << res << "\n";
}

#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 5;
vector<int> adj[Maxn];
int sz[Maxn];
int n;
long long ret, ans;
void dfs_init(int u, int f) {
  sz[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == f) continue;
    dfs_init(v, u);
    sz[u] += sz[v];
  }
  ret += sz[u];
}
void dfs(int u, int f, long long ret) {
  ans = max(ans, ret);
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == f) continue;
    dfs(v, u, ret + n - 2 * sz[v]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = ret = 0;
  dfs_init(1, 0);
  dfs(1, 0, ret);
  printf("%d\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int NN = 806060;
int flag[NN], root[NN], d[NN];
vector<pii> adj[NN];
int find_root(int u) { return root[u] = root[u] == u ? u : find_root(root[u]); }
int merge(int u, int v) {
  u = find_root(u);
  v = find_root(v);
  root[v] = u;
  return (u ^ v);
}
void dfs(int u, int fa = -1) {
  for (auto p : adj[u]) {
    int v = p.first;
    if (v == fa) continue;
    dfs(v, u);
  }
  for (auto p : adj[u]) {
    int v = p.first, id = p.second;
    if (v == fa) continue;
    if (d[v] == 1) {
      flag[id] = 1;
      if (d[u] == -1) continue;
      d[u] = (d[u] ^ 1);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", d + i);
  int rt = 0;
  for (int i = 1; i <= n; i++)
    if (d[i] == -1) rt = i;
  if (!rt) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += d[i];
    if (sum & 1) {
      puts("-1");
      return 0;
    }
    rt = 1;
  }
  for (int i = 1; i <= n; i++) root[i] = i;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (merge(u, v)) adj[u].push_back(pii(v, i)), adj[v].push_back(pii(u, i));
  }
  dfs(rt);
  int ans = 0;
  for (int i = 1; i <= m; i++) ans += flag[i];
  cout << ans << endl;
  for (int i = 1; i <= m; i++)
    if (flag[i]) printf("%d\n", i);
  return 0;
}

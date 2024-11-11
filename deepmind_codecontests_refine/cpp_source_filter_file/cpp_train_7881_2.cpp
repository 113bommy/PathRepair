#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int T = 5e3 + 10;
int vez;
vector<int> g[T];
vector<pair<int, int> > nodes;
int vis[T];
bool chegou[T];
void dfs(int u) {
  chegou[u] = true;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (!chegou[v]) dfs(v);
  }
}
int dfs2(int u) {
  vis[u] = vez;
  int cont = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (vis[v] != vez && !chegou[v]) cont += dfs2(v);
  }
  return cont;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first != b.first) return a.first < b.first;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, s, u, v;
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
  }
  dfs(s);
  for (int i = 1; i <= n; i++) {
    if (!chegou[i]) {
      vez++;
      int cont = dfs2(i);
      nodes.emplace_back(cont, i);
    }
  }
  sort(nodes.begin(), nodes.end(), cmp);
  int ans = 0;
  for (auto x : nodes) {
    if (!chegou[x.second]) {
      ans++;
      dfs(x.second);
    }
  }
  cout << ans << endl;
  return 0;
}

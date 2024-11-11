#include <bits/stdc++.h>
using namespace std;
vector<int> G[200009];
int anc[200009][20];
int depth[200009];
void dfs(int u, int p = -1) {
  anc[u][0] = p;
  for (int i = 1; i < 20; i++) {
    anc[u][i] = (anc[u][i - 1]) ? anc[anc[u][i - 1]][i - 1] : -1;
  }
  for (auto v : G[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = 20 - 1; i >= 0; i--) {
    if (depth[u] - (1 << i) >= depth[v]) {
      u = anc[u][i];
    }
  }
  if (u == v) return u;
  for (int i = 20 - 1; i >= 0; i--) {
    if (anc[u][i] != anc[v][i]) {
      u = anc[u][i];
      v = anc[v][i];
    }
  }
  return anc[u][0];
}
bool cmp(int a, int b) { return depth[a] < depth[b]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(1);
    while (m--) {
      int k;
      cin >> k;
      vector<int> v(k);
      for (int i = 0; i < k; i++) cin >> v[i];
      sort(v.begin(), v.end(), cmp);
      bool ok = 1;
      for (int i = 0; i < k; i++) {
        int w = lca(v[i], v[k - 1]);
        ok = ok & (depth[v[i]] <= depth[w] + 1);
      }
      if (ok)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}

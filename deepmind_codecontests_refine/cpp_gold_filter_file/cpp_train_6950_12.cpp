#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int par[N], a[N], far[N];
bool have[N];
vector<int> adj[N];
vector<pair<int, int> > edges;
int res[N], sum[N];
int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
bool join(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return false;
  par[v] = u;
  return true;
}
void dfs(int u, int p) {
  sum[u] = a[u];
  for (auto v : adj[u])
    if (v != p) {
      far[v] = far[u] + 1;
      dfs(v, u);
      sum[u] += sum[v];
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = (1); i <= (n); ++i) par[i] = i;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  cin >> m;
  for (int i = (1); i <= (m); ++i) {
    int u, v;
    cin >> u >> v;
    edges.push_back(pair<int, int>(u, v));
    if (join(u, v)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
      have[i] = true;
    }
  }
  int tot = 0;
  for (int i = (1); i <= (n); ++i) tot += a[i];
  if (tot) return cout << "Impossible\n", 0;
  dfs(1, 1);
  cout << "Possible\n";
  for (int i = (1); i <= (m); ++i)
    if (have[i]) {
      int u = edges[i - 1].first;
      int v = edges[i - 1].second;
      if (far[u] < far[v])
        res[i] = sum[v];
      else
        res[i] = -sum[u];
    }
  for (int i = (1); i <= (m); ++i) cout << res[i] << '\n';
}

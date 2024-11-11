#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> s(n + 1);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    sum += s[i];
  }
  if (sum != 0) return !(cout << "Impossible");
  int m;
  cin >> m;
  vector<pair<int, int> > edges;
  vector<vector<int> > adj(n + 1);
  vector<int> par(n + 1);
  vector<long long> nani(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.push_back({u, v});
  }
  function<void(int)> DFS = [&](int u) {
    if (par[u] == 0) par[u] = -1;
    nani[u] = s[u];
    for (int v : adj[u])
      if (par[v] == 0) {
        par[v] = u;
        DFS(v);
        nani[u] += nani[v];
      }
  };
  DFS(1);
  cout << "Possible";
  for (auto [u, v] : edges) {
    if (par[u] != v && par[v] != u)
      cout << "0\n";
    else {
      if (par[v] == u)
        cout << nani[v] << '\n';
      else
        cout << -nani[u] << '\n';
    }
  }
  return 0;
}

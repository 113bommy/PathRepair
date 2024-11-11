#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
using namespace std;
const int MXN = 1e5 + 10;
int n, m, q, trn;
int Par[MXN], SZ[MXN];
vector<int> M[MXN];
vector<pair<int, int>> G[MXN], E[MXN], Q[MXN], Qu;
map<pair<int, int>, bool> mp;
map<pair<int, int>, int> ans;
int Find(int u) { return (Par[u] == u ? u : Par[u] = Find(Par[u])); }
inline bool Union(int u, int v) {
  u = Find(u), v = Find(v);
  if (u == v) return 0;
  if (SZ[v] > SZ[u]) swap(u, v);
  for (auto x : M[v]) {
    for (auto Pr : Q[x]) {
      int y = Pr.first, id = Pr.second;
      if (Find(y) == u) ans[{min(x, y), max(x, y)}]++;
    }
  }
  for (auto x : M[v]) {
    M[u].push_back(x);
  }
  Par[v] = u, SZ[u] += SZ[v];
  M[v].clear();
  M[v].shrink_to_fit();
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) SZ[i] = 1, Par[i] = i, M[i].push_back(i);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back({v, w}), G[v].push_back({u, w});
    E[w].push_back({u, v});
  }
  cin >> q;
  while (trn < q) {
    int u, v;
    cin >> u >> v;
    Qu.push_back({u, v});
    if (mp[{min(u, v), max(u, v)}]) {
      trn++;
      continue;
    }
    mp[{min(u, v), max(u, v)}] = 1;
    Q[u].push_back({v, trn}), Q[v].push_back({u, trn});
    trn++;
  }
  for (int c = 1; c <= m; c++) {
    if (E[c].empty()) continue;
    for (auto Pr : E[c]) {
      int u = Pr.first, v = Pr.second;
      Union(u, v);
    }
    for (auto Pr : E[c]) {
      int u = Pr.first, v = Pr.second;
      Par[u] = u, SZ[u] = 1;
      Par[v] = v, SZ[v] = 1;
      M[u].clear(), M[v].clear();
      M[u].shrink_to_fit(), M[v].shrink_to_fit();
      M[u].push_back(u), M[v].push_back(v);
    }
  }
  for (int i = 0; i < q; i++) {
    cout
        << ans[{min(Qu[i].first, Qu[i].second), max(Qu[i].first, Qu[i].second)}]
        << endl;
  }
  return 0;
}

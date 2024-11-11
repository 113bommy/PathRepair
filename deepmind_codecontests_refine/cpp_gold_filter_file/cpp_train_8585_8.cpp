#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, m, h[MAXN], par[MAXN];
vector<pair<int, int> > adj[MAXN];
bool mark[MAXN];
vector<pair<int, int> > bc, vec[MAXN];
bool marke[MAXN];
void dfs(int u) {
  mark[u] = true;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i].first;
    if (marke[adj[u][i].second]) continue;
    marke[adj[u][i].second] = true;
    if (!mark[v]) {
      par[v] = u, h[v] = h[u] + 1;
      dfs(v);
    } else
      bc.push_back({u, v});
  }
}
inline void dfs_all() {
  for (int i = 0; i < n; i++) {
    if (!mark[i]) par[i] = i, dfs(i);
  }
}
inline vector<int> path(int u, int v) {
  vector<int> vc;
  while (u != v) {
    vc.push_back(u);
    u = par[u];
  }
  vc.push_back(v);
  return vc;
}
inline void solve(int z, int x, int y, int u, int v) {
  int f = (h[y] >= h[v] ? y : v);
  vector<int> v1 = path(z, f);
  vector<int> v2 = path(x, z);
  vector<int> v2p = path(f, y);
  reverse(v2.begin(), v2.end());
  for (int i = v2p.size() - 1; i >= 0; i--) v2.push_back(v2p[i]);
  vector<int> v3 = path(u, z);
  reverse(v3.begin(), v3.end());
  vector<int> v3p = path(f, v);
  for (int i = v3p.size() - 1; i >= 0; i--) v3.push_back(v3p[i]);
  cout << "YES" << endl;
  cout << v1.size() << " ";
  for (int i = 0; i < v1.size(); i++) cout << ++v1[i] << " ";
  cout << endl << v2.size() << " ";
  for (int i = 0; i < v2.size(); i++) cout << ++v2[i] << " ";
  cout << endl << v3.size() << " ";
  for (int i = 0; i < v3.size(); i++) cout << ++v3[i] << " ";
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    adj[u].push_back({v, i}), adj[v].push_back({u, i});
  }
  dfs_all();
  for (int i = 0; i < bc.size(); i++) {
    int u = bc[i].first, v = bc[i].second;
    int cur = u;
    while (cur != v) {
      if (vec[cur].size()) {
        solve(cur, u, v, vec[cur].back().first, vec[cur].back().second);
        return 0;
      }
      cur = par[cur];
    }
    cur = u;
    while (cur != v) {
      vec[cur].push_back({u, v});
      cur = par[cur];
    }
  }
  cout << "NO" << endl;
  return 0;
}

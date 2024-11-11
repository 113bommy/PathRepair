#include <bits/stdc++.h>
using namespace std;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const long long MAXN = 1e6 + 10;
const long long INF = 8e18;
const long long MOD = 1e9 + 7;
vector<pair<long long, long long> > adj[MAXN];
pair<pair<long long, long long>, long long> edges[MAXN];
int n, m, G, S, B;
bool found, vis[210];
vector<int> path;
long long ans = INF;
inline void Remove(int ind) {
  int u = edges[ind].first.first, v = edges[ind].first.second;
  adj[u].erase(
      find((adj[u]).begin(), (adj[u]).end(), make_pair(1ll * v, 1ll * ind)));
  adj[v].erase(
      find((adj[v]).begin(), (adj[v]).end(), make_pair(1ll * u, 1ll * ind)));
}
inline void Add(int ind) {
  int u = edges[ind].first.first, v = edges[ind].first.second;
  adj[u].push_back({v, ind});
  adj[v].push_back({u, ind});
}
void dfs(int v, int p, int tar) {
  if (v == tar) {
    found = true;
    return;
  }
  for (pair<long long, long long> e : adj[v]) {
    int u = e.first, ind = e.second;
    if (u == p) continue;
    path.push_back(ind);
    dfs(u, v, tar);
    if (found) return;
    path.pop_back();
  }
}
void dfs2(int v, int p) {
  vis[v] = true;
  for (pair<long long, long long> e : adj[v]) {
    int ind = e.second, u = e.first;
    if (u == p) continue;
    dfs2(u, v);
    B = max(1ll * B, edges[ind].second);
  }
}
inline void Ans(int tg) {
  B = 0;
  memset(vis, false, sizeof vis);
  dfs2(1, 0);
  if (find(vis + 1, vis + n + 1, false) != vis + n + 1) return;
  ans = min(ans, 1ll * tg * G + 1ll * B * S);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> G >> S;
  vector<pair<long long, long long> > E;
  for (int i = 1; i <= m; i++) {
    int u, v, g, s;
    cin >> u >> v >> g >> s;
    edges[i] = {{u, v}, s};
    E.push_back({g, i});
  }
  sort((E).begin(), (E).end());
  for (pair<long long, long long> e : E) {
    int g = e.first, ind = e.second, u = edges[ind].first.first,
        v = edges[ind].first.second, s = edges[ind].second;
    found = false;
    path.clear();
    dfs(u, 0, v);
    if (!found)
      Add(ind);
    else {
      int bw = 0, r_ind = -1;
      for (int e : path) {
        if (edges[e].second > bw) {
          bw = edges[e].second;
          r_ind = e;
        }
      }
      if (bw > s) {
        Remove(r_ind);
        Add(ind);
      }
    }
    Ans(g);
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';
  return 0;
}

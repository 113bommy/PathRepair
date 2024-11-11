#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, u, v, dsu[N];
long long w;
vector<tuple<long long, int, int>> edge;
vector<pair<int, long long>> adj[N];
int trace(int x) { return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]); }
void join(int x, int y) {
  if ((x = trace(x)) == (y = trace(y))) return;
  if (dsu[x] > dsu[y]) swap(x, y);
  dsu[x] += dsu[y];
  dsu[y] = x;
}
bool vis[N];
int par[N][20], tin[N], tout[N], t = 0;
long long mx[N][20];
void dfs(int x) {
  tin[x] = t++;
  vis[x] = true;
  for (auto &p : adj[x]) {
    auto [y, w] = p;
    if (!vis[y]) {
      par[y][0] = x;
      mx[y][0] = w;
      dfs(y);
    }
  }
  tout[x] = t++;
}
bool anc(int x, int y) { return tin[x] <= tin[y] && tout[y] <= tout[x]; }
int lca(int x, int y) {
  if (anc(x, y)) return x;
  for (int i = 19; i >= 0; i--) {
    if (!anc(par[x][i], y)) x = par[x][i];
  }
  return par[x][0];
}
long long getmx(int x, int c) {
  if (anc(x, c)) return LLONG_MIN;
  long long ans = LLONG_MIN;
  for (int i = 19; i >= 0; i--) {
    if (!anc(par[x][i], c)) {
      ans = max(ans, mx[x][i]);
      x = par[x][i];
    }
  }
  return max(ans, mx[x][0]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  fill(dsu, dsu + N, -1);
  for (int i = (0); i < (m); i++) {
    cin >> u >> v >> w;
    edge.emplace_back(w, u, v);
  }
  sort((edge).begin(), (edge).end());
  long long W = -1;
  vector<tuple<long long, int, int>> ve;
  for (auto &p : edge) {
    tie(w, u, v) = p;
    if (trace(u) == trace(v)) {
      ve.push_back(p);
    } else {
      W = w;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
      join(u, v);
    }
  }
  par[1][0] = 1;
  dfs(1);
  for (int l = 1; l < 20; l++) {
    for (int i = (1); i < (n + 1); i++) {
      par[i][l] = par[par[i][l - 1]][l - 1];
      mx[i][l] = max(mx[i][l], mx[par[i][l - 1]][l - 1]);
    }
  }
  long long ans = 0;
  for (auto &p : ve) {
    tie(w, u, v) = p;
    if (w <= W) {
      int c = lca(u, v);
      long long m = max(getmx(u, c), getmx(v, c));
      ans += max(0LL, m - w + 1);
    }
  }
  cout << ans << '\n';
}

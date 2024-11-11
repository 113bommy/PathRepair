#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 10, inf = 2e9 + 7;
const ll INF = 1e18, mod = 1e9 + 7, P = 57;
struct edge {
  int u, v, g, s;
} E[N];
bool cmp(edge x, edge y) { return x.g < y.g; }
vector<pair<int, int> > g[201];
int n, m;
ll G, second;
pair<int, pair<int, int> > dfs(int v, int u, int p = -1) {
  for (auto x : g[v]) {
    int to, w;
    tie(to, w) = x;
    if (to == u) {
      return {w, {v, to}};
    } else if (to != p) {
      pair<int, pair<int, int> > res = dfs(to, u, v);
      if (res.first != 0) {
        return max(res, {w, {v, to}});
      }
    }
  }
  return {0, {0, 0}};
}
void remove(int a, int b) {
  for (int i = 0; i < g[a].size(); i++) {
    if (g[a][i].first == b) {
      swap(g[a][i], g[a].back());
      g[a].pop_back();
      return;
    }
  }
}
int heaviest() {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (auto to : g[i]) {
      res = max(res, to.second);
    }
  }
  return res;
}
void solve() {
  cin >> n >> m >> G >> second;
  for (int i = 1; i <= m; i++) {
    cin >> E[i].u >> E[i].v >> E[i].g >> E[i].s;
    if (E[i].u == E[i].v) {
      i--;
      m--;
    }
    if (E[i].u > E[i].v) swap(E[i].u, E[i].v);
  }
  sort(E + 1, E + m + 1, cmp);
  int comps = n;
  ll ans = -1;
  for (int i = 1; i <= m; i++) {
    pair<int, pair<int, int> > bigest = dfs(E[i].u, E[i].v);
    if (bigest.first == 0) {
      comps--;
      g[E[i].u].push_back({E[i].v, E[i].s});
      g[E[i].v].push_back({E[i].u, E[i].s});
    } else if (E[i].s < bigest.first) {
      remove(bigest.second.first, bigest.second.second);
      remove(bigest.second.second, bigest.second.first);
      g[E[i].u].push_back({E[i].v, E[i].s});
      g[E[i].v].push_back({E[i].u, E[i].s});
    }
    if (comps == 1) {
      ll cans = E[i].g * G + heaviest() * second;
      ans = (ans == -1 ? cans : min(ans, cans));
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}

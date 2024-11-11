#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, maxn = 1e5 + 1;
const long long inff = 1e18;
const long double eps = 1e-9;
struct edge {
  int u, first, id;
  long long second;
  bool pick;
};
vector<edge> e;
vector<pair<int, long long> > adj[maxn];
int n, k, m;
int lab[maxn], par_weight[maxn];
int root(int i) { return (lab[i] < 0 ? i : lab[i] = root(lab[i])); }
void set_union(int ra, int rb) {
  if (lab[ra] > lab[rb]) swap(ra, rb);
  lab[ra] += lab[rb];
  lab[rb] = ra;
}
long long mstsum = 0;
void build_mst() {
  for (edge &x : e) {
    int ra = root(x.u), rb = root(x.first);
    if (ra == rb) continue;
    set_union(ra, rb);
    adj[x.u].push_back(make_pair(x.first, x.second));
    adj[x.first].push_back(make_pair(x.u, x.second));
    x.pick = 1;
    mstsum += x.second;
  }
}
void input() {
  cin >> n >> m;
  e.resize(m);
  for (int i = 1; i <= m; ++i)
    cin >> e[i - 1].u >> e[i - 1].first >> e[i - 1].second, e[i - 1].id = i;
  fill(lab + 1, lab + n + 1, -1);
  sort(e.begin(), e.end(), [](edge a, edge b) { return a.second < b.second; });
  build_mst();
}
int p[maxn][20], h[maxn];
long long max_edge[maxn][20];
void dfs(int i) {
  for (auto it : adj[i]) {
    int j = it.first;
    if (j == p[i][0]) continue;
    {
      p[j][0] = i;
      h[j] = h[i] + 1;
      max_edge[j][0] = it.second;
      for (int d = 1; (1 << d) <= n; ++d)
        p[j][d] = p[p[j][d - 1]][d - 1],
        max_edge[j][d] = max(max_edge[j][d - 1], max_edge[p[j][d - 1]][d - 1]);
      dfs(j);
    }
  }
}
pair<int, long long> lca(int u, int first) {
  long long max_weight = 0;
  if (h[u] < h[first]) swap(u, first);
  int d = h[u] - h[first];
  for (int i = 0; (1 << i) <= d; ++i)
    if ((d >> i) & 1) max_weight = max(max_weight, max_edge[u][i]), u = p[u][i];
  if (u == first) return make_pair(u, max_weight);
  int i;
  for (i = 0; (1 << i) <= n; ++i)
    ;
  for (--i; i >= 0; --i) {
    if (p[u][i] != p[first][i])
      max_weight = max(max(max_weight, max_edge[u][i]), max_edge[first][i]),
      u = p[u][i], first = p[first][i];
  }
  max_weight = max(max_weight, max_edge[u][0]);
  max_weight = max(max_weight, max_edge[first][0]);
  u = p[u][0];
  return make_pair(u, max_weight);
}
long long res[maxn] = {};
void solve() {
  p[1][0] = 1;
  dfs(1);
  for (edge x : e) {
    if (x.pick) {
      res[x.id] = mstsum;
      continue;
    }
    auto k = lca(x.u, x.first);
    res[x.id] = mstsum - k.second + x.second;
  }
  for (int i = 1; i <= m; ++i) cout << res[i] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  clock_t entime = clock();
}

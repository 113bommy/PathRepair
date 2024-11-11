#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int LG = 20;
const int INF = 1e9 + 7;
int par[N][LG];
pair<int, int> mx[N][LG];
int from[N], to[N], cost[N], num[N], ind[N];
vector<int> adj[N];
int d[N];
bool mark[N];
void dfs(int v, int p) {
  for (auto x : adj[v]) {
    int u = from[x] ^ to[x] ^ v;
    if (u != p) {
      d[u] = d[v] + 1;
      par[u][0] = v;
      mx[u][0] = {num[x], x};
      for (int i = 1; i < LG; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
      }
      dfs(u, v);
    }
  }
}
int dad[N];
int root(int v) { return dad[v] == -1 ? v : dad[v] = root(dad[v]); }
bool merge(int v, int u) {
  v = root(v);
  u = root(u);
  if (v == u) return false;
  dad[v] = u;
  return true;
}
bool cmp(int a, int b) { return num[a] < num[b]; }
pair<int, pair<int, int> > get_par(int v, int a) {
  pair<int, int> res = {-INF, -INF};
  for (int i = 0; i < LG; i++)
    if ((a >> i) & 1) {
      res = max(res, mx[v][i]);
      v = par[v][i];
    }
  return {v, res};
}
int lca(int v, int u) {
  if (d[v] < d[u]) swap(u, v);
  v = get_par(v, d[v] - d[u]).first;
  if (v == u) return v;
  for (int i = LG - 1; i >= 0; i--)
    if (par[v][i] != par[u][i]) v = par[v][i], u = par[u][i];
  return par[v][0];
}
int main() {
  ios::sync_with_stdio(false);
  memset(dad, -1, sizeof dad);
  memset(mx, -63, sizeof mx);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> num[i];
  for (int i = 0; i < m; i++) cin >> cost[i];
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i];
    from[i]--, to[i]--;
  }
  int s;
  cin >> s;
  for (int i = 0; i < m; i++) ind[i] = i;
  sort(ind, ind + m, cmp);
  long long sum = 0;
  int mincost = INF;
  for (int i = 0; i < m; i++)
    if (merge(from[ind[i]], to[ind[i]])) {
      sum += num[ind[i]];
      mincost = min(mincost, cost[ind[i]]);
      adj[from[ind[i]]].push_back(ind[i]);
      adj[to[ind[i]]].push_back(ind[i]);
      mark[ind[i]] = true;
    }
  dfs(0, -1);
  long long ans = sum, rem = ind[0], add = ind[0];
  for (int i = 0; i < m; i++) {
    int up = lca(from[i], to[i]);
    auto res = max(get_par(from[i], d[from[i]] - d[up]).second,
                   get_par(to[i], d[to[i]] - d[up]).second);
    if (ans > sum - res.first + num[i] - s / cost[i]) {
      ans = sum - res.first + num[i] - s / cost[i];
      rem = res.second;
      add = i;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < m; i++)
    if (mark[i] && i != rem) cout << i + 1 << " " << num[i] << "\n";
  cout << add + 1 << " " << num[add] - s / cost[add] << "\n";
  return 0;
}

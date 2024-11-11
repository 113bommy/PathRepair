#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int LOG = 22;
int n, m, par[MAXN][LOG], v_ind[MAXN], T[MAXN], H[MAXN], D[MAXN];
bool C[MAXN];
vector<pair<int, int> > adj[MAXN];
pair<int, int> dp_down[MAXN], dp_up[MAXN];
vector<pair<int, int> > dp[MAXN][2];
void dfs(int v, int p) {
  par[v][0] = p;
  int ind = 0;
  for (pair<int, int> e : adj[v]) {
    int u = e.first, w = e.second;
    if (u == p) continue;
    H[u] = H[v] + 1;
    dfs(u, v);
    int val = dp_down[u].first + w;
    if (val > dp_down[v].first) {
      dp_down[v].first = val;
      dp_down[v].second = dp_down[u].second;
    } else if (val == dp_down[v].first)
      dp_down[u].second = v;
    dp[v][0].push_back({0, 0});
    dp[v][1].push_back({0, 0});
    if (ind == 0)
      dp[v][0][0] = {val, dp_down[u].second};
    else {
      dp[v][0][ind] = dp[v][0][ind - 1];
      if (val > dp[v][0][ind].first) {
        dp[v][0][ind].first = val;
        dp[v][0][ind].second = dp_down[u].second;
      } else if (val == dp[v][0][ind].first)
        dp[v][0][ind].second = v;
    }
    v_ind[u] = ind;
    ind++;
  }
  ind--;
  for (int i = adj[v].size() - 1; i >= 0; i--) {
    int u = adj[v][i].first, w = adj[v][i].second;
    if (u == p) continue;
    int val = dp_down[u].first + w;
    if (ind == dp[v][0].size() - 1)
      dp[v][1][ind] = {val, dp_down[u].second};
    else {
      dp[v][1][ind] = dp[v][1][ind + 1];
      if (val > dp[v][1][ind].first) {
        dp[v][1][ind].first = val;
        dp[v][1][ind].second = dp_down[u].second;
      } else if (val == dp[v][1][ind].first)
        dp[v][1][ind].second = v;
    }
    ind--;
  }
}
void dfs_up(int v, int p, int w) {
  if (p) {
    int ind = v_ind[v];
    dp_up[v] = max(make_pair(w + dp_up[p].first, dp_up[p].second), dp_up[v]);
    if (ind) {
      if (dp[p][0][ind - 1].first + w > dp_up[v].first) {
        dp_up[v].first = dp[p][0][ind - 1].first + w;
        dp_up[v].second = dp[p][0][ind - 1].second;
      } else if (dp[p][0][ind - 1].first + w == dp_up[v].first)
        dp_up[v].second = p;
    }
    if (ind < dp[p][1].size() - 1) {
      if (dp[p][1][ind + 1].first + w > dp_up[v].first) {
        dp_up[v].first = dp[p][1][ind + 1].first + w;
        dp_up[v].second = dp[p][1][ind + 1].second;
      } else if (dp[p][1][ind + 1].first + w == dp_up[v].first)
        dp_up[v].second = p;
    }
  }
  if (dp_down[v].first > dp_up[v].first)
    T[v] = dp_down[v].second;
  else if (dp_down[v].first < dp_up[v].first)
    T[v] = dp_up[v].second;
  else
    T[v] = v;
  for (pair<int, int> e : adj[v])
    if (e.first != p) dfs_up(e.first, v, e.second);
}
inline int Par(int v, int k) {
  for (int i = LOG - 1; i >= 0; i--)
    if (k & (1 << i)) v = par[v][i];
  return v;
}
inline int LCA(int v, int u) {
  if (H[v] < H[u]) swap(u, v);
  v = Par(v, H[v] - H[u]);
  if (v == u) return v;
  for (int i = LOG - 1; i >= 0; i--)
    if (par[v][i] != par[u][i]) v = par[v][i], u = par[u][i];
  return par[v][0];
}
void MajikalDfs(int v, int p) {
  for (pair<int, int> e : adj[v]) {
    int u = e.first;
    if (u == p) continue;
    MajikalDfs(u, v);
    D[v] += D[u];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  fill(dp_down, dp_down + MAXN, make_pair(-INF, -1));
  fill(dp_up, dp_up + MAXN, make_pair(-INF, -1));
  for (int i = 1; i <= m; i++) {
    int v;
    cin >> v;
    C[v] = true;
    dp_down[v] = dp_up[v] = {0, v};
  }
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dfs(1, 0);
  dfs_up(1, 0, 0);
  for (int i = 1; i < LOG; i++)
    for (int v = 1; v <= n; v++) par[v][i] = par[par[v][i - 1]][i - 1];
  for (int i = 1; i <= n; i++) {
    if (C[i]) {
      int u = i, v = T[i], lca = LCA(u, v);
      D[u]++;
      D[v]++;
      D[lca]--;
      D[par[lca][0]]--;
    }
  }
  MajikalDfs(1, 0);
  int mx = -1, mx_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (C[i]) continue;
    if (D[i] > mx)
      mx = D[i], mx_cnt = 1;
    else if (D[i] == mx)
      mx_cnt++;
  }
  cout << mx << ' ' << mx_cnt << '\n';
  return 0;
}

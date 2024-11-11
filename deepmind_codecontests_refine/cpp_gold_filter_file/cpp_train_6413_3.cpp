#include <bits/stdc++.h>
using namespace std;
long long t, n, m, u, v, q, k;
const int N = 2e5 + 500;
const int LN = 20;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57;
long long arr[N];
string str, ss;
int to[N], from[N], id[N], p[N];
long long cost[N];
int find(int x) {
  if (x == p[x])
    return x;
  else
    return p[x] = find(p[x]);
}
bool unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    p[x] = y;
    return true;
  } else
    return false;
}
bool mst[N];
int L[N][LN], D[N], P[N][LN];
vector<int> adj[N], idx[N];
vector<long long> cst[N];
inline void _pre() {
  for (int j = 1; j < LN; ++j) {
    for (int i = 1; i <= n; ++i) {
      L[i][j] = L[L[i][j - 1]][j - 1];
      P[i][j] = max(P[i][j - 1], P[L[i][j - 1]][j - 1]);
    }
  }
}
inline int lca(int u, int v) {
  if (D[u] > D[v]) swap(u, v);
  int diff = D[v] - D[u];
  for (int i = 0; i < LN; ++i) {
    if (diff & (1 << i)) v = L[v][i];
  }
  if (u == v) return u;
  for (int i = LN - 1; i >= 0; --i) {
    if (L[u][i] != L[v][i]) {
      u = L[u][i];
      v = L[v][i];
    }
  }
  return L[u][0];
}
int query(int u, int v) {
  int x = lca(u, v);
  int d1 = D[u] - D[x];
  int d2 = D[v] - D[x];
  int ret = 0;
  for (int i = 0; i < LN; ++i) {
    if (d1 & (1 << i)) {
      ret = max(ret, P[u][i]);
      u = L[u][i];
    }
    if (d2 & (1 << i)) {
      ret = max(ret, P[v][i]);
      v = L[v][i];
    }
  }
  return ret - 1;
}
void dfs(int v, int p, int d) {
  L[v][0] = p;
  D[v] = d;
  for (int i = 0; i < adj[v].size(); ++i) {
    int u = adj[v][i];
    if (u != p)
      dfs(u, v, d + 1);
    else
      P[v][0] = cst[v][i];
  }
}
set<pair<int, int> > f[N];
int sol[N];
void solve(int v, int p) {
  for (int u : adj[v]) {
    if (u == p) continue;
    solve(u, v);
    if (f[u].size() > f[v].size()) f[v].swap(f[u]);
    for (auto j : f[u]) {
      if (f[v].find(j) != f[v].end())
        f[v].erase(j);
      else
        f[v].insert(j);
    }
  }
  int j = -1;
  for (int i = 0; i < adj[v].size(); ++i) {
    int u = adj[v][i];
    if (u == p) {
      j = idx[v][i];
    }
  }
  if (j != -1 && f[v].size() > 0) {
    sol[j] = (*f[v].begin()).first - 1;
  } else if (j != -1)
    sol[j] = -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) p[i] = i;
  for (int i = 1; i <= m; ++i) {
    cin >> to[i] >> from[i] >> cost[i];
    id[i] = i;
  }
  sort(id + 1, id + 1 + m, [](int a, int b) { return cost[a] < cost[b]; });
  for (int ii = 1; ii <= m; ++ii) {
    int i = id[ii];
    mst[i] = unite(to[i], from[i]);
    if (mst[i]) {
      adj[to[i]].push_back(from[i]);
      adj[from[i]].push_back(to[i]);
      cst[to[i]].push_back(cost[i]);
      cst[from[i]].push_back(cost[i]);
      idx[from[i]].push_back(i);
      idx[to[i]].push_back(i);
    }
  }
  dfs(1, 0, 0);
  _pre();
  for (int ii = 1; ii <= m; ++ii) {
    int i = ii;
    if (mst[i]) continue;
    sol[i] = query(to[i], from[i]);
    f[to[i]].insert(make_pair(cost[i], i));
    f[from[i]].insert(make_pair(cost[i], i));
  }
  solve(1, 0);
  for (int i = 1; i <= m; ++i) {
    cout << sol[i] << " ";
  }
}

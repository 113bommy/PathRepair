#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, m, k, tmp;
bool v[MAXN], dsuV[MAXN], vis[MAXN], is[MAXN];
long long c[MAXN], weights[MAXN], dsuC[MAXN], ans[MAXN], dp[MAXN];
vector<vector<pair<int, long long>>> g(MAXN), tr(MAXN);
int dsu[MAXN], sz[MAXN], highest[MAXN], dpth[MAXN], par[MAXN], in[MAXN],
    rep[MAXN];
set<int> tree;
int getp(int first) {
  return dsu[first] == first ? first : dsu[first] = getp(dsu[first]);
}
void connect(int u, int v) {
  u = getp(u), v = getp(v);
  if (u == v) return;
  if (sz[u] < sz[v]) swap(u, v);
  sz[u] += sz[v];
  dsu[v] = u;
  if (dpth[highest[v]] < dpth[highest[u]]) highest[u] = highest[v];
}
void dfs(int u, int pr, int d = 0) {
  vis[u] = 1;
  par[u] = pr;
  dpth[u] = d;
  for (auto v : g[u]) {
    if (!vis[v.first])
      dfs(v.first, u, d + 1);
    else if (v.first != pr) {
      int first = u;
      while (dpth[first] > dpth[v.first]) {
        int nxt = highest[getp(par[first])];
        connect(first, nxt);
        first = nxt;
      }
    }
  }
}
void dfs2(int u) {
  vis[u] = 1;
  dsuV[in[u]] |= v[u];
  dsuC[in[u]] += c[u];
  for (auto v : g[u]) {
    if (vis[v.first]) continue;
    if (in[u] == in[v.first])
      dfs2(v.first);
    else
      tr[in[u]].push_back({in[v.first], v.second}),
          tr[in[v.first]].push_back({in[u], v.second});
  }
}
void dfs3(int u, int pr = -1) {
  is[u] = dsuV[u];
  for (auto v : tr[u]) {
    if (v.first == pr) continue;
    dfs3(v.first, u);
    is[u] |= is[v.first];
  }
  for (auto v : tr[u]) {
    if (v.first == pr) continue;
    if (!is[v.first]) {
      dsuC[u] += dsuC[v.first];
      connect(rep[u], rep[v.first]);
    }
  }
}
void dfs4(int u, int pr = -1) {
  for (auto v : tr[u]) {
    if (!is[v.first] || v.first == pr) continue;
    dfs4(v.first, u);
    dp[u] += max(0LL, dp[v.first] + dsuC[v.first] - v.second);
  }
}
void dfs5(int u, int pr = -1) {
  for (auto v : tr[u]) {
    if (!is[v.first] || v.first == pr) continue;
    int A = dp[u], B = dp[v.first];
    dp[u] -= max(0LL, dp[v.first] + dsuC[v.first] - v.second);
    dp[v.first] += max(0LL, dp[u] + dsuC[u] - v.second);
    ans[getp(rep[v.first])] = dp[v.first] + dsuC[v.first];
    dfs5(v.first, u);
    dp[u] = A, dp[v.first] = B;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> tmp;
    tmp--;
    v[tmp] = 1;
  }
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < m; i++) cin >> weights[i];
  for (int i = 0; i < m; i++) {
    int first, second;
    cin >> first >> second;
    first--;
    second--;
    g[first].push_back({second, weights[i]});
    g[second].push_back({first, weights[i]});
  }
  for (int i = 0; i < n; i++) dsu[i] = i, sz[i] = 1, highest[i] = i;
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    int dad = getp(i);
    if (tree.count(dad) == 0) {
      in[dad] = in[i] = (int)(tree.size());
      rep[in[dad]] = dad;
      tree.insert(dad);
    } else {
      in[i] = in[dad];
    }
  }
  for (int i = 0; i < n; i++) vis[i] = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    dfs2(i);
  }
  int X = -1;
  for (int i = 0; i < (int)(tree.size()); i++) {
    if (dsuV[i]) {
      X = i;
      break;
    }
  }
  assert(X != -1);
  dfs3(X);
  dfs4(X);
  ans[getp(rep[X])] = dp[X] + dsuC[X];
  dfs5(X);
  for (int i = 0; i < n; i++) {
    cout << ans[getp(i)] << ' ';
  }
  return 0;
}

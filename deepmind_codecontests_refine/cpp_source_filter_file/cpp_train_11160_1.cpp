#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
const int maxn = 5e5 + 10, N = 1e5, base = 97, mod = 1e9 + 7, INF = 1e9,
          lg = 18;
int n, cnt, ans = 1, a[maxn], h[maxn], par[maxn];
vector<int> edges[maxn];
vector<pair<int, int> > rules[maxn];
int after[maxn], before[maxn], mark[maxn];
void dfs(int v) {
  for (auto u : edges[v]) {
    if (u != par[v]) {
      par[u] = v;
      h[u] = h[v] + 1;
      dfs(u);
    }
  }
}
inline int lca(int u, int v, vector<int> &from_u, vector<int> &to_v) {
  while (h[u] > h[v]) {
    from_u.push_back(u);
    u = par[u];
  }
  while (h[v] > h[u]) {
    to_v.push_back(v);
    v = par[v];
  }
  while (u != v) {
    from_u.push_back(u);
    u = par[u];
    to_v.push_back(v);
    v = par[v];
  }
  return v;
}
inline void check(int u, int v) {
  if (u == v) {
    cout << 0 << endl;
    exit(0);
  }
  vector<int> from_u, to_v;
  from_u.push_back(n + 1);
  to_v.push_back(n + 2);
  u = v = lca(u, v, from_u, to_v);
  from_u.push_back(u);
  for (int i = to_v.size() - 1; i >= 0; --i) {
    from_u.push_back(to_v[i]);
  }
  for (int i = 1; i + 1 < from_u.size(); ++i) {
    rules[from_u[i]].push_back({from_u[i - 1], from_u[i + 1]});
  }
  cnt += from_u.size() - 3;
  if (cnt > 2 * n - 2) {
    cout << 0 << endl;
    exit(0);
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    edges[i].push_back(n + 1);
    edges[i].push_back(n + 2);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    if (a[i]) {
      check(i, a[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto cond : rules[i]) {
      int u = cond.first, v = cond.second;
      if ((after[u] && after[u] != v) || (before[v] && before[v] != u)) {
        cout << 0 << endl;
        return 0;
      }
      after[u] = v;
      before[v] = u;
    }
    for (auto u : edges[i]) {
      if (!mark[u]) {
        mark[u] = 1;
        int curr = after[u];
        while (curr) {
          if (curr == u) {
            cout << 0 << endl;
            return 0;
          }
          if (mark[curr]) {
            break;
          }
          mark[curr] = 1;
          curr = after[curr];
        }
      }
    }
    if (after[n + 2]) {
      int curr = n, tot = 1;
      while (curr) {
        if (curr == n + 2) {
          break;
        }
        tot++;
        curr = after[curr];
      }
      if (curr == n + 2 && tot < edges[i].size()) {
        cout << 0 << endl;
        return 0;
      }
    }
    int counter = 0;
    for (auto u : edges[i]) {
      if (u < n && !before[u]) {
        counter++;
      }
    }
    if (before[n + 2]) {
      counter--;
    }
    for (int j = 1; j <= counter; ++j) {
      ans = (1ll * ans * j) % mod;
    }
    for (auto u : edges[i]) {
      after[u] = before[u] = mark[u] = 0;
    }
  }
  cout << ans << endl;
}

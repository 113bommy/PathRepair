#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline int len(const T &a) {
  return a.size();
}
struct edge {
  int v, u, w;
};
constexpr int maxn = 1e6 + 10;
int n, m;
edge es[maxn];
vector<int> g[maxn], ig[maxn];
vector<int> order;
int gp[maxn], mark[maxn];
void dfs(int v) {
  mark[v] = 1;
  for (auto &u : g[v]) {
    if (!mark[u]) {
      dfs(u);
    }
  }
  order.push_back(v);
}
void sfd(int v, int root) {
  gp[v] = root;
  mark[v] = 2;
  for (auto &u : ig[v]) {
    if (mark[u] != 2) {
      sfd(u, root);
    }
  }
}
void scc() {
  for (int i = 0; i < n; ++i) {
    if (!mark[i]) {
      dfs(i);
    }
  }
  reverse(order.begin(), order.end());
  for (auto &v : order) {
    if (mark[v] != 2) {
      sfd(v, v);
    }
  }
}
vector<pair<int, int>> ng[maxn];
long long val[maxn], dp[maxn];
void run_dp(int v) {
  mark[v] = 1;
  for (auto &u : ng[v]) {
    if (mark[u.first] != 2) {
      run_dp(u.first);
    }
    dp[v] = max(dp[v], dp[u.first] + u.second);
  }
  mark[v] = 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    g[--v].push_back(--u);
    ig[u].push_back(v);
    es[i] = {v, u, w};
  }
  scc();
  for (int i = 0; i < m; ++i) {
    if (gp[es[i].v] == gp[es[i].u]) {
      int low = 0, high = 1e5;
      while (high - low > 0) {
        int mid = (low + high + 1) >> 1;
        if ((1ll * mid * (mid + 1)) / 2 < es[i].w) {
          low = mid;
        } else {
          high = mid - 1;
        }
      }
      val[gp[es[i].v]] +=
          1ll * (low + 1) * es[i].w - (1ll * low * (low + 1) * (low + 2)) / 6;
    } else {
      ng[gp[es[i].v]].push_back({gp[es[i].u], es[i].w});
    }
  }
  for (int i = 0; i < n; ++i) {
    dp[i] = val[i];
  }
  int start;
  cin >> start;
  --start;
  memset(mark, 0, sizeof(mark));
  run_dp(gp[start]);
  cout << dp[gp[start]];
}

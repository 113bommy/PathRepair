#include <bits/stdc++.h>
using namespace std;
const int N = 202020;
int n, k, tim, rt;
int a[N];
vector<int> g[N];
int f[N];
int vis[N], ban[N], sz[N], sum[N], ma[N][2];
int pban[N], pf[N];
void dfs(int u, int fa) {
  vis[u] = tim;
  ban[u] = sum[u] = ma[u][0] = ma[u][1] = 0;
  sz[u] = 1;
  for (auto v : g[u])
    if (v != fa) {
      if (a[v] >= tim) {
        dfs(v, u);
        sz[u] += sz[v];
        if (ban[v]) {
          ban[u]++;
          if (ma[u][0] < f[v]) {
            ma[u][1] = ma[u][0];
            ma[u][0] = f[v];
          } else {
            ma[u][1] = max(ma[u][1], f[v]);
          }
        } else {
          sum[u] += sz[v];
        }
      } else {
        ban[u]++;
      }
    }
  f[u] = sum[u] + ma[u][0] + 1;
}
void dfs2(int u, int fa) {
  for (auto v : g[u])
    if (v != fa && a[v] >= tim) {
      pban[u] = ban[u] - (ban[v] > 0) + (pban[fa] > 0);
      pf[u] = sum[u];
      if (!ban[v]) pf[u] -= sz[v];
      if (!pban[fa]) pf[u] += sz[rt] - sz[u];
      int t = ban[v] ? (f[v] == ma[u][0] ? ma[u][1] : ma[u][0]) : ma[u][0];
      if (pban[fa]) t = max(t, pf[fa]);
      pf[u] += t;
      f[v] = sum[v] + 1;
      if (pban[u]) {
        f[v] += max(ma[v][0], pf[u]);
      } else {
        f[v] += sz[rt] - sz[v] + ma[v][0];
      }
      dfs2(v, u);
    }
}
bool check(int x) {
  tim = x;
  for (int i = (1); i < (n + 1); i++)
    if (a[i] >= tim && vis[i] != tim) {
      dfs(i, 0);
      rt = i;
      dfs2(i, 0);
    }
  for (int i = (1); i < (n + 1); i++)
    if (a[i] >= tim && f[i] >= k) return 1;
  return 0;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> k;
  for (int i = (1); i < (n + 1); i++) cin >> a[i];
  for (int i = (1); i < (n); i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  int l = 1, r = 1e6, ans = 1e6;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << "\n";
  return 0;
}

#include <bits/stdc++.h>
const int N = 1005;
void work(int u);
bool dfs(int u, long long now);
int a[N], b[N];
std::vector<int> G[N];
int fa[N];
bool vis[N];
long long now;
int cnt;
int n, m;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; ++i) scanf("%d", a + i);
    for (int i = 2; i <= n; ++i) scanf("%d", b + i);
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      G[u].push_back(v), G[v].push_back(u);
    }
    vis[1] = true;
    int L = 0, R = 1e9;
    int ans = 0;
    while (L <= R) {
      int mid = (L + R) >> 1;
      for (int i = 2; i <= n; ++i) vis[i] = false;
      now = mid;
      cnt = 1;
      while (cnt < n) {
        for (int i = 1; i <= n; ++i) fa[i] = 0;
        bool flag = false;
        for (int i = 1; i <= n; ++i) {
          if (vis[i] && dfs(i, now)) {
            flag = true;
            break;
          }
        }
        if (!flag) break;
      }
      if (cnt == n) {
        ans = mid;
        R = mid - 1;
      } else {
        L = mid + 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
void work(int u) {
  while (!vis[u]) {
    vis[u] = true;
    now += b[u];
    ++cnt;
    u = fa[u];
  }
}
bool dfs(int u, long long now) {
  for (int v : G[u]) {
    if (v == fa[u] || now <= a[v]) continue;
    if (!vis[u] && vis[v]) {
      work(u);
      return true;
    }
    if (vis[v]) continue;
    if (fa[v]) {
      work(v), work(u);
      return true;
    }
    fa[v] = u;
    if (dfs(v, now + b[v])) return true;
  }
  return false;
}

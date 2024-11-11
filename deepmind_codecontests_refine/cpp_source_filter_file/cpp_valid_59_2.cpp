#include <bits/stdc++.h>
using namespace std;
const int M = 1005;
const int inf = 0x3f3f3f3f;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int T, n, m, ans, a[M], b[M], vis[M], cur[M], pre[M];
vector<int> g[M];
int path(int x) {
  if (vis[x]) return 0;
  vis[x] = 1;
  return min(inf, path(pre[x]) + b[x]);
}
int dfs(int u, int x) {
  x = min(inf, x + b[u]);
  cur[u] = 1;
  for (auto v : g[u]) {
    if (v == pre[u] || x <= a[v]) continue;
    if (cur[v]) return path(u) + path(v);
    pre[v] = u;
    int f = dfs(v, x);
    if (f != -1) return f;
  }
  return -1;
}
int check(int x) {
  int f = 0;
  memset(vis, 0, sizeof vis);
  vis[1] = 1;
  while (f != -1) {
    f = -1;
    memcpy(cur, vis, sizeof cur);
    for (int u = 1; u <= n && f == -1; u++)
      if (vis[u])
        for (auto v : g[u])
          if (!vis[v] && x > a[v]) {
            pre[v] = u;
            f = dfs(v, x);
            if (f != -1) break;
          }
    if (f == -1) {
      for (int i = 1; i <= n; i++)
        if (!vis[i]) return 0;
      return 1;
    }
    x = min(inf, x + f);
  }
  return 0;
}
void dich(int l, int r) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  if (check(mid)) {
    ans = mid;
    dich(l, mid - 1);
  } else
    dich(mid + 1, r);
}
void work() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 2; i <= n; i++) a[i] = read();
  for (int i = 2; i <= n; i++) b[i] = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dich(0, 1e9);
  printf("%d\n", ans);
}
signed main() {
  T = read();
  while (T--) work();
}

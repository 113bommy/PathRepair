#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int tot = 0;
int head[maxn], vis[maxn], c[maxn];
int d[maxn];
struct edge {
  int v, next;
} e[maxn * 2];
void add(int u, int v) {
  e[tot].v = v;
  e[tot].next = head[u];
  head[u] = tot++;
}
void dfs(int x) {
  vis[x] = 1;
  int y;
  for (int i = head[x]; i != -1; i = e[i].next) {
    y = e[i].v;
    if (!vis[y]) dfs(y);
  }
}
int main() {
  int n, m, i, u, v;
  long long cnt = 0;
  cin >> n >> m;
  memset(head, -1, sizeof(head));
  memset(d, 0, sizeof(d));
  memset(vis, 0, sizeof(vis));
  memset(c, 0, sizeof(c));
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
    if (u == v) {
      cnt++;
      c[u]++;
      continue;
    }
    d[u]++;
    d[v]++;
  }
  for (i = 1; i <= n; i++)
    if (d[i]) {
      dfs(i);
      break;
    }
  for (i = 1; i <= n; i++) {
    if (!vis[i])
      if (c[i] != 0 || d[i] != 0) {
        cout << 0 << endl;
        return 0;
      }
  }
  long long ans = 0;
  ans += cnt * (cnt - 1) / 2;
  ans += cnt * (m - cnt);
  for (i = 1; i <= n; i++) {
    if (d[i] >= 2) ans += d[i] * (d[i] - 1) / 2;
  }
  cout << ans << endl;
}

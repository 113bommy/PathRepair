#include <bits/stdc++.h>
using namespace std;
int head[1005], vis[1005], Vis[1005], d[1005], q[1005], a[1005];
int i, j, u, v, l, r, n, m, ans, cnt, num, Max, inf = 1e9;
struct ff {
  int to, nxt;
} e[200005];
void add(int u, int v) {
  e[++cnt].to = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
void dfs(int now) {
  a[++num] = now;
  for (int i = head[now]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (!vis[v]) vis[v] = vis[now] ^ 1, dfs(v);
    if (vis[v] == vis[now]) {
      puts("-1");
      exit(0);
    }
  }
}
void bfs(int x) {
  memset(Vis, 0, sizeof(vis));
  memset(d, 63, sizeof(d));
  d[x] = 0;
  l = r = 1;
  q[1] = x;
  Vis[x] = 1;
  while (l <= r) {
    for (int i = head[q[l]]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (!Vis[v]) {
        if (d[q[l]] + 1 < d[v]) d[v] = d[q[l]] + 1;
        q[++r] = v;
        Vis[v] = 1;
      }
    }
    l++;
  }
  Max = max(Max, d[q[r]]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    add(u, v), add(v, u);
  }
  for (i = 1; i <= n; i++)
    if (!vis[i]) {
      num = 0;
      vis[i] = 2, dfs(i);
      Max = 0;
      for (j = 1; j <= num; j++) bfs(a[j]);
      ans += Max;
    }
  printf("%d\n", ans);
  return 0;
}

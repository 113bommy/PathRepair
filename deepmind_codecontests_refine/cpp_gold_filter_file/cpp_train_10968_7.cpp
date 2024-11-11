#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n, m, size, head[maxn], dis[maxn], cnt[maxn], x[maxn], y[maxn],
    val[5005][5005];
bool vis[maxn], can[maxn];
struct node {
  int v, nxt;
} e[maxn];
void add(int u, int v) {
  e[++size].v = v;
  e[size].nxt = head[u];
  head[u] = size;
}
bool spfa() {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(0);
  dis[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = 1; i <= n; ++i) {
      if (val[u][i] == 0x3f3f3f3f) continue;
      int v = i, w = val[u][i];
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;
        if (cnt[v] > n) return 1;
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return 0;
}
bool dfs(int u) {
  if (u == n || can[u]) return 1;
  vis[u] = 1;
  bool ok = 0;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (!vis[v])
      if (dfs(v)) {
        val[u][v] = 2;
        val[v][u] = -1;
        ok = 1;
      }
  }
  vis[u] = 0;
  return can[u] = ok;
}
int main() {
  memset(val, 0x3f, sizeof(val));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    add(x[i], y[i]);
  }
  for (int i = 1; i <= n; ++i) val[0][i] = 0;
  if (!dfs(1) || spfa())
    return puts("No"), 0;
  else
    puts("Yes");
  for (int i = 1; i <= m; ++i) {
    int d = abs(dis[y[i]] - dis[x[i]]);
    if (d > 0 && d <= 2)
      printf("%d\n", d);
    else
      puts("1");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
int n, m, k, cnt, pos[10010], a[10010], b[10010], f[1 << 25], dis[10010],
    g[30][30];
bool vis[10010];
queue<int> q;
inline void bfs(int x, int id) {
  memset(dis, 0x3f3f3f3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  q.push(x);
  vis[x] = 1;
  dis[x] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 1; i <= m; i++) {
      int v = a[i];
      if (u + v <= n && !vis[u + v]) {
        dis[u + v] = dis[u] + 1;
        vis[u + v] = 1;
        q.push(u + v);
      }
      if (u - v >= 1 && !vis[u - v]) {
        dis[u - v] = dis[u] + 1;
        vis[u - v] = 1;
        q.push(u - v);
      }
    }
  }
  for (int i = 1; i <= cnt; i++)
    if (vis[b[i]])
      g[id][i] = dis[b[i]];
    else
      g[id][i] = inf;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1, x; i <= k; i++) scanf("%d", &x), pos[x] = 1;
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  n++;
  for (int i = n; i >= 1; i--) pos[i] ^= pos[i - 1];
  for (int i = 1; i <= n; i++)
    if (pos[i]) {
      pos[i] = ++cnt;
      b[cnt] = i;
    }
  for (int i = 1; i <= n; i++)
    if (pos[i]) bfs(i, pos[i]);
  for (int i = 1; i < (1 << cnt); i++) f[i] = inf;
  for (int i = 0, k; i < (1 << cnt); i++) {
    for (int j = 1; j <= cnt; j++)
      if ((1 << j - 1) & i) {
        k = j;
        break;
      }
    for (int j = 1; j <= cnt; j++)
      if ((1 << j - 1) & i)
        f[i] = min(f[i], f[i ^ (1 << k - 1) ^ (1 << j - 1)] + g[k][j]);
  }
  printf("%d", f[(1 << cnt) - 1] == inf ? -1 : f[(1 << cnt) - 1]);
  return 0;
}

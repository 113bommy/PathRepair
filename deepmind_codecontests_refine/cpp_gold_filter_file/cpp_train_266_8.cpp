#include <bits/stdc++.h>
const int MAXN = 10010;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
std::queue<int> q;
int dist[25][25], f[1 << 25];
int n, k, m, cnt, a[MAXN], len[MAXN], node[MAXN], dis[MAXN];
inline int read() {
  int X = 0, flag = 0;
  char ch = 0;
  while (!isdigit(ch)) flag |= ch == '-', ch = getchar();
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return flag ? -X : X;
}
inline void bfs(int x, int pos) {
  memset(dis, INF, sizeof(dis));
  memset(vis, false, sizeof(vis));
  q.push(x), vis[x] = true, dis[x] = 0;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (int i = 1; i <= m; i++) {
      int tmp = len[i];
      if ((x + tmp) <= n && !vis[x + tmp]) {
        vis[x + tmp] = 1;
        dis[x + tmp] = dis[x] + 1;
        q.push(x + tmp);
      }
      if ((x - tmp) >= 1 && !vis[x - tmp]) {
        vis[x - tmp] = 1;
        dis[x - tmp] = dis[x] + 1;
        q.push(x - tmp);
      }
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (vis[node[i]])
      dist[pos][i] = dis[node[i]];
    else
      dist[pos][i] = INF;
  }
}
inline void dp() {
  for (int i = 1; i < (1 << cnt); i++) f[i] = INF;
  for (int i = 0, j; i < (1 << cnt); i++) {
    for (int k = 1; k <= cnt; k++)
      if ((1 << (k - 1)) & i) {
        j = k;
        break;
      }
    for (int k = 1; k <= cnt; k++)
      if ((1 << (k - 1)) & i)
        f[i] =
            std::min(f[i], f[i ^ (1 << (j - 1)) ^ (1 << (k - 1))] + dist[j][k]);
  }
}
signed main() {
  n = read(), k = read(), m = read();
  for (int i = 1; i <= k; i++) a[read()] = 1;
  for (int i = 1; i <= m; i++) len[i] = read();
  n++;
  for (int i = n; i >= 1; i--) a[i] ^= a[i - 1];
  for (int i = 1; i <= n; i++)
    if (a[i]) a[i] = ++cnt, node[cnt] = i;
  for (int i = 1; i <= n; i++)
    if (a[i]) bfs(i, a[i]);
  dp();
  if (f[(1 << cnt) - 1] == INF)
    printf("-1\n");
  else
    printf("%d\n", f[(1 << cnt) - 1]);
  return 0;
}

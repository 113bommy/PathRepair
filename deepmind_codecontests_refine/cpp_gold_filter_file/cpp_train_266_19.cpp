#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long llINF = 1e18;
const int MAXN = 22;
const int MAXM = 1 << MAXN;
const int MAXL = 2e4 + 5;
int n, k, m, tot;
int pos[MAXN], dis[MAXL], cost[MAXN][MAXN], a[MAXL], len[105], vis[MAXL],
    f[MAXM];
queue<int> q;
void bfs(int s) {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  dis[pos[s]] = 0;
  vis[pos[s]] = 1;
  q.push(pos[s]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 1; i <= m; i++) {
      int v1 = u + len[i], v2 = u - len[i];
      if (v1 <= n && !vis[v1]) {
        dis[v1] = dis[u] + 1;
        vis[v1] = 1;
        q.push(v1);
      }
      if (v2 >= 0 && !vis[v2]) {
        dis[v2] = dis[u] + 1;
        vis[v2] = 1;
        q.push(v2);
      }
    }
  }
  for (int i = 1; i <= tot; i++) cost[s][i] = dis[pos[i]];
}
void checkmin(int &x, int y) {
  if (x > y) x = y;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1, x; i <= k; i++) {
    scanf("%d", &x);
    a[x] = 1;
  }
  for (int i = 1; i <= m; i++) scanf("%d", &len[i]);
  for (int i = 0; i <= n; i++) a[i] ^= a[i + 1];
  for (int i = 0; i <= n; i++) {
    if (a[i]) pos[++tot] = i;
  }
  for (int i = 1; i <= tot; i++) bfs(i);
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  int maxState = (1 << tot) - 1;
  for (int S = 0; S <= maxState; S++) {
    for (int i = 1; i <= tot; i++) {
      if (S & (1 << (i - 1))) continue;
      for (int j = i + 1; j <= tot; j++) {
        if (S & (1 << (j - 1))) continue;
        checkmin(f[S | (1 << (i - 1)) | (1 << (j - 1))], f[S] + cost[i][j]);
      }
    }
  }
  printf("%d\n", (f[maxState] >= INF ? -1 : f[maxState]));
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 51, maxv = 100100, maxe = 1001000;
int n, m, d[maxn], ans[maxn][maxn], S, T, vtot;
int head[maxv], nxt[maxe << 1], ver[maxe << 1], flow[maxe << 1],
    cost[maxe << 1], tot = 1;
inline void addedge(int a, int b, int c, int d) {
  nxt[++tot] = head[a];
  ver[tot] = b;
  flow[tot] = c;
  cost[tot] = d;
  head[a] = tot;
  nxt[++tot] = head[b];
  ver[tot] = a;
  flow[tot] = 0;
  cost[tot] = -d;
  head[b] = tot;
}
int dis[maxv], lst[maxv], lstedge[maxv], inq[maxv], fl[maxv];
queue<int> q;
inline bool spfa() {
  for (int i = 1; i <= T; i++) dis[i] = 1e9, inq[i] = 0, lst[i] = 0;
  dis[S] = 0;
  while (q.size()) q.pop();
  q.push(S);
  dis[S] = 0;
  fl[S] = 1e9;
  while (q.size()) {
    int x = q.front();
    q.pop();
    inq[x] = 0;
    for (int i = head[x]; i; i = nxt[i]) {
      int y = ver[i];
      if (flow[i] == 0 || dis[y] <= dis[x] + cost[i]) continue;
      fl[y] = min(fl[x], flow[i]);
      dis[y] = dis[x] + cost[i];
      lst[y] = x;
      lstedge[y] = i;
      if (!inq[y]) q.push(y), inq[y] = 1;
    }
  }
  return dis[T] < 1e9;
}
inline void bao() {
  int x = T, f = fl[x];
  while (x != S) {
    int l = lstedge[x];
    flow[l] -= f;
    flow[l ^ 1] += f;
    x = lst[x];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  memset(ans, -1, sizeof(ans));
  for (int i = 1, a, b; i <= m; i++)
    scanf("%d%d", &a, &b), ans[a][b] = 1, ans[b][a] = 0, d[a]++;
  S = n * (n - 1) / 2 - m + n + 1, T = n * (n - 1) / 2 - m + n + 2;
  for (int i = 1; i <= n; i++) ans[i][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (ans[i][j] == -1) {
        vtot++;
        addedge(S, vtot, 1, 0);
        addedge(vtot, i + n * (n - 1) / 2 - m, 1, 0);
        addedge(vtot, j + n * (n - 1) / 2 - m, 1, 0);
      }
  for (int i = 1; i <= n; i++)
    for (int j = d[i] + 1; j <= n; j++)
      addedge(i + n * (n - 1) / 2 - m, T, 1, j - 1);
  while (spfa()) bao();
  vtot = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (ans[i][j] == -1) {
        vtot++;
        for (int bb = head[vtot]; bb; bb = nxt[bb])
          if (bb % 2 == 0 && flow[bb]) {
            if (ver[bb] - (n * (n - 1) / 2 - m) == i)
              ans[i][j] = 1, ans[j][i] = 0;
            else
              ans[i][j] = 0, ans[j][i] = 1;
          }
      }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) putchar(ans[i][j] + '0');
    putchar('\n');
  }
  return 0;
}

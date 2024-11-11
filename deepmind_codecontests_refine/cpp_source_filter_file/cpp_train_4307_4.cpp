#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, u, v, f[110], dis[110][110], q[110], head, tail, cnt[110][110];
bool flag[110], cut[110][110];
struct edge {
  int v;
  edge *nxt;
} pool[20100], *tp = pool, *fst1[110], *fst2[110];
void dfs(int x, int k) {
  flag[x] = 1;
  for (edge *i = fst1[x]; i; i = i->nxt)
    if (!flag[i->v] && dis[k][x] == dis[k][i->v] + 1) dfs(i->v, k);
}
void dfs(int x, int k, int w) {
  cnt[k][x] = -1;
  if (cut[k][x]) f[x] = min(f[x], w);
  for (edge *i = fst2[x]; i; i = i->nxt)
    if (dis[k][i->v] == dis[k][x] + 1 && cnt[k][i->v] != -1 && !--cnt[k][i->v])
      dfs(i->v, k, w);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  while (m--) {
    scanf("%d%d", &u, &v);
    *tp = (edge){v, fst1[u]}, fst1[u] = tp++;
    *tp = (edge){u, fst2[v]}, fst2[v] = tp++;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    memset(dis[i], 80, sizeof(dis[i]));
    dis[i][q[head = tail = 0] = v] = 0;
    for (int x; head <= tail; ++head)
      for (edge *j = fst2[x = q[head]]; j; j = j->nxt)
        if (dis[i][j->v] > n) dis[i][q[++tail] = j->v] = dis[i][x] + 1;
    memset(flag, 0, sizeof(flag)), dfs(u, i);
    for (int j = 1; j <= n; ++j) {
      if (!flag[j]) dis[i][j] = 1 << 30;
      for (edge *k = fst1[j]; k; k = k->nxt)
        cnt[i][j] += dis[i][j] == dis[i][k->v] + 1;
    }
    for (int j = 1; j <= n; ++j)
      if (dis[i][j] <= n) {
        cut[i][j] = 1;
        for (int k = 1; k <= n; ++k)
          cut[i][j] &= k == j || dis[i][k] != dis[i][j];
      }
  }
  memset(f, 80, sizeof(f)), f[t] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int k = 1; k <= n; ++k)
        if (f[k] == i - 1 && dis[j][k] <= n & cut[j][k]) dfs(k, j, i);
  printf("%d\n", f[s] <= n ? f[s] : -1);
  return 0;
}

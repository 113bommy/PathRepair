#include <bits/stdc++.h>
using namespace std;
const int N = 75, M = 20, T = 2e7;
int n, m, A, B, G[N][N], id[N], f[T], cnt, vis1[N], vis2[N], tot;
queue<int> q1, q2;
int dfs1(int u) {
  vis1[u] = 1;
  int res = 1;
  for (int i = 1; i <= n; ++i)
    if (G[u][i] == A && !vis1[i]) res += dfs1(i);
  return res;
}
void dfs2(int u) {
  vis2[u] = 1, id[u] = cnt;
  for (int i = 1; i <= n; ++i)
    if (G[u][i] == A && !vis2[i]) dfs2(i);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &A, &B);
  for (int i = 1, a, b, c; i <= m; ++i)
    scanf("%d%d%d", &a, &b, &c), G[a][b] = G[b][a] = c;
  for (int i = 1; i <= n; ++i)
    if (!vis1[i] && dfs1(i) > 3) dfs2(i), ++cnt;
  memset(vis1, 0, sizeof(vis1)), tot = cnt;
  for (int i = 1; i <= n; ++i)
    if (!vis1[i] && dfs1(i) < 4) dfs2(i), ++cnt;
  memset(f, 0x3f, sizeof(f)), f[((0) * n + (1) - 1)] = 0,
                                                 q1.push(((0) * n + (1) - 1)),
                                                 q2.push(((0) * n + (1) - 1));
  while (!q1.empty() || !q2.empty()) {
    int now, S, u;
    if (q1.empty())
      now = q2.front(), q2.pop();
    else if (q2.empty())
      now = q1.front(), q1.pop();
    else if (f[q1.front()] < f[q2.front()])
      now = q1.front(), q1.pop();
    else
      now = q2.front(), q2.pop();
    S = now / n, u = now % n + 1;
    for (int i = 1, v; i <= n; ++i) {
      if (!G[u][i] || (id[i] < tot && (S >> id[i] & 1)) ||
          (id[u] == id[i] && G[u][i] == B))
        continue;
      if (id[i] < tot && id[i] != id[u])
        v = ((S | 1 << id[u]) * n + (i)-1);
      else
        v = ((S)*n + (i)-1);
      if (f[v] > f[now] + G[u][i]) {
        f[v] = f[now] + G[u][i];
        if (G[u][i] == A)
          q1.push(v);
        else
          q2.push(v);
      }
    }
  }
  for (int i = 1, ans; i <= n; ++i) {
    ans = 2e9;
    for (int S = 0; S < 1 << tot; ++S) ans = min(ans, f[((S)*n + (i)-1)]);
    printf("%d ", ans);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1001, inf = 1 << 30;
int n, m, tot, sum;
int a[N], b[N];
int head[N], to[N], nxt[N];
int ans[N][N], flow[N], d[N], q[N], cap[N], cur[N];
void Add_Edge(int x, int y, int z) {
  to[tot] = y, nxt[tot] = head[x], cap[tot] = z, head[x] = tot++;
  to[tot] = x, nxt[tot] = head[y], cap[tot] = 0, head[y] = tot++;
}
bool Bfs(int S, int T) {
  int f, r, x, y;
  f = r = 0;
  q[++r] = T;
  for (int i = S; i <= T; i++) d[i] = inf;
  d[T] = 0;
  while (f < r) {
    x = q[++f];
    for (int i = head[x]; i != -1; i = nxt[i]) {
      y = to[i];
      if (flow[i ^ 1] == cap[i ^ 1] || d[y] != inf) continue;
      d[y] = d[x] + 1;
      q[++r] = y;
    }
  }
  return d[S] != inf;
}
int Dfs(int x, int T, int limit) {
  if (x == T) return limit;
  int sum = 0, y, tmp;
  for (int &i = cur[x]; i != -1; i = nxt[i]) {
    y = to[i];
    if (d[y] + 1 != d[x] || flow[i] == cap[i]) continue;
    if ((tmp = Dfs(y, T, min(limit, cap[i] - flow[i]))) != 0) {
      sum += tmp;
      limit -= tmp;
      flow[i] += tmp;
      flow[i ^ 1] -= tmp;
      if (!limit) break;
    }
  }
  return sum;
}
int Maxflow(int S, int T) {
  int flow = 0;
  while (Bfs(S, T)) {
    memcpy(cur, head, sizeof(head));
    flow += Dfs(S, T, inf);
  }
  return flow;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &m);
  int s = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), sum += a[i], Add_Edge(0, i, a[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &b[i]), s += b[i], Add_Edge(i, i + n, inf),
        Add_Edge(i + n, 2 * n + 1, b[i]);
  if (sum != s) {
    printf("NO\n");
    return 0;
  }
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    Add_Edge(x, y + n, inf);
    Add_Edge(y, x + n, inf);
  }
  if (Maxflow(0, 2 * n + 1) != sum)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 1; i <= n; i++)
      for (int j = head[i]; j != -1; j = nxt[j])
        if (to[j] > n) ans[i][to[j] - n] = flow[j];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < n; j++) printf("%d ", ans[i][j]);
      printf("%d\n", ans[i][n]);
    }
  }
  return 0;
}

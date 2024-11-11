#include <bits/stdc++.h>
using std::queue;
const int W = 14, N = 20005 * (W + 1), M = N + N * 4;
int to[M << 1], w[M << 1], Next[M << 1], edge, n, x, y, f[20005][W + 1], idn[N],
    deep[N], last[N], b[20005][W + 1];
int s, t, m, cnt, ans, tag[N], cur[N];
queue<int> q;
void add(int x, int y, int z) {
  to[++edge] = y;
  Next[edge] = last[x];
  last[x] = edge;
  w[edge] = z;
}
void dfs(int x, int fa) {
  f[x][0] = fa, deep[x] = deep[fa] + 1;
  for (int i = last[x]; i; i = Next[i])
    if (to[i] != fa) {
      idn[to[i]] = (i + 1) / 2;
      dfs(to[i], x);
    }
}
void Add(int x, int y, int w) {
  add(x, y, w);
  add(y, x, 0);
}
int lca(int x, int y) {
  if (deep[x] < deep[y]) std::swap(x, y);
  for (int i = W; i >= 0; i--)
    if (deep[f[x][i]] >= deep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = W; i >= 0; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
void addedge(int x, int y, int id) {
  for (int i = W; i >= 0; i--)
    if (deep[f[x][i]] >= deep[y]) {
      Add(id, b[x][i], n + 1);
      x = f[x][i];
    }
}
bool bfs() {
  for (int i = 0; i <= t; i++) cur[i] = last[i], deep[i] = 0;
  deep[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = last[x]; i; i = Next[i])
      if (w[i] && !deep[to[i]]) {
        deep[to[i]] = deep[x] + 1;
        q.push(to[i]);
      }
  }
  return (deep[t]);
}
int c(int x) { return x & 1 ? x + 1 : x - 1; }
int dfs(int x) {
  if (x == t) return 1;
  for (int i = cur[x]; i; i = Next[i]) {
    cur[x] = i;
    int u = to[i];
    if (deep[u] > deep[x] && w[i]) {
      int di = dfs(to[i]);
      if (di) {
        w[i]--;
        w[c(i)]++;
        return 1;
      }
    }
  }
  return 0;
}
void DFS(int x) {
  tag[x] = 1;
  for (int i = last[x]; i; i = Next[i])
    if (w[i] && !tag[to[i]]) DFS(to[i]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y, 0), add(y, x, 0);
  }
  s = 0;
  dfs(1, 0);
  edge = 0;
  memset(last, 0, sizeof(last));
  cnt = n;
  for (int i = 2; i <= n; i++) b[i][0] = i;
  for (int i = 1; i <= W; i++)
    for (int j = 1; j <= n; j++)
      if (f[f[j][i - 1]][i - 1]) {
        f[j][i] = f[f[j][i - 1]][i - 1];
        Add(++cnt, b[j][i - 1], n + 1);
        Add(cnt, b[f[j][i - 1]][i - 1], n + 1);
        b[j][i] = cnt;
      }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    Add(s, ++cnt, 1);
    idn[cnt] = i;
    int l = lca(x, y);
    addedge(x, l, cnt), addedge(y, l, cnt);
  }
  t = cnt + 1;
  for (int i = 2; i <= n; i++) Add(i, t, 1);
  while (bfs())
    while (dfs(s) == 1) ans++;
  printf("%d\n", ans);
  DFS(s);
  ans = 0;
  for (int i = last[s]; i; i = Next[i])
    if (tag[to[i]] != tag[s]) ans++;
  printf("%d ", ans);
  for (int i = last[s]; i; i = Next[i])
    if (tag[to[i]] != tag[s]) printf("%d ", idn[to[i]]);
  puts("");
  ans = 0;
  for (int i = last[t]; i; i = Next[i])
    if (tag[to[i]] != tag[t]) ans++;
  printf("%d ", ans);
  for (int i = last[t]; i; i = Next[i])
    if (tag[to[i]] != tag[t]) printf("%d ", idn[to[i]]);
  return 0;
}

#include <bits/stdc++.h>
const int MAXN = 100000 + 10;
const int MAXM = 200000 + 10;
int N, M;
long long c[MAXN];
int cnt = 1, head[MAXN], next[MAXM], to[MAXM];
int depth[MAXN];
int X, Y, id;
long long sumx, sumy, weight[MAXM];
inline void insert(int x, int y) {
  next[++cnt] = head[x], to[cnt] = y, head[x] = cnt;
  next[++cnt] = head[y], to[cnt] = x, head[y] = cnt;
}
inline void Dfs(int x) {
  register int i;
  for (i = head[x]; i; i = next[i])
    if (!depth[to[i]])
      depth[to[i]] = depth[x] + 1, Dfs(to[i]);
    else if (!(depth[x] - depth[to[i]] & 1))
      X = x, Y = to[i], id = i >> 1;
}
inline void solve(int x) {
  static bool visited[MAXN];
  register int i;
  visited[x] = 1;
  for (i = head[x]; i; i = next[i])
    if (!visited[to[i]])
      solve(to[i]), weight[i >> 1] = c[to[i]], c[x] -= weight[i >> 1];
}
int main() {
  register int i;
  register long long x, y;
  scanf("%d%d", &N, &M);
  for (i = 1; i <= N; ++i) scanf("%d", c + i);
  for (i = 1; i <= M; ++i) scanf("%d%d", &x, &y), insert(x, y);
  depth[1] = 1;
  Dfs(1);
  for (i = 1; i <= N; ++i) (depth[i] & 1 ? sumx : sumy) += c[i];
  if (sumx != sumy && !id) return 0 * puts("NO");
  x = (sumx - sumy) >> 1;
  (depth[X] & 1) ? weight[id] = x : weight[id] = -x;
  c[X] -= weight[id], c[Y] -= weight[id];
  solve(1);
  puts("YES");
  for (i = 1; i <= M; ++i) printf("%I64d\n", weight[i]);
  return 0;
}

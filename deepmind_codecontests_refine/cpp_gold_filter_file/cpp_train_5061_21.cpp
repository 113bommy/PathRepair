#include <bits/stdc++.h>
using namespace std;
int n, m, s, k, x, y, z, S, T, sl, fh, st[1010], cur[1010], dep[1010],
    f[610][610];
int t, head[1010], to[1000010], nxt[1000010], val[1000010];
queue<int> q;
int rd() {
  sl = 0;
  fh = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
void add(int u, int v, int w) {
  to[t] = v;
  val[t] = w;
  nxt[t] = head[u];
  head[u] = t++;
}
bool bfs() {
  while (!q.empty()) q.pop();
  memset(dep, 0, sizeof(dep));
  q.push(S);
  dep[S] = 1;
  int u, v;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = nxt[i])
      if (!dep[v = to[i]] && val[i] > 0) {
        dep[v] = dep[u] + 1;
        if (v == T) return 1;
        q.push(v);
      }
  }
  return 0;
}
int dfs(int u, int f) {
  if (f <= 0) return 0;
  if (u == T) return f;
  int v, q = 0, tmp;
  for (int &i = cur[u]; i != -1; i = nxt[i])
    if (dep[v = to[i]] == dep[u] + 1) {
      tmp = dfs(v, min(f, val[i]));
      if (!tmp) continue;
      f -= tmp;
      q += tmp;
      val[i] -= tmp;
      val[i ^ 1] += tmp;
      if (!f) return q;
    }
  return q;
}
bool check(int len) {
  memset(head, -1, sizeof(head));
  t = 0;
  for (int i = 1; i <= s; ++i) add(S, i, 1), add(i, S, 0);
  for (int i = 1; i <= n; ++i) add(s + i, T, 1), add(T, s + i, 0);
  for (int i = 1; i <= s; ++i)
    for (int j = 1; j <= n; ++j)
      if (f[st[i]][j] <= len) add(i, j + s, 1), add(j + s, i, 0);
  int sum, ans = 0;
  while (bfs()) {
    for (int i = 0; i <= s + n + 1; ++i) cur[i] = head[i];
    while (sum = dfs(S, 0x7fffffff)) ans += sum;
  }
  return ans >= k;
}
int main() {
  n = rd();
  m = rd();
  s = rd();
  k = rd();
  memset(f, 127 / 3, sizeof(f));
  for (int i = 1; i <= s; ++i) st[i] = rd();
  for (int i = 1; i <= m; ++i) {
    x = rd();
    y = rd();
    z = rd();
    f[x][y] = f[y][x] = min(f[x][y], z);
  }
  for (int i = 1; i <= n; ++i) f[i][i] = 0;
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      if (i != k)
        for (int j = 1; j <= n; ++j)
          if (i != j && j != k) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  int mid, ans = -1, l = 0, r = 1731311;
  S = 0, T = s + n + 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}

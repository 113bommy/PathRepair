#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 1e9;
const double pi = acos(-1.0);
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct data {
  int obj, pre, c;
} e[6005000];
int cur[1205], uu[1205], head[1205], mp[1205][1205], d[1205], vd[1205], a[1205];
int n, m, k, cnt, s, t, tot;
void insert(int x, int y, int c) {
  e[++tot].obj = y;
  e[tot].pre = head[x];
  e[tot].c = c;
  head[x] = tot;
  e[++tot].obj = x;
  e[tot].pre = head[y];
  e[tot].c = 0;
  head[y] = tot;
}
bool bfs() {
  queue<int> q;
  q.push(0);
  memset(uu, -1, sizeof(uu));
  uu[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = head[u]; j; j = e[j].pre) {
      int v = e[j].obj;
      if (uu[v] == -1 && e[j].c) {
        uu[v] = uu[u] + 1;
        q.push(v);
      }
    }
  }
  if (uu[t] == -1) return 0;
  return 1;
}
int dfs(int x, int mx) {
  if (x == t) return mx;
  int used = 0;
  for (int j = cur[x]; j; j = e[j].pre) {
    int v = e[j].obj;
    if (uu[v] == uu[x] + 1) {
      int w = dfs(v, min(e[j].c, mx - used));
      e[j].c -= w;
      e[j ^ 1].c += w;
      used += w;
      if (e[j].c) cur[x] = j;
      if (used == mx) return mx;
    }
  }
  if (!used) uu[x] = -1;
  return used;
}
int dinic() {
  int ans = 0;
  while (bfs()) {
    for (int i = 0; i <= t; i++) cur[i] = head[i];
    ans += dfs(0, inf);
  }
  return ans;
}
bool jud(int mid) {
  tot = 1;
  t = cnt + n + 2;
  for (int i = 0; i <= t; i++) head[i] = 0;
  for (int i = 1; i <= cnt; i++) insert(0, i, 1);
  for (int i = 1; i <= cnt; i++)
    for (int j = 1; j <= n; j++)
      if (mp[a[i]][j] <= mid) insert(i, cnt + j, 1);
  for (int i = 1; i <= n; i++) insert(cnt + i, t, 1);
  int ans = dinic();
  return ans >= k;
}
int main() {
  n = read();
  m = read();
  cnt = read();
  k = read();
  for (int i = 1; i <= cnt; i++) a[i] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) mp[i][j] = inf;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    mp[x][y] = mp[y][x] = min(mp[x][y], z);
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
  int l = 0, r = 1731312;
  int ans = inf;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (jud(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", ans > 1731311 ? -1 : ans);
  return 0;
}

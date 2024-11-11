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
} e[1205 * 1205 * 2];
int head[1205], mp[1205][1205], d[1205], vd[1205], a[1205];
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
int sap(int u, int mx) {
  if (u == t) return mx;
  int ans = 0, now = 0;
  for (int j = head[u]; j; j = e[j].pre) {
    int v = e[j].obj;
    if (d[v] + 1 == d[u] && e[j].c) {
      now = sap(v, min(e[j].c, mx - ans));
      ans += now;
      e[j].c -= now;
      e[j ^ 1].c += now;
      if (ans == mx) return ans;
    }
  }
  if (!--vd[d[u]]) {
    d[s] = t + 1;
    return ans;
  }
  ++vd[++d[u]];
  return ans;
}
bool jud(int mid) {
  tot = 1;
  memset(head, 0, sizeof(head));
  s = 2 * n + 1, t = 2 * n + 2;
  for (int i = 1; i <= cnt; i++) insert(s, a[i], 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (mp[i][j] <= mid) insert(i, n + j, inf);
  for (int i = 1; i <= n; i++) insert(n + i, t, 1);
  for (int i = 1; i <= t; i++) vd[i] = d[i] = 0;
  vd[0] = t;
  int ans = 0;
  while (d[s] <= t) ans += sap(s, inf);
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

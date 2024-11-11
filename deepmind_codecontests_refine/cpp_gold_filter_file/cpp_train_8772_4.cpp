#include <bits/stdc++.h>
using namespace std;
int h[20005], tot, n, m;
struct edge {
  int to, nxt;
} e[200005 << 1];
void add(int x, int y) {
  e[++tot].nxt = h[x];
  h[x] = tot;
  e[tot].to = y;
}
struct node {
  int u, v, val;
  bool operator<(const node o) const { return val < o.val; }
} a[200005];
int dfn[20005], low[20005], idx, v[20005], sta[20005], top, pos[20005], cnt;
void dfs(int x) {
  dfn[x] = low[x] = ++idx;
  v[x] = 1;
  sta[++top] = x;
  for (int i = h[x]; i; i = e[i].nxt) {
    if (!dfn[e[i].to])
      dfs(e[i].to), low[x] = min(low[x], low[e[i].to]);
    else if (v[e[i].to])
      low[x] = min(low[x], dfn[e[i].to]);
  }
  if (low[x] == dfn[x]) {
    ++cnt;
    while (true) {
      int y = sta[top--];
      pos[y] = cnt;
      v[y] = 0;
      if (x == y) return;
    }
  }
}
bool check(int r) {
  memset(h, 0, sizeof(h));
  tot = 0;
  top = 0;
  cnt = 0;
  idx = 0;
  memset(v, 0, sizeof(v));
  memset(dfn, 0, sizeof(dfn));
  for (int i = 1; i <= r; i++) add(a[i].u, a[i].v + n);
  for (int i = 1; i <= n; i++) add(i + n, i);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) dfs(i);
  for (int i = 1; i <= n; i++)
    if (pos[i] != pos[n + i]) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].val);
  sort(a + 1, a + m + 1);
  int l = 1, r = m, ans = ~0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  if (~ans)
    printf("%d\n", a[ans].val);
  else
    puts("-1");
  return 0;
}

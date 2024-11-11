#include <bits/stdc++.h>
int tot = 0, cnt = 0;
std::pair<long long, int> a[300005];
std::vector<std::pair<long long, int> > vec[300005];
int h[300005], to[600005], ver[600005];
int rt[600005], dep[300005], dis[600005], lson[600005], rson[600005];
long long f[600005], tag[600005];
inline int read() {
  register int x = 0, f = 1;
  register char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline void add(int x, int y) {
  to[++cnt] = y;
  ver[cnt] = h[x];
  h[x] = cnt;
}
inline void swap(int &x, int &y) {
  int tmp = y;
  y = x;
  x = tmp;
}
inline void work(int p, long long val) {
  tag[p] += val;
  a[p].first += val;
}
inline int spread(int p) {
  if (tag[p]) {
    work(lson[p], tag[p]);
    work(rson[p], tag[p]);
    tag[p] = 0;
  }
}
inline int merge(int x, int y) {
  if (!x || !y) return x + y;
  if (a[x].first > a[y].first) swap(x, y);
  spread(x);
  rson[x] = merge(rson[x], y);
  if (dis[rson[x]] > dis[lson[x]]) swap(lson[x], rson[x]);
  dis[x] = dis[rson[x]] + 1;
  return x;
}
inline void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  for (register int i = 0; i < vec[x].size(); ++i) {
    a[++tot] = std::make_pair(vec[x][i].first, vec[x][i].second);
    dis[tot] = 1;
    rt[x] = merge(rt[x], tot);
  }
  long long sum = 0;
  for (register int i = h[x]; i; i = ver[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs(y, x);
    work(rt[y], -f[y]);
    rt[x] = merge(rt[x], rt[y]);
    sum += f[y];
  }
  work(rt[x], sum);
  while (rt[x] && dep[x] <= dep[a[rt[x]].second]) {
    spread(rt[x]);
    rt[x] = merge(lson[rt[x]], rson[rt[x]]);
  }
  if (!rt[x]) {
    printf("-1 %d\n", x);
    exit(0);
  }
  f[x] = a[rt[x]].first;
}
int main() {
  int n = read(), m = read();
  tot = n;
  dep[1] = 1;
  for (register int i = 1; i < n; ++i) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  for (register int i = 1; i <= m; ++i) {
    int x = read(), y = read(), k = read();
    vec[x].push_back(std::make_pair(k, y));
  }
  long long ans = 0;
  for (register int i = h[1]; i; i = ver[i]) {
    int y = to[i];
    dfs(y, 1);
    ans += f[y];
  }
  printf("%lld\n", ans);
  return 0;
}

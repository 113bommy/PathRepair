#include <bits/stdc++.h>
const int N = 2e5 + 10;
int n, k, lim;
int a[N];
int pre[N << 1], to[N << 1], head[N], wcnt;
int size[N], fa[N];
struct Node {
  int sum;
  std::pair<int, int> max, sec;
  Node(int sum = 0, std::pair<int, int> max = std::pair<int, int>(0, 0),
       std::pair<int, int> sec = std::pair<int, int>(0, 0))
      : sum(sum), max(max), sec(sec) {}
  inline int val() const { return sum + max.first; }
  inline void push(const std::pair<int, int> &b) {
    if (b >= max) {
      sec = max;
      max = b;
    } else if (b >= sec)
      sec = b;
  }
  Node operator+(const Node &b) const {
    Node res = *this;
    res.sum += b.sum;
    res.push(b.max);
    res.push(b.sec);
    return res;
  }
};
Node f[N], g[N];
int ans;
inline void addedge(int u, int v) {
  wcnt++;
  pre[wcnt] = head[u];
  head[u] = wcnt;
  to[wcnt] = v;
}
inline void add2edge(int u, int v) {
  addedge(u, v);
  addedge(v, u);
}
void predfs(int u) {
  int i;
  size[u] = 1;
  for (i = head[u]; i; i = pre[i])
    if (fa[u] ^ to[i]) {
      fa[to[i]] = u;
      predfs(to[i]);
      size[u] += size[to[i]];
    }
}
void dfs1(int u) {
  int i;
  f[u].sum = 1;
  for (i = head[u]; i; i = pre[i])
    if (fa[u] ^ to[i]) dfs1(to[i]);
  for (i = head[u]; i; i = pre[i])
    if (fa[u] ^ to[i]) {
      if (f[to[i]].sum == size[to[i]])
        f[u].sum += f[to[i]].sum;
      else
        f[u].push(std::pair<int, int>(f[to[i]].val(), to[i]));
    }
  if (a[u] < lim) f[u] = Node();
}
void dfs2(int u) {
  Node t;
  int i;
  if (a[u] >= lim) {
    if (a[fa[u]] < lim)
      g[u] = f[u];
    else {
      t = g[fa[u]];
      if (f[u].sum == size[u])
        t.sum -= size[u];
      else if (g[u].max.second == u) {
        t.max = g[u].sec;
        t.sec = std::pair<int, int>();
      } else if (g[u].sec.second == u)
        t.sec = std::pair<int, int>();
      g[u] = f[u];
      if (t.sum == n - size[u])
        g[u].sum += t.sum;
      else
        g[u].push(std::pair<int, int>(t.val(), fa[u]));
    }
  }
  ans = std::max(ans, g[u].val());
  for (i = head[u]; i; i = pre[i])
    if (fa[u] ^ to[i]) dfs2(to[i]);
}
bool check() {
  int i;
  for (i = 1; i <= int(n); i++) f[i] = g[i] = Node();
  ans = 0;
  dfs1(1);
  dfs2(1);
  return ans >= k;
}
int main() {
  int i, u, v;
  int l, r, mid;
  scanf("%d %d", &n, &k);
  for (i = 1; i <= int(n); i++) scanf("%d", &a[i]);
  for (i = 1; i <= int(n - 1); i++) {
    scanf("%d %d", &u, &v);
    add2edge(u, v);
  }
  predfs(1);
  l = 1;
  r = 1e6;
  while (l ^ r) {
    lim = mid = (l + r + 1) >> 1;
    if (check())
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}

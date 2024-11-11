#include <bits/stdc++.h>
using namespace std;
stack<int> sta;
int n, m, q, amount;
int dep[100005], size[100005], top[100005], son[100005], fa[100005],
    tag[100005], rev[100005], total;
int scc[6000005];
bool ins[100005];
int dfn[6000005], low[6000005], number, quantity;
vector<int> g[100005];
int head[6000005], cnt;
struct data {
  int next, to;
  data(int next = 0, int to = 0) : next(next), to(to) {}
} edge[6000005];
struct segment {
  int l, r, p, q;
  vector<int> g;
} t[100005 << 2];
int zero(int x) { return x << 1; }
int one(int x) { return x << 1 | 1; }
void connect(int u, int v) {
  edge[++cnt] = data(head[u], v);
  head[u] = cnt;
  edge[++cnt] = data(head[v ^ 1], u ^ 1);
  head[v ^ 1] = cnt;
}
int read() {
  char c = getchar();
  int x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x;
}
void build(int l, int r, int x = 1) {
  t[x].l = l;
  t[x].r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, x << 1);
  build(mid + 1, r, x << 1 | 1);
}
void insert(int l, int r, int v, int x = 1) {
  if (l <= t[x].l && t[x].r <= r) {
    t[x].g.push_back(v);
    return;
  }
  int mid = (t[x].l + t[x].r) >> 1;
  if (l <= mid) insert(l, r, v, x << 1);
  if (r > mid) insert(l, r, v, x << 1 | 1);
}
void DFS1(int u, int pre) {
  fa[u] = pre;
  size[u] = 1;
  dep[u] = dep[pre] + 1;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v == pre) continue;
    DFS1(v, u);
    size[u] = size[u] + size[v];
    if (size[v] > size[son[u]]) son[u] = v;
  }
}
void DFS2(int u, int pre) {
  top[u] = pre;
  tag[u] = ++total;
  rev[total] = u;
  if (!son[u]) return;
  DFS2(son[u], pre);
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v == fa[u] || v == son[u]) continue;
    DFS2(v, v);
  }
}
void append(int u, int v, int e) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    insert(tag[top[u]], tag[u], e);
    u = fa[top[u]];
  }
  if (dep[u] > dep[v]) swap(u, v);
  insert(tag[u] + 1, tag[v], e);
}
void construct(int x = 1) {
  t[x].p = ++amount;
  amount = t[x].q = t[x].p + (int)t[x].g.size();
  if (x != 1) {
    connect(zero(t[x].p), zero(t[x >> 1].q));
    if (t[x].g.size()) connect(t[x].g[0], zero(t[x >> 1].q));
  }
  for (int i = 0; i < t[x].g.size(); ++i) {
    int p = t[x].g[i];
    if (i) connect(p, zero(t[x].p + i - 1));
    connect(zero(t[x].p + i + 1), zero(t[x].p + i));
    connect(p, one(t[x].p + i));
  }
  if (t[x].l == t[x].r) return;
  construct(x << 1);
  construct(x << 1 | 1);
}
void tarjan(int u) {
  sta.push(u);
  ins[u] = true;
  dfn[u] = low[u] = ++number;
  for (int i = head[u]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    int k;
    ++quantity;
    do {
      k = sta.top();
      sta.pop();
      ins[k] = false;
      scc[k] = quantity;
    } while (u != k);
  }
}
int main() {
  n = read();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  DFS1(1, 0);
  DFS2(1, 1);
  build(1, n);
  m = read();
  for (int i = 1; i <= m; ++i) {
    int u1 = read(), v1 = read(), u2 = read(), v2 = read();
    append(u1, v1, zero(i));
    append(u2, v2, one(i));
  }
  amount = m;
  construct();
  for (int i = 1; i <= (amount << 1 | 1); ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= m; ++i)
    if (scc[one(i)] == scc[zero(i)]) {
      puts("NO");
      return 0;
    }
  puts("YES");
  for (int i = 1; i <= m; ++i) puts(scc[i << 1] < scc[i << 1 | 1] ? "1" : "2");
}

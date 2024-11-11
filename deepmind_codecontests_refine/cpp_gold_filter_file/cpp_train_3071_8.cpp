#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, m;
vector<int> son[N];
int dfn[N], size[N];
void dfs(int x) {
  static int t = 0;
  dfn[x] = ++t;
  size[x] = 1;
  for (auto &y : son[x]) dfs(y), size[x] += size[y];
}
struct Info {
  int w, t, node, coef;
  bool operator<(const Info &x) const { return t < x.t; }
} query[N], add[N];
int q, a, id;
long long ans[N];
struct Army {
  int fa[N], n;
  int find(int x) {
    if (x == fa[x]) return x;
    int t = find(fa[x]);
    las[x] = max(las[x], las[fa[x]]);
    return fa[x] = t;
  }
  int las[N];
  void init(int t) {
    n = t;
    for (int i = 1; i <= 2 * t; ++i) fa[i] = i, las[i] = 0;
  }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = fa[y] = ++n;
  }
  void go(int x, int t) { las[find(x)] = t; }
  void ask(int x, int t) {
    id++;
    query[++q] = (Info){id, t, x, 1};
    find(x), query[++q] = (Info){id, las[x], x, -1};
  }
} army;
struct Uni {
  int fa[N], n;
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  int sz[N];
  void init(int t) {
    n = t;
    for (int i = 1; i <= 2 * t; ++i) fa[i] = i, sz[i] = (i <= t);
  }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = fa[y] = ++n;
    son[n].emplace_back(x), son[n].emplace_back(y);
    sz[n] = sz[x] + sz[y];
  }
  void go(int x, int t) {
    x = find(x);
    add[++a] = (Info){sz[x], t, x, 0};
  }
} uni;
struct Bit {
  int n;
  long long tree[N];
  void init(int t) { n = 2 * t; }
  void add(int l, int r, int w) {
    for (int i = l; i <= n; i += (i & -i)) tree[i] += w;
    for (int i = r + 1; i <= n; i += (i & -i)) tree[i] -= w;
  }
  long long ask(int x) {
    long long res = 0;
    for (; x; x &= (x - 1)) res += tree[x];
    return res;
  }
  void A(Info &x) { add(dfn[x.node], dfn[x.node] + size[x.node] - 1, x.w); }
  void Q(Info &x) { ans[x.w] += x.coef * ask(dfn[x.node]); }
} bit;
inline int read() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = getchar();
  return f ? -x : x;
}
inline void write(long long x) {
  char s[25] = {}, *p = s + 23;
  if (x < 0) putchar('-'), x = -x;
  do *(--p) = x % 10 + '0', x /= 10;
  while (x);
  puts(p);
}
char getop() {
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  return c;
}
int main() {
  n = read(), m = read();
  army.init(n), uni.init(n);
  for (int t = 1; t <= m; ++t) {
    char c = getop();
    int x, y;
    if (c == 'U') x = read(), y = read(), uni.merge(x, y);
    if (c == 'M') x = read(), y = read(), army.merge(x, y);
    if (c == 'A') uni.go(read(), t);
    if (c == 'Z') army.go(read(), t);
    if (c == 'Q') army.ask(read(), t);
  }
  sort(add + 1, add + 1 + a), sort(query + 1, query + 1 + q);
  int rt = uni.n + 1;
  for (int i = 1; i <= uni.n; ++i)
    if (uni.find(i) == i) son[rt].push_back(i);
  bit.init(n), dfs(rt);
  int p = 1;
  for (int i = 1; i <= a; ++i) {
    while (query[p].t <= add[i].t & p <= q) bit.Q(query[p++]);
    bit.A(add[i]);
  }
  while (p <= q) bit.Q(query[p++]);
  for (int i = 1; i <= id; ++i) write(ans[i]);
  return 0;
}

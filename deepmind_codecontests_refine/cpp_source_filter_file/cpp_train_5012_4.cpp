#include <bits/stdc++.h>
const int maxn = 1e6 + 9;
void Dfs(int u, int f);
inline int Read() {
  int x(0), f(1);
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
struct node {
  int to, nxt;
} dis[maxn];
int num, tim;
int head[maxn];
inline void Add(int u, int v) {
  dis[++num] = (node){v, head[u]};
  head[u] = num;
}
struct BIT {
  const int up = 4e5;
  int tree[maxn];
  inline int Lowbit(int x) { return x & -x; }
  inline void Add(int x, int val) {
    for (x; x <= 400000; x += Lowbit(x)) tree[x] += val;
  }
  inline int Query(int x) {
    int ret(0);
    for (; x; x -= Lowbit(x)) ret += tree[x];
    return ret;
  }
} t1;
struct LCT {
  int fa[maxn], son[maxn][2], size[maxn], lazy[maxn], r[maxn], col[maxn],
      sta[maxn];
  inline int N_rt(int x) { return son[fa[x]][0] == x || son[fa[x]][1] == x; }
  inline void Up(int x) { size[x] = size[son[x][0]] + size[son[x][1]] + 1; }
  inline void Ro(int x) {
    int y(fa[x]), z(fa[y]), lz(son[y][1] == x);
    if (N_rt(y)) {
      son[z][son[z][1] == y] = x;
    }
    fa[x] = z;
    son[y][lz] = son[x][lz ^ 1];
    if (son[y][lz]) fa[son[y][lz]] = y;
    son[x][lz ^ 1] = y;
    fa[y] = x;
    Up(y);
    Up(x);
  }
  inline void Pr(int x) {
    std::swap(son[x][0], son[x][1]);
    r[x] ^= 1;
  }
  inline void Pd(int x) {
    int lc(son[x][0]), rc(son[x][1]);
    if (r[x]) {
      if (lc) Pr(lc);
      if (rc) Pr(rc);
      r[x] = 0;
    }
    if (lazy[x]) {
      if (lc) col[lc] = lazy[lc] = lazy[x];
      if (rc) col[rc] = lazy[rc] = lazy[x];
      lazy[x] = 0;
    }
  }
  inline void Splay(int x) {
    int top(0), y(x);
    sta[++top] = y;
    while (N_rt(y)) y = fa[y], sta[++top] = y;
    while (top) Pd(sta[top--]);
    while (N_rt(x)) {
      y = fa[x];
      if (N_rt(y)) {
        int z(fa[y]);
        if ((son[y][1] == x) ^ (son[z][1] == y))
          Ro(x);
        else
          Ro(y);
      }
      Ro(x);
    }
  }
  inline void Ac(int x, int id) {
    int y(0);
    for (; x; y = x, x = fa[x]) {
      Splay(x);
      int z(son[x][1]);
      t1.Add(col[x], size[z] - size[x]);
      son[x][1] = y;
      Up(x);
    }
    t1.Add(id, size[y]);
    lazy[y] = id;
    col[y] = id;
  }
  inline void Mk_rt(int x, int id) {
    Ac(x, id);
    Splay(x);
    Pr(x);
  }
  inline int Query(int u) {
    Splay(u);
    int ret(t1.Query(col[u] - 1));
    ret += size[son[u][1]] + 1;
    return ret;
  }
} t2;
int n, m;
char s[maxn];
int main() {
  n = Read();
  m = Read();
  for (int i = 1; i < n; ++i) {
    int u(Read()), v(Read());
    Add(u, v);
    Add(v, u);
  }
  Dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    t2.col[i] = i;
    t2.size[i] = 1;
    t1.Add(i, 1);
  }
  tim = n;
  for (int i = 1; i <= n; ++i) {
    ++tim;
    t2.Mk_rt(i, tim);
  }
  while (m--) {
    scanf(" %s", s + 1);
    int u, v;
    if (s[1] == 'u') {
      ++tim;
      u = Read();
      t2.Mk_rt(u, tim);
    } else if (s[1] == 'w') {
      u = Read();
      printf("%d\n", t2.Query(u));
    } else {
      u = Read();
      v = Read();
      printf("%d\n", t2.Query(u) < t2.Query(v) ? u : v);
    }
  }
}
void Dfs(int u, int f) {
  for (int i = head[u]; i; i = dis[i].nxt) {
    int v(dis[i].to);
    if (v == f) continue;
    Dfs(v, u);
    t2.fa[v] = u;
  }
}

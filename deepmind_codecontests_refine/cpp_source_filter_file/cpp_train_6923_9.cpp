#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200200;
struct Edge {
  int to, next;
  unsigned long long w;
} edge[MAXN * 2];
int head[MAXN], tot;
int top[MAXN], fa[MAXN], deep[MAXN], num[MAXN];
int p[MAXN], fp[MAXN], son[MAXN];
int pos;
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  pos = 1;
  memset(son, -1, sizeof(son));
}
inline void addedge(int u, int v) {
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot++;
}
inline void dfs1(int u, int pre, int d) {
  deep[u] = d;
  fa[u] = pre;
  num[u] = 1;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (v != pre) {
      dfs1(v, u, d + 1);
      num[u] += num[v];
      if (son[u] == -1 || num[v] > num[son[u]]) son[u] = v;
    }
  }
}
inline void getpos(int u, int sp) {
  top[u] = sp;
  p[u] = pos++;
  fp[p[u]] = u;
  if (son[u] == -1) return;
  getpos(son[u], sp);
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (v != son[u] && v != fa[u]) getpos(v, v);
  }
}
unsigned long long mul[MAXN << 2];
unsigned long long LINF = 1e18 + 1ll;
unsigned long long oper(unsigned long long a, unsigned long long b) {
  if (a == -1 || b == -1)
    return -1;
  else {
    if (a > LINF / b)
      return -1;
    else
      return a * b;
  }
}
void up(int rt) { mul[rt] = oper(mul[rt << 1], mul[rt << 1 | 1]); }
void build(int l, int r, int rt) {
  mul[rt] = 1;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
}
void update(int p, unsigned long long v, int l, int r, int rt) {
  if (l == r) {
    mul[rt] = v;
    return;
  }
  int m = (l + r) >> 1;
  if (p <= m)
    update(p, v, l, m, rt << 1);
  else
    update(p, v, m + 1, r, rt << 1 | 1);
  up(rt);
}
unsigned long long query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return mul[rt];
  }
  int m = (l + r) >> 1;
  unsigned long long ret = 1;
  if (L <= m) ret = oper(ret, query(L, R, l, m, rt << 1));
  if (R > m) ret = oper(ret, query(L, R, m + 1, r, rt << 1 | 1));
  return ret;
}
int n, m;
unsigned long long ask(int u, int v) {
  unsigned long long ret = 1;
  int f1 = top[u], f2 = top[v];
  while (f1 != f2) {
    if (deep[f1] < deep[f2]) {
      swap(f1, f2);
      swap(u, v);
    }
    ret = oper(ret, query(p[f1], p[u], 1, n, 1));
    u = fa[f1];
    f1 = top[u];
  }
  if (u == v) return ret;
  if (deep[u] > deep[v]) swap(u, v);
  ret = oper(ret, query(p[son[u]], p[v] + 1, 1, n, 1));
  return ret;
}
pair<int, int> pp[MAXN];
unsigned long long eval[MAXN];
int link[MAXN];
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    init();
    for (int i = 1; i < n; i++) {
      int u, v;
      unsigned long long w;
      scanf("%d%d%I64d", &u, &v, &w);
      pp[i] = make_pair(u, v);
      addedge(u, v);
      addedge(v, u);
      eval[i] = w;
    }
    dfs1(1, 0, 0);
    getpos(1, 1);
    for (int i = 1; i < n; i++) {
      if (deep[pp[i].first] > deep[pp[i].second])
        swap(pp[i].first, pp[i].second);
      link[i] = p[pp[i].second];
    }
    build(1, n, 1);
    for (int i = 1; i < n; i++) {
      update(link[i], eval[i], 1, n, 1);
    }
    for (int i = 0; i < m; i++) {
      int op;
      scanf("%d", &op);
      if (op == 1) {
        int u, v;
        unsigned long long w;
        scanf("%d%d%I64d", &u, &v, &w);
        unsigned long long q = ask(u, v);
        if (q == -1)
          puts("0");
        else
          printf("%I64d\n", w / q);
      } else {
        int p;
        unsigned long long w;
        scanf("%d%I64d", &p, &w);
        update(link[p], w, 1, n, 1);
      }
    }
  }
  return 0;
}

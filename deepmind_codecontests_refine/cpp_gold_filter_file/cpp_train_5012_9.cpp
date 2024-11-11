#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
struct node {
  int son[2], fa, sz, tag;
} g[1010101];
int n, m, col[1010101], head[1010101], tot;
struct edge {
  int to, nxt;
} e[1010101];
inline void made(int from, int to) {
  e[++tot].to = to;
  e[tot].nxt = head[from];
  head[from] = tot;
}
int tr[1010101];
inline void add(int x, int y) {
  for (; x <= n + m; x += x & -x) tr[x] += y;
}
inline int query(int x) {
  int ans = 0;
  for (; x; x -= x & -x) ans += tr[x];
  return ans;
}
inline void pushup(int rt) {
  g[rt].sz = g[g[rt].son[0]].sz + g[g[rt].son[1]].sz + 1;
}
inline void reverse(int rt) {
  if (!rt) return;
  g[rt].tag ^= 1;
  swap(g[rt].son[0], g[rt].son[1]);
}
inline void pushdown(int rt) {
  if (g[rt].tag) reverse(g[rt].son[0]), reverse(g[rt].son[1]), g[rt].tag = 0;
  if (g[rt].son[0]) col[g[rt].son[0]] = col[rt];
  if (g[rt].son[1]) col[g[rt].son[1]] = col[rt];
}
inline bool isrt(int rt) {
  return (g[g[rt].fa].son[0] != rt && g[g[rt].fa].son[1] != rt);
}
inline bool wtson(int rt) { return (g[g[rt].fa].son[0] == rt ? 0 : 1); }
inline void rotate(int rt) {
  int fa = g[rt].fa, fafa = g[fa].fa, wht = wtson(rt), whtfa = wtson(fa),
      son = g[rt].son[1 ^ wht];
  g[rt].fa = fafa;
  if (fafa && !isrt(fa)) g[fafa].son[whtfa] = rt;
  g[fa].fa = rt;
  g[rt].son[1 ^ wht] = fa;
  g[son].fa = fa;
  g[fa].son[wht] = son;
  pushup(fa);
}
int sta[1010101], top;
inline void splay(int rt) {
  sta[top = 1] = rt;
  for (int i = rt; !isrt(i); i = g[i].fa) sta[++top] = g[i].fa;
  for (; top; top--) pushdown(sta[top]);
  while (!isrt(rt)) {
    int fa = g[rt].fa;
    if (isrt(fa))
      rotate(rt);
    else if (wtson(rt) == wtson(fa))
      rotate(fa), rotate(rt);
    else
      rotate(rt), rotate(rt);
  }
  pushup(rt);
}
int ccnt;
inline void access(int x) {
  for (int y = 0; x; x = g[y = x].fa) {
    splay(x);
    g[x].son[1] = 0;
    pushup(x);
    add(col[x], -g[x].sz);
    add(ccnt, g[x].sz);
    g[x].son[1] = y;
    pushup(x);
  }
}
inline void doit(int x) {
  ccnt++;
  access(x);
  splay(x);
  reverse(x);
  col[x] = ccnt;
}
void dfs(int u, int fa) {
  col[u] = u;
  g[u].fa = fa;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    if (col[v] > col[u]) {
      col[u] = col[v];
      g[u].son[1] = v;
    }
  }
  pushup(u);
  add(col[u], 1);
}
inline int get(int x) {
  splay(x);
  return (1 + query(col[x] - 1) + g[g[x].son[1]].sz);
}
signed main() {
  n = read(), m = read();
  ccnt = n;
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    made(x, y);
    made(y, x);
  }
  dfs(n, 0);
  for (int T = 1; T <= m; T++) {
    char ss[10];
    scanf("%s", ss + 1);
    if (ss[1] == 'u') {
      doit(read());
    } else if (ss[1] == 'w') {
      int x = read();
      printf("%d\n", get(x));
    } else {
      int x = read(), y = read();
      printf("%d\n", get(x) > get(y) ? y : x);
    }
  }
  return 0;
}

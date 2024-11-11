#include <bits/stdc++.h>
using std::cerr;
using std::endl;
inline int read() {
  int x = 0, f = 1;
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
const int MAXN = 400005;
int n, m, ecnt, head[MAXN];
int c[MAXN], fa[MAXN];
long long ans[MAXN], cur;
std::vector<std::pair<int, int> > vec[MAXN];
struct Edge {
  int to, nxt;
} e[MAXN << 1];
inline void add_edge(int bg, int ed) {
  ++ecnt;
  e[ecnt].to = ed;
  e[ecnt].nxt = head[bg];
  head[bg] = ecnt;
}
struct lct {
  int fa, ch[2];
  int siz;
  int isiz;
  long long ich2;
  bool tag;
} a[MAXN];
inline bool isroot(int x) {
  return a[a[x].fa].ch[0] != x && a[a[x].fa].ch[1] != x;
}
inline void pushr(int x) {
  std::swap(a[x].ch[0], a[x].ch[1]);
  a[x].tag ^= 1;
}
inline void pushdown(int x) {
  if (!a[x].tag) return;
  if (a[x].ch[0]) pushr(a[x].ch[0]);
  if (a[x].ch[1]) pushr(a[x].ch[1]);
  a[x].tag = false;
}
inline void pushup(int x) {
  a[x].siz = a[a[x].ch[0]].siz + a[a[x].ch[1]].siz + 1 + a[x].isiz;
}
inline void rotate(int x) {
  int y = a[x].fa, z = a[y].fa, d = a[y].ch[1] == x, w = a[x].ch[d ^ 1];
  if (!isroot(y)) a[z].ch[a[z].ch[1] == y] = x;
  a[x].ch[d ^ 1] = y;
  a[y].ch[d] = w;
  if (w) a[w].fa = y;
  a[y].fa = x;
  a[x].fa = z;
  pushup(y);
}
int top, sta[MAXN];
inline void splay(int x) {
  int y = x, z = 0;
  sta[top = 1] = y;
  while (!isroot(y)) sta[++top] = y = a[y].fa;
  while (top) pushdown(sta[top--]);
  while (!isroot(x)) {
    y = a[x].fa, z = a[y].fa;
    if (!isroot(y)) {
      if ((a[z].ch[0] == y) == (a[y].ch[0] == x))
        rotate(y);
      else
        rotate(x);
    }
    rotate(x);
  }
  pushup(x);
}
inline void access(int x) {
  for (int y = 0; x; x = a[y = x].fa) {
    splay(x);
    a[x].isiz += a[a[x].ch[1]].siz;
    a[x].ich2 += ((1ll * a[a[x].ch[1]].siz) * (1ll * a[a[x].ch[1]].siz));
    a[x].ch[1] = y;
    a[x].isiz -= a[a[x].ch[1]].siz;
    a[x].ich2 -= ((1ll * a[a[x].ch[1]].siz) * (1ll * a[a[x].ch[1]].siz));
    pushup(x);
  }
}
inline void makeroot(int x) {
  access(x);
  splay(x);
  pushr(x);
}
inline int findroot(int x) {
  access(x);
  splay(x);
  while (pushdown(x), a[x].ch[0]) x = a[x].ch[0];
  splay(x);
  return x;
}
inline void split(int x, int y) {
  makeroot(x);
  access(y);
  splay(y);
}
inline void link(int x, int y) {
  split(x, y);
  a[x].fa = y;
  a[y].isiz += a[x].siz;
  a[y].ich2 += ((1ll * a[x].siz) * (1ll * a[x].siz));
  pushup(y);
}
inline void cut(int x, int y) {
  split(x, y);
  a[y].ch[0] = 0;
  a[x].fa = 0;
  pushup(y);
}
inline void link(int x) {
  int y = fa[x];
  access(x);
  splay(x);
  cur -= a[x].ich2 + ((1ll * a[a[x].ch[1]].siz) * (1ll * a[a[x].ch[1]].siz));
  int z = findroot(y);
  access(y);
  splay(z);
  cur -= ((1ll * a[a[z].ch[1]].siz) * (1ll * a[a[z].ch[1]].siz));
  splay(y);
  a[x].fa = y;
  a[y].isiz += a[x].siz;
  a[y].ich2 += ((1ll * a[x].siz) * (1ll * a[x].siz));
  pushup(y);
  access(x);
  splay(z);
  cur += ((1ll * a[a[z].ch[1]].siz) * (1ll * a[a[z].ch[1]].siz));
}
inline void cut(int x) {
  int y = fa[x];
  access(x);
  cur += a[x].ich2;
  int z = findroot(y);
  access(x);
  splay(z);
  cur -= ((1ll * a[a[z].ch[1]].siz) * (1ll * a[a[z].ch[1]].siz));
  splay(x);
  a[a[x].ch[0]].fa = 0;
  a[x].ch[0] = 0;
  pushup(x);
  access(y);
  splay(z);
  cur += ((1ll * a[a[z].ch[1]].siz) * (1ll * a[a[z].ch[1]].siz));
}
void dfs(int x, int pre) {
  fa[x] = pre;
  for (int i = head[x]; i; i = e[i].nxt) {
    int ver = e[i].to;
    if (ver == pre) continue;
    dfs(ver, x);
  }
  a[x].fa = pre;
  a[pre].isiz += a[x].siz;
  a[pre].ich2 += ((1ll * a[x].siz) * (1ll * a[x].siz));
  pushup(pre);
}
int main() {
  n = read(), m = read();
  for (int i = (1); i <= (n); ++i) {
    c[i] = read();
    vec[c[i]].push_back(std::make_pair(i, 0));
  }
  for (int i = (2); i <= (n); ++i) {
    int u = read(), v = read();
    add_edge(u, v);
    add_edge(v, u);
  }
  for (int i = (1); i <= (n + 1); ++i) a[i].siz = 1;
  dfs(1, n + 1);
  for (int i = (1); i <= (m); ++i) {
    int x = read(), y = read();
    if (c[x] == y) continue;
    vec[c[x]].push_back(std::make_pair(-x, i));
    c[x] = y;
    vec[c[x]].push_back(std::make_pair(x, i));
  }
  cur = 1ll * n * (n - 1);
  for (int i = (1); i <= (n); ++i) {
    for (int j = (0); j <= ((int)vec[i].size() - 1); ++j) {
      int x = vec[i][j].first;
      if (x > 0)
        cut(x);
      else
        link(-x);
      ans[vec[i][j].second] += 1ll * n * (n - 1) - cur;
      ans[j == (int)vec[i].size() - 1 ? m + 1 : vec[i][j + 1].second] -=
          1ll * n * (n - 1) - cur;
    }
    for (int j = ((int)vec[i].size() - 1); j >= (0); --j) {
      int x = vec[i][j].first;
      if (x > 0)
        link(x);
      else
        cut(-x);
    }
  }
  for (int i = (1); i <= (m); ++i) ans[i] += ans[i - 1];
  for (int i = (0); i <= (m); ++i) printf("%I64d\n", ans[i]);
  return 0;
}

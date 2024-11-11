#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
struct p {
  int x, y;
} c[MAX << 1];
int n, m, COL, num;
int s[MAX << 1], st[MAX], h[MAX];
int lowbit(int x) { return x & (-x); }
void change(int x, int d) {
  for (int i = x; i <= n + m; i += lowbit(i)) s[i] += d;
}
int ask(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) ans += s[i];
  return ans;
}
struct Link_Cut_Tree {
  int tag[MAX], fa[MAX], siz[MAX], col[MAX];
  int son[MAX][2];
  bool fl[MAX];
  void pus(int x) { siz[x] = siz[son[x][0]] + siz[son[x][1]] + 1; }
  void down(int x) {
    if (fl[x]) {
      if (son[x][0]) fl[son[x][0]] ^= 1;
      if (son[x][1]) fl[son[x][1]] ^= 1;
      swap(son[x][0], son[x][1]), fl[x] = 0;
    }
    if (tag[x]) {
      if (son[x][0]) col[son[x][0]] = tag[son[x][0]] = tag[x];
      if (son[x][1]) col[son[x][1]] = tag[son[x][1]] = tag[x];
      tag[x] = 0;
    }
  }
  bool is_root(int x) { return son[fa[x]][0] != x && son[fa[x]][1] != x; }
  bool GET_ID(int x) { return son[fa[x]][1] == x; }
  void rot(int x) {
    int y = fa[x], z = fa[y], k = GET_ID(x);
    if (!is_root(y)) son[z][GET_ID(y)] = x;
    son[y][k] = son[x][k ^ 1], fa[son[y][k]] = y, son[x][k ^ 1] = y, fa[y] = x,
    fa[x] = z;
    pus(y), pus(x);
  }
  void splay(int x) {
    int qwq = x, Top = 0;
    for (; !is_root(qwq); qwq = fa[qwq]) st[++Top] = qwq;
    if (qwq) down(qwq);
    while (Top) down(st[Top--]);
    for (int y; !is_root(x); rot(x))
      if (!is_root(y = fa[x])) rot(GET_ID(x) == GET_ID(y) ? y : x);
  }
  void access(int x, int Col) {
    for (int y = 0; x; y = x, x = fa[x])
      splay(x), change(col[x], -siz[x] + siz[son[x][1]]),
          change(col[x] = Col, siz[x] - siz[son[x][1]]), tag[x] = Col,
                                                         son[x][1] = y, pus(x);
  }
  void make_root(int x) {
    access(x, COL), splay(x), fl[x] ^= 1, down(x), change(col[x], -1),
        son[x][1] = 0, col[x] = tag[x] = ++COL, siz[x] = 1, change(col[x], 1);
  }
  void GET_TREE(int x = n, int F = 0) {
    col[x] = x, siz[x] = 1, fa[x] = F;
    for (int i = h[x]; i; i = c[i].x)
      if (c[i].y ^ F) GET_TREE(c[i].y, x), col[x] = max(col[x], col[c[i].y]);
    for (int i = h[x]; i; i = c[i].x)
      if (col[x] == col[c[i].y]) son[x][1] = c[i].y, siz[x] += siz[c[i].y];
    change(col[x], 1);
  }
  int GET_TIME(int x) { return splay(x), ask(col[x]) - siz[son[x][0]]; }
} Tree;
char a[11];
int read() {
  int x(0);
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    ;
  for (; isdigit(ch); x = x * 10 + ch - 48, ch = getchar())
    ;
  return x;
}
void add(int x, int y) {
  c[++num] = (p){h[x], y}, h[x] = num;
  c[++num] = (p){h[y], x}, h[y] = num;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i < n; ++i) add(read(), read());
  Tree.GET_TREE(), COL = n + 1;
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%s", a), x = read();
    if (a[0] == 'u')
      Tree.make_root(x);
    else if (a[0] == 'w')
      printf("%d\n", Tree.GET_TIME(x));
    else if (a[0] == 'c')
      y = read(), Tree.GET_TIME(x) < Tree.GET_TIME(y) ? printf("%d\n", x)
                                                      : printf("%d\n", y);
  }
  return 0;
}

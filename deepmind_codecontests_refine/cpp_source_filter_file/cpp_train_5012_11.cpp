#include <bits/stdc++.h>
using namespace std;
struct node {
  int to, next;
} q[410500];
int head[203100], ss, fa[203100], son[203100][2], sz[203100], rev[203100],
    col[203100], U, tag[203100], C, tre[203100], stk[203100];
char s[20];
void addedge(int x, int y) {
  q[++ss] = (node){y, head[x]};
  head[x] = ss;
  q[++ss] = (node){x, head[y]};
  head[y] = ss;
}
bool isroot(int x) { return son[fa[x]][0] != x && son[fa[x]][1] != x; }
void add(int x, int v) {
  for (int i = x; i <= U; i += i & -i) tre[i] += v;
}
int qry(int x) {
  int ans = 0;
  for (; x; x = x & x - 1) ans += tre[x];
  return ans;
}
void dfs(int i, int F) {
  col[i] = i;
  sz[i] = 1;
  for (int j = head[i]; j; j = q[j].next)
    if (q[j].to ^ F) {
      int t = q[j].to;
      fa[t] = i;
      dfs(t, i);
      if (col[t] > col[i]) {
        col[i] = col[t];
        son[i][1] = t;
        sz[i] = sz[t] + 1;
      }
    }
  add(col[i], 1);
}
inline void update(int x) { sz[x] = sz[son[x][0]] + sz[son[x][1]] + 1; }
inline void rotate(int x) {
  int y = fa[x], z = (son[fa[x]][1] == x);
  fa[x] = fa[y];
  if (!isroot(y)) son[fa[y]][(son[fa[y]][1] == y)] = x;
  fa[y] = x;
  if (son[x][z ^ 1]) fa[son[x][z ^ 1]] = y;
  son[y][z] = son[x][z ^ 1];
  son[x][z ^ 1] = y;
  update(y);
}
void pushdown(int x) {
  if (rev[x]) {
    swap(son[son[x][0]][0], son[son[x][0]][1]);
    rev[son[x][0]] ^= 1;
    swap(son[son[x][1]][1], son[son[x][1]][0]);
    rev[son[x][1]] ^= 1;
    rev[x] = 0;
  }
  if (son[x][1]) col[son[x][1]] = col[x];
  if (son[x][0]) col[son[x][0]] = col[x];
}
void splay(int x) {
  int top = 0;
  stk[++top] = x;
  for (int y = x; !isroot(y); y = fa[y]) stk[++top] = fa[y];
  while (top) pushdown(stk[top--]);
  while (!isroot(x)) {
    if (!isroot(fa[x]))
      rotate((son[fa[fa[x]]][1] == fa[x]) == (son[fa[x]][1] == x) ? fa[x] : x);
    rotate(x);
  }
  update(x);
}
void access(int x) {
  int y = 0;
  for (; x; y = x, x = fa[x]) {
    splay(x);
    son[x][1] = 0;
    update(x);
    add(col[x], -sz[x]);
    son[x][1] = y;
    update(x);
  }
  add(C, sz[y]);
}
void makeroot(int x) {
  ++C;
  access(x);
  splay(x);
  col[x] = C;
  rev[x] ^= 1;
  swap(son[x][0], son[x][1]);
}
int query(int x) {
  splay(x);
  return qry(col[x] - 1) + sz[son[x][1]] + 1;
}
inline int read() {
  int n = 0;
  char a;
  bool z = false;
  while (a = getchar()) {
    if (a > '9' || a < '0')
      if (z)
        break;
      else
        continue;
    if (!z) z = true;
    n = (n << 1) + (n << 3) + (a ^ 48);
  }
  return n;
}
int main() {
  int n = read(), Q = read(), x, y;
  U = n + Q;
  C = n;
  for (int i = 1; i < n; ++i) addedge(read(), read());
  dfs(n, n);
  while (Q--) {
    scanf("%s", s + 1);
    switch (s[1]) {
      case 'u':
        x = read();
        makeroot(x);
        break;
      case 'w':
        printf("%d\n", query(read()));
        break;
      case 'c':
        x = read();
        y = read();
        printf("%d\n", query(x) < query(y) ? x : y);
        break;
    }
  }
  return 0;
}

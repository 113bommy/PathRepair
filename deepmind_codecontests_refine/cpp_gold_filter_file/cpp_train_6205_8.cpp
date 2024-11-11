#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[1 << 16], *S, *T;
  if (S == T) {
    T = (S = buf) + fread(buf, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline int read() {
  int x = 0, f = 1;
  char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc();
  return x * f;
}
int n, Q, m = 0, fa[100010 << 1], c[100010 << 1][2], sz[100010 << 1],
          v[100010 << 1], mn[100010 << 1], cnt = 0, q[100010 << 1];
bool rev[100010 << 1];
int mark[100010];
struct quer {
  int op, id;
} qq[100010];
struct edge {
  int x, y;
} e[100010];
map<pair<int, int>, int> mp;
inline bool isroot(int x) { return x != c[fa[x]][0] && x != c[fa[x]][1]; }
inline void update(int p) {
  int l = c[p][0], r = c[p][1];
  sz[p] = sz[l] + sz[r] + 1;
  if (v[p] <= v[mn[l]] && v[p] <= v[mn[r]])
    mn[p] = p;
  else if (v[mn[l]] <= v[mn[r]])
    mn[p] = mn[l];
  else
    mn[p] = mn[r];
}
inline void pushdown(int p) {
  if (!rev[p]) return;
  rev[p] = 0;
  swap(c[p][0], c[p][1]);
  rev[c[p][0]] ^= 1;
  rev[c[p][1]] ^= 1;
}
inline void rotate(int x) {
  int y = fa[x], z = fa[y], l = x == c[y][1], r = l ^ 1;
  if (!isroot(y)) c[z][y == c[z][1]] = x;
  fa[c[x][r]] = y;
  fa[y] = x;
  fa[x] = z;
  c[y][l] = c[x][r];
  c[x][r] = y;
  update(y);
  update(x);
}
inline void splay(int x) {
  int top = 0;
  q[++top] = x;
  for (int xx = x; !isroot(xx); xx = fa[xx]) q[++top] = fa[xx];
  while (top) pushdown(q[top--]);
  while (!isroot(x)) {
    int y = fa[x], z = fa[y];
    if (!isroot(y)) {
      if (x == c[y][1] ^ y == c[z][1])
        rotate(x);
      else
        rotate(y);
    }
    rotate(x);
  }
}
inline void access(int x) {
  int y = 0;
  while (x) {
    splay(x);
    c[x][1] = y;
    update(x);
    y = x;
    x = fa[x];
  }
}
inline void makeroot(int x) {
  access(x);
  splay(x);
  rev[x] ^= 1;
}
inline void link(int x, int y) {
  makeroot(x);
  fa[x] = y;
}
inline void cut(int x, int y) {
  makeroot(x);
  access(y);
  splay(y);
  c[y][0] = fa[x] = 0;
  update(y);
}
inline int qmin(int x, int y) {
  makeroot(x);
  access(y);
  splay(y);
  return mn[y];
}
inline int find(int x) {
  access(x);
  splay(x);
  while (c[x][0]) x = c[x][0];
  return x;
}
int main() {
  n = read();
  Q = read();
  mn[0] = 0;
  v[0] = 0x3f3f3f3f;
  for (int i = 1; i <= Q; ++i) {
    int x = read(), y = read();
    if (x > y) swap(x, y);
    int id = mp[make_pair(x, y)];
    if (id)
      qq[i].op = 0, qq[i].id = id, mp[make_pair(x, y)] = 0, v[n + id] = i;
    else
      qq[i].op = 1, qq[i].id = ++m, e[m].x = x, e[m].y = y,
      mp[make_pair(x, y)] = m;
  }
  for (int i = 1; i <= n; ++i) v[i] = 0x3f3f3f3f, mn[i] = i;
  for (int i = 1; i <= m; ++i) {
    if (!v[n + i]) v[n + i] = Q + 1;
    mn[n + i] = n + i;
  }
  for (int i = 1; i <= Q; ++i) {
    int id = qq[i].id, x = e[id].x, y = e[id].y;
    if (qq[i].op) {
      if (find(x) != find(y))
        link(x, id + n), link(id + n, y);
      else {
        makeroot(x);
        access(y);
        splay(y);
        if (sz[y] - 1 >> 1 & 1) {
          int z = qmin(x, y);
          if (v[id + n] <= v[z])
            mark[id] = 2;
          else
            mark[z - n] = 2, cut(e[z - n].x, z), cut(e[z - n].y, z),
                     link(x, id + n), link(id + n, y);
        } else {
          int z = qmin(x, y);
          ++cnt;
          if (v[id + n] <= v[z])
            mark[id] = 1;
          else
            mark[z - n] = 1, cut(e[z - n].x, z), cut(e[z - n].y, z),
                     link(x, id + n), link(id + n, y);
        }
      }
    } else {
      if (!mark[id])
        cut(x, id + n), cut(id + n, y);
      else if (mark[id] == 1)
        --cnt;
    }
    puts(cnt ? "NO" : "YES");
  }
  return 0;
}

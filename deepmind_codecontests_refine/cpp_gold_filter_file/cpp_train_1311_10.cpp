#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool t = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') t = true, ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
  return t ? -x : x;
}
struct Node {
  int ch[2], ff, v, tag;
} t[300300];
int tot, ans, n;
void rotate(int x) {
  int y = t[x].ff, z = t[y].ff;
  int k = t[y].ch[1] == x;
  if (z) t[z].ch[t[z].ch[1] == y] = x;
  t[x].ff = z;
  t[y].ch[k] = t[x].ch[k ^ 1];
  if (t[x].ch[k ^ 1]) t[t[x].ch[k ^ 1]].ff = y;
  t[x].ch[k ^ 1] = y;
  t[y].ff = x;
}
void pushdown(int x) {
  if (!t[x].tag) return;
  int w = t[x].tag;
  if ((t[x].ch[0])) t[(t[x].ch[0])].v += w, t[(t[x].ch[0])].tag += w;
  if ((t[x].ch[1])) t[(t[x].ch[1])].v += w, t[(t[x].ch[1])].tag += w;
  t[x].tag = 0;
}
int S[300300], top, root;
void Splay(int x, int goal) {
  S[top = 1] = x;
  for (int i = x; t[i].ff; i = t[i].ff) S[++top] = t[i].ff;
  while (top) pushdown(S[top--]);
  while (t[x].ff != goal) {
    int y = t[x].ff, z = t[y].ff;
    if (z != goal)
      (t[y].ch[0] == x) ^ (t[z].ch[0] == y) ? rotate(x) : rotate(y);
    rotate(x);
  }
  if (!goal) root = x;
}
int Find(int val) {
  int x = root, ret = 0;
  while (x) {
    pushdown(x);
    if (t[x].v < val)
      ret = x, x = (t[x].ch[1]);
    else
      x = (t[x].ch[0]);
  }
  return ret;
}
int Getnxt(int x) {
  Splay(x, 0);
  x = (t[x].ch[1]);
  while ((t[x].ch[0])) x = (t[x].ch[0]);
  return x;
}
int Getpre(int x) {
  Splay(x, 0);
  x = (t[x].ch[0]);
  while ((t[x].ch[1])) x = (t[x].ch[1]);
  return x;
}
void Delete(int x) {
  int pre = Getpre(x), nxt = Getnxt(x);
  Splay(pre, 0);
  Splay(nxt, pre);
  t[nxt].ch[0] = 0;
  t[x].ff = 0;
}
void Insert(int val) {
  int x = root, fa = 0;
  while (x) {
    pushdown(x);
    fa = x;
    if (t[x].v <= val)
      x = (t[x].ch[1]);
    else
      x = (t[x].ch[0]);
  }
  x = ++tot;
  if (fa) t[fa].ch[t[fa].v <= val] = x;
  t[x].ff = fa;
  t[x].v = val;
  Splay(x, 0);
}
void Solve(int l, int r) {
  int u = Find(l), v = Find(r), nt = Getnxt(v);
  if (u ^ v) {
    Splay(u, 0);
    Splay(nt, u);
    int QwQ = t[nt].ch[0];
    t[QwQ].v += 1;
    t[QwQ].tag += 1;
  }
  if (nt != 2) Delete(nt), --ans;
  Insert(l), ++ans;
}
int main() {
  n = read();
  Insert(-1e9 - 5);
  Insert(+1e9 + 5);
  ans = 0;
  for (int i = 1, l, r; i <= n; ++i) l = read(), r = read(), Solve(l, r);
  printf("%d\n", ans);
  return 0;
}

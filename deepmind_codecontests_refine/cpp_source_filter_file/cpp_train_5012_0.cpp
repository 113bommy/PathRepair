#include <bits/stdc++.h>
using namespace std;
int n, m, sl, fh, cnt, top, T[1000010], col[1000010], stk[1000010];
int t, h[1000010];
struct Tre {
  int to, nxt;
} e[1000010 << 1];
struct LCT {
  int lt, sz, fa, sn[2];
} tr[1000010];
int rd() {
  sl = 0;
  fh = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
void upd(int i, int v) {
  for (; i <= n * 2; i += (i & -i)) T[i] += v;
}
int qry(int i) {
  int res = 0;
  for (; i; i -= (i & -i)) res += T[i];
  return res;
}
void putup(int x) { tr[x].sz = tr[tr[x].sn[0]].sz + tr[tr[x].sn[1]].sz + 1; }
bool nort(int x) { return tr[tr[x].fa].sn[0] == x || tr[tr[x].fa].sn[1] == x; }
void rever(int x) {
  swap(tr[x].sn[0], tr[x].sn[1]);
  tr[x].lt ^= 1;
}
void pushdown(int x) {
  if (tr[x].lt) {
    rever(tr[x].sn[0]);
    rever(tr[x].sn[1]);
    tr[x].lt = 0;
  }
  col[tr[x].sn[0]] = col[tr[x].sn[1]] = col[x];
}
void rotate(int x) {
  int f = tr[x].fa, p = tr[f].fa, k = x == tr[f].sn[1], u = tr[x].sn[k ^ 1];
  if (nort(f)) tr[p].sn[f == tr[p].sn[1]] = x;
  tr[x].fa = p;
  if (u) tr[u].fa = f;
  tr[f].sn[k] = u;
  tr[f].fa = x;
  tr[x].sn[k ^ 1] = f;
  putup(f);
  putup(x);
}
void splay(int x) {
  stk[top = 1] = x;
  for (int y = x; nort(y); y = tr[y].fa, stk[++top] = y)
    ;
  for (; top; --top) pushdown(stk[top]);
  for (int f, p; nort(x); rotate(x)) {
    f = tr[x].fa;
    p = tr[f].fa;
    if (nort(f)) {
      if ((x == tr[f].sn[1]) ^ (f == tr[p].sn[1]))
        rotate(x);
      else
        rotate(f);
    }
  }
}
void access(int x) {
  for (int y = 0; x; y = x, x = tr[x].fa)
    splay(x), tr[x].sn[1] = 0, putup(x), upd(col[x], -tr[x].sz),
              upd(cnt, tr[x].sz), tr[x].sn[1] = y, putup(x);
}
void mkrt(int x) {
  ++cnt;
  access(x);
  splay(x);
  rever(x);
  col[x] = cnt;
}
int getans(int x) {
  splay(x);
  return qry(col[x] - 1) + tr[tr[x].sn[1]].sz + 1;
}
void add(int u, int v) {
  e[++t] = (Tre){v, h[u]};
  h[u] = t;
  e[++t] = (Tre){u, h[v]};
  h[v] = t;
}
void dfs(int u, int f) {
  col[u] = u;
  int v;
  for (int i = h[u]; i; i = e[i].nxt)
    if ((v = e[i].to) != f) {
      dfs(v, u);
      tr[v].fa = u;
      if (col[v] > col[u]) {
        col[u] = col[v];
        tr[u].sn[1] = v;
      }
    }
  upd(col[u], 1);
  putup(u);
}
int main() {
  n = rd();
  m = rd();
  int x, y;
  cnt = n;
  for (int i = 1; i < n; ++i) x = rd(), y = rd(), add(x, y);
  dfs(n, 0);
  char s[10];
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s);
    if (s[0] == 'u')
      mkrt(rd());
    else if (s[0] == 'w')
      printf("%d\n", getans(rd()));
    else
      x = rd(), y = rd(), printf("%d\n", getans(x) < getans(y) ? x : y);
  }
  return 0;
}

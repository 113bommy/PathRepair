#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  int w = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') w |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return w ? -x : x;
}
const int N = 200005;
const int Maxlg = 20;
const int M = 26;
int n, m, nedge, hed[N], num, len[N], ch[N][M], fa[N];
int last, cnt, rot[N], L[N], R[N], val[N], tot;
struct node {
  int sz, son[2];
} tr[N * Maxlg];
struct Edge {
  int to, nex;
} edge[N << 1];
char s[N], ss[N];
void update(int l, int r, int &nod, int x) {
  nod = ++cnt;
  if (l == r) {
    tr[nod].sz++;
    return;
  }
  if (x <= ((l + r) >> 1))
    update(l, ((l + r) >> 1), tr[nod].son[0], x);
  else
    update(((l + r) >> 1) + 1, r, tr[nod].son[1], x);
  tr[nod].sz = tr[tr[nod].son[0]].sz + tr[tr[nod].son[1]].sz;
}
void extend(int i, int c) {
  int p = last;
  int np = ++num;
  update(1, n, rot[np], i);
  len[np] = len[p] + 1;
  while (p && (!ch[p][c])) ch[p][c] = np, p = fa[p];
  if (!p)
    fa[np] = 1;
  else {
    int q = ch[p][c];
    if (len[q] == len[p] + 1)
      fa[np] = q;
    else {
      int nq = ++num;
      len[nq] = len[p] + 1;
      fa[nq] = fa[q];
      for (register int j = 0; j <= 25; j++) ch[nq][j] = ch[q][j];
      fa[q] = fa[np] = nq;
      while (p && (ch[p][c] == q)) ch[p][c] = nq, p = fa[p];
    }
  }
  last = np;
}
int query(int l, int r, int nod, int ll, int rr) {
  if (!nod) return 0;
  if ((l == ll) && (r == rr)) return tr[nod].sz;
  if (rr <= ((l + r) >> 1))
    return query(l, ((l + r) >> 1), tr[nod].son[0], ll, rr);
  else if (ll > ((l + r) >> 1))
    return query(((l + r) >> 1) + 1, r, tr[nod].son[1], ll, rr);
  else
    return query(l, ((l + r) >> 1), tr[nod].son[0], ll, ((l + r) >> 1)) +
           query(((l + r) >> 1) + 1, r, tr[nod].son[1], ((l + r) >> 1) + 1, rr);
}
int merge(int l, int r, int x, int y) {
  if (!x) return y;
  if (!y) return x;
  int o = ++cnt;
  if (l == r) {
    tr[o].sz = tr[x].sz + tr[y].sz;
    return o;
  }
  tr[o].son[0] = merge(l, ((l + r) >> 1), tr[x].son[0], tr[y].son[0]);
  tr[o].son[1] = merge(((l + r) >> 1) + 1, r, tr[x].son[1], tr[y].son[1]);
  tr[o].sz = tr[tr[o].son[0]].sz + tr[tr[o].son[1]].sz;
  return o;
}
void addedge(int a, int b) {
  edge[nedge].to = b;
  edge[nedge].nex = hed[a];
  hed[a] = nedge++;
}
void dfs(int k) {
  for (register int i = hed[k]; ~i; i = edge[i].nex) {
    int v = edge[i].to;
    dfs(v);
    rot[k] = merge(1, n, rot[k], rot[v]);
  }
}
void solve(char *s, int l, int r) {
  int nwn = strlen(s);
  int nw = 1;
  int res = 0, pd = 0;
  for (register int i = 0; i <= nwn; i++) {
    if (l + i > r) break;
    for (register int j = (i == nwn) ? 0 : (s[i] - 'a' + 1); j <= 25; j++) {
      if (!ch[nw][j]) continue;
      int tmp = ch[nw][j];
      if (query(1, n, rot[tmp], l + i, r)) {
        res = i;
        pd = j + 1;
        break;
      }
    }
    if ((i == nwn) || (!ch[nw][s[i] - 'a'])) break;
    nw = ch[nw][s[i] - 'a'];
  }
  if (!pd)
    printf("-1\n");
  else {
    for (register int i = 0; i <= res - 1; i++) putchar(s[i]);
    putchar('a' + (pd - 1));
    putchar('\n');
  }
}
int main() {
  scanf("%s", &s);
  n = strlen(s);
  last = num = 1;
  for (register int i = 1; i <= n; i++) extend(i, s[i - 1] - 'a');
  nedge = 0;
  memset(hed, -1, sizeof(hed));
  for (register int i = 2; i <= num; i++) addedge(fa[i], i);
  dfs(1);
  scanf("%d", &m);
  for (register int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    scanf("%s", &ss);
    solve(ss, l, r);
  }
  return 0;
}

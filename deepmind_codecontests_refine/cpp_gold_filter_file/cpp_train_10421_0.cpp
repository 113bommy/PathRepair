#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
namespace ywy {
inline int get() {
  int n = 0;
  char c;
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
    else
      return (n);
  }
  n = c - '0';
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 - c + '0';
    else
      return (n);
  }
}
char str[210002];
int sam[200001][26], fa[200001], heads[200001], len[200001];
inline int sget() {
  char c;
  register int ptr = 1;
  while ((c = getchar()) || 23333)
    if (c >= 'a' && c <= 'z') break;
  str[ptr] = c;
  ptr++;
  while ((c = getchar()) || 23333) {
    if (c >= 'a' && c <= 'z')
      str[ptr] = c, ptr++;
    else
      return (ptr - 1);
  }
}
typedef struct _b {
  int dest;
  int nxt;
} bian;
bian memchi[200001];
int gnn = 1;
inline void add(int s, int t) {
  memchi[gnn].dest = t;
  memchi[gnn].nxt = heads[s];
  heads[s] = gnn;
  gnn++;
}
int gn = 2;
int n;
int root[200001], lef[10000001], rgh[10000001], data[10000001], gseg = 1, pt;
void insert(int l, int r, int &tree) {
  if (!tree) tree = gseg, gseg++;
  data[tree]++;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (pt <= mid)
    insert(l, mid, lef[tree]);
  else
    insert(mid + 1, r, rgh[tree]);
}
int united(int a, int b) {
  if (!(a && b)) return (a | b);
  int tree = gseg;
  gseg++;
  data[tree] = data[a] + data[b];
  lef[tree] = united(lef[a], lef[b]);
  rgh[tree] = united(rgh[a], rgh[b]);
  return (tree);
}
int query(int rl, int rr, int l, int r, int tree) {
  if (!data[tree]) return (0);
  if (rl == l && rr == r) return (data[tree]);
  int mid = (l + r) >> 1;
  if (rl > mid) return (query(rl, rr, mid + 1, r, rgh[tree]));
  if (rr <= mid) return (query(rl, rr, l, mid, lef[tree]));
  return (query(rl, mid, l, mid, lef[tree]) +
          query(mid + 1, rr, mid + 1, r, rgh[tree]));
}
inline int zhuanyi(int p, int x, int cjr) {
  int me = gn;
  gn++;
  len[me] = len[p] + 1;
  pt = cjr;
  insert(1, n, root[me]);
  while (p && !sam[p][x]) sam[p][x] = me, p = fa[p];
  if (!p) {
    fa[me] = 1;
    return (me);
  }
  int q = sam[p][x];
  if (len[q] == len[p] + 1) {
    fa[me] = q;
    return (me);
  }
  int nq = gn;
  gn++;
  len[nq] = len[p] + 1;
  fa[nq] = fa[q];
  for (register int i = 0; i < 26; i++) sam[nq][i] = sam[q][i];
  fa[q] = fa[me] = nq;
  while (p && sam[p][x] == q) sam[p][x] = nq, p = fa[p];
  return (me);
}
char stk[100002];
void dfs(int pt) {
  for (register int i = heads[pt]; i; i = memchi[i].nxt) {
    dfs(memchi[i].dest);
    root[pt] = united(root[pt], root[memchi[i].dest]);
  }
}
int l, r;
int efs(int pt, int deep) {
  if (deep > (r - l + 1)) return (-1);
  for (register int i = 0; i < 26; i++) {
    if (!sam[pt][i]) continue;
    if (i + 'a' < str[deep]) continue;
    if (!query(l + deep - 1, r, 1, n, root[sam[pt][i]])) continue;
    stk[deep] = i + 'a';
    if (stk[deep] > str[deep]) return (deep);
    int cjr = efs(sam[pt][i], deep + 1);
    if (cjr != -1) return (cjr);
  }
  return (-1);
}
void ywymain() {
  n = sget();
  int p = 1;
  for (register int i = 1; i <= n; i++) p = zhuanyi(p, str[i] - 'a', i);
  for (register int i = 2; i < gn; i++) add(fa[i], i);
  dfs(1);
  int m = get();
  while (m) {
    m--;
    l = get(), r = get();
    int g = sget();
    str[g + 1] = 0;
    int cjr = efs(1, 1);
    if (cjr == -1)
      printf("-1\n");
    else {
      for (register int i = 1; i <= cjr; i++) putchar(stk[i]);
      putchar('\n');
    }
  }
}
}  // namespace ywy
int main() {
  ywy::ywymain();
  return (0);
}

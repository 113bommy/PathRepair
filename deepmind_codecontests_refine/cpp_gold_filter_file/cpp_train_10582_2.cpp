#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, blk = 2150, sqrtn = 666;
struct node {
  int l, r, t, b1, b2, id;
  node() {}
  node(int L, int R, int T, int i) {
    l = L, r = R, t = T, id = i;
    b1 = l / blk, b2 = r / blk;
  }
  friend bool operator<(node a, node b) {
    if (a.b1 != b.b1) return a.b1 < b.b1;
    if (a.b2 != b.b2) return a.b2 < b.b2;
    return a.t < b.t;
  }
} p[maxn];
struct chnode {
  int x, y, pre;
  chnode() {}
  chnode(int X, int Y, int p) { x = X, y = Y, pre = p; }
} q[maxn];
int n, m, a[maxn], pre[maxn], l = 1, r, t, cnt[maxn], cc[maxn], qc, ac, cn,
                              sum[maxn], bc;
map<int, int> maps;
void revise(int x, bool v) {
  if (cnt[x] < sqrtn) cc[cnt[x]]--;
  v ? cnt[x]++ : cnt[x]--;
  if (cnt[x] < sqrtn) cc[cnt[x]]++;
}
void change(int x, int c) {
  if (x >= l && x <= r) revise(a[x], 0), revise(c, 1);
  a[x] = c;
}
void md(int i) {
  while (t < p[i].t) t++, change(q[t].x, q[t].y);
  while (t > p[i].t) change(q[t].x, q[t].pre), t--;
  while (l > p[i].l) revise(a[--l], 1);
  while (r < p[i].r) revise(a[++r], 1);
  while (l < p[i].l) revise(a[l++], 0);
  while (r > p[i].r) revise(a[r--], 0);
  for (register int j = 1; j <= sqrtn; j++) {
    if (!cc[j]) {
      sum[p[i].id] = j;
      break;
    }
  }
}
int main() {
  int op, x, y;
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (!maps[a[i]]) maps[a[i]] = ++bc;
    a[i] = maps[a[i]], pre[i] = a[i];
  }
  for (register int i = 1; i <= m; i++) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      qc++, p[qc] = node(x, y, ac, qc);
    else {
      if (!maps[y]) maps[y] = ++bc;
      y = maps[y], q[++ac] = chnode(x, y, pre[x]), pre[x] = y;
    }
  }
  sort(p + 1, p + qc + 1);
  for (register int i = 1; i <= qc; i++) md(i);
  for (register int i = 1; i <= qc; i++) printf("%d\n", sum[i]);
}

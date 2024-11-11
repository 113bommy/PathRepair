#include <bits/stdc++.h>
using namespace std;
int n, k, m;
set<pair<int, int>> ssp;
struct Node {
  int l, r, v, key, sum, lz, maxn, hexin;
} nd[200005 << 1];
int cnt = 1, root;
inline int newNode(int x, int hx) {
  nd[cnt].hexin = hx, nd[cnt].key = rand(), nd[cnt].sum = 1,
  nd[cnt].v = nd[cnt].maxn = x;
  return cnt++;
}
inline void upd(int x) {
  nd[x].sum = 1 + nd[nd[x].l].sum + nd[nd[x].r].sum;
  nd[x].maxn = max(nd[x].v, max(nd[nd[x].l].maxn, nd[nd[x].r].maxn));
}
inline void make(int x, int p) { nd[x].v += p, nd[x].maxn += p, nd[x].lz += p; }
inline void pud(int x) {
  if (nd[x].lz == 0) return;
  if (nd[x].l) make(nd[x].l, nd[x].lz);
  if (nd[x].r) make(nd[x].r, nd[x].lz);
  nd[x].lz = 0;
}
void split(int rt, int& a, int& b, int v) {
  if (rt == 0) {
    a = b = 0;
    return;
  }
  pud(rt);
  if (nd[rt].hexin < v)
    a = rt, split(nd[rt].r, nd[a].r, b, v);
  else
    b = rt, split(nd[rt].l, a, nd[b].l, v);
  upd(rt);
}
void merge(int& rt, int a, int b) {
  if (a == 0 || b == 0) {
    rt = a + b;
    return;
  }
  pud(a), pud(b);
  if (nd[a].key > nd[b].key)
    rt = a, merge(nd[rt].r, nd[a].r, b);
  else
    rt = b, merge(nd[rt].l, a, nd[b].l);
  upd(rt);
}
int main() {
  srand(time(nullptr));
  scanf("%d%d%d", &n, &k, &m);
  nd[0].maxn = -0x3f3f3f3f;
  while (m--) {
    int x, y, a, b, c, v;
    scanf("%d%d", &x, &y);
    v = y + abs(x - k);
    if (ssp.count(make_pair(x, y))) {
      ssp.erase(make_pair(x, y));
      split(root, a, c, v), split(c, b, c, v + 1);
      merge(a, a, nd[b].l), merge(c, nd[b].r, c);
      if (c) make(c, 1);
      merge(root, a, c);
    } else {
      ssp.insert(make_pair(x, y));
      split(root, a, c, v);
      merge(a, a, newNode(v - nd[a].sum - 1, v));
      if (c) make(c, -1);
      merge(root, a, c);
    }
    printf("%d\n", nd[root].sum + nd[root].maxn - n);
  }
  return 0;
}

#include <bits/stdc++.h>
int n, m, p, k;
struct node {
  node *lc, *rc;
  int sz, add, mak, l, a[5], b[5];
  void pushup() {
    l = lc->l;
    for (int j = 0; j < l; ++j) a[j] = lc->a[j], b[j] = lc->b[j];
    for (int j = 0; j < rc->l; ++j) {
      int same = 0;
      for (int i = 0; i < l; ++i)
        if (a[i] == rc->a[j]) {
          same = 1;
          b[i] += rc->b[j];
          break;
        }
      if (same) continue;
      if (l < k) {
        a[l] = rc->a[j], b[l] = rc->b[j];
        ++l;
        continue;
      }
      int c = rc->b[j];
      for (int i = 0; i < l; ++i)
        if (c > b[i]) c = b[i];
      int p = 0;
      for (int i = 0; i < l; ++i)
        if (b[i] > c) a[p] = a[i], b[p] = b[i] - c, ++p;
      if (rc->b[j] > c) a[p] = rc->a[j], b[p] = rc->b[j] - c, ++p;
      l = p;
    }
  }
  void A() {
    ++add;
    for (int j = 0; j < l; ++j) ++a[j];
  }
  void M(int v) {
    add = 0;
    mak = v;
    l = 1;
    a[0] = v;
    b[0] = sz;
  }
  void pushdown() {
    if (mak) lc->M(mak), rc->M(mak), mak = add = 0;
    if (add) lc->A(), rc->A(), add = 0;
  }
} * buf, *root, *q;
int ind;
node *build(int l, int r) {
  node *p = &buf[ind++];
  p->mak = p->add = 0;
  p->sz = r - l + 1;
  if (l == r) {
    p->l = p->b[0] = 1;
    scanf("%d", p->a);
    return p;
  }
  p->lc = build(l, (l + r) / 2), p->rc = build((l + r) / 2 + 1, r);
  return p->pushup(), p;
}
void upd(node *p, int l, int r, int pl, int pr, int c) {
  if (l > pr || r < pl) return;
  if (l >= pl && r <= pr) return c ? p->M(c) : p->A();
  p->pushdown();
  int m = (l + r) >> 1;
  upd(p->lc, l, m, pl, pr, c);
  upd(p->rc, m + 1, r, pl, pr, c);
  p->pushup();
}
void query(node *p, int l, int r, int pl, int pr) {
  if (l > pr || r < pl) return;
  if (l >= pl && r <= pr) return q->rc = p, q->pushup();
  p->pushdown();
  int m = (l + r) >> 1;
  query(p->lc, l, m, pl, pr);
  query(p->rc, m + 1, r, pl, pr);
}
int main() {
  scanf("%d %d %d", &n, &m, &p);
  k = 100 / p;
  buf = new node[n << 1 | 7];
  root = build(1, n);
  q = &buf[ind++];
  q->lc = q;
  for (int opt, l, r, c; m; m--) {
    scanf("%d %d %d", &opt, &l, &r);
    if (opt == 1)
      scanf("%d", &c), upd(root, 1, n, l, r, c);
    else if (opt == -1)
      upd(root, 1, n, l, r, 0);
    else {
      q->l = 0;
      query(root, 1, n, l, r);
      printf("%d", q->l);
      for (int j = 0; j < q->l; ++j) printf(" %d", q->a[j]);
      puts("");
    }
  }
  return 0;
}

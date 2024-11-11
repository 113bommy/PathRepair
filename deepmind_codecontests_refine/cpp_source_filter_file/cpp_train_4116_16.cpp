#include <bits/stdc++.h>
using namespace std;
const int N = 150010;
int n, m, p, rd[N];
struct node {
  int a[7], b[7], sz, lz, len;
  node() {
    len = 0;
    sz = 0;
    lz = 0;
  }
} tr[N << 2];
node operator+(node x, node y) {
  node z;
  z = y;
  z.len += x.len;
  z.lz = 0;
  for (int i = 0; i < x.sz; i++) {
    bool fl = 0;
    for (int j = 0; j < z.sz; j++)
      if (z.a[j] == x.a[i]) {
        z.b[j] += x.b[i], fl = 1;
        break;
      }
    if (fl) continue;
    if (z.sz < p) {
      z.a[z.sz] = x.a[i];
      z.b[z.sz] = x.b[i];
      z.sz++;
      continue;
    }
    int k = 0;
    for (int j = 0; j < p; j++)
      if (z.b[j] < z.b[k]) k = j;
    if (z.b[k] > x.b[i]) {
      for (int j = 0; j < p; j++) z.b[j] -= x.b[i];
    } else {
      int t = z.b[k];
      z.a[k] = x.b[i];
      z.b[k] = x.b[i];
      for (int j = 0; j < p; j++) z.b[j] -= t;
    }
  }
  return z;
}
void build(int rt, int l, int r) {
  if (l == r) {
    tr[rt].a[0] = rd[l];
    tr[rt].b[0] = 1;
    tr[rt].sz = 1;
    tr[rt].len = 1;
    return;
  }
  int mid = l + r >> 1;
  build(((rt) << 1), l, mid);
  build(((rt) << 1 | 1), mid + 1, r);
  tr[rt] = tr[((rt) << 1)] + tr[((rt) << 1 | 1)];
  return;
}
void pushdown(int rt) {
  if (tr[rt].lz != 0) {
    tr[((rt) << 1)].lz = tr[rt].lz;
    tr[((rt) << 1)].sz = 1;
    tr[((rt) << 1)].a[0] = tr[rt].lz;
    tr[((rt) << 1)].b[0] = tr[((rt) << 1)].len;
    tr[((rt) << 1 | 1)].lz = tr[rt].lz;
    tr[((rt) << 1 | 1)].sz = 1;
    tr[((rt) << 1 | 1)].a[0] = tr[rt].lz;
    tr[((rt) << 1 | 1)].b[0] = tr[((rt) << 1 | 1)].len;
    tr[rt].lz = 0;
  }
}
void update(int rt, int l, int r, int L, int R, int valu) {
  if (L <= l && r <= R) {
    tr[rt].lz = valu;
    tr[rt].a[0] = valu;
    tr[rt].b[0] = tr[rt].len;
    tr[rt].sz = 1;
    return;
  }
  pushdown(rt);
  int mid = l + r >> 1;
  if (L <= mid) update(((rt) << 1), l, mid, L, R, valu);
  if (R > mid) update(((rt) << 1 | 1), mid + 1, r, L, R, valu);
  tr[rt] = tr[((rt) << 1)] + tr[((rt) << 1 | 1)];
  return;
}
node query(int rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) return tr[rt];
  pushdown(rt);
  int mid = l + r >> 1;
  node ret;
  if (L <= mid) ret = ret + query(((rt) << 1), l, mid, L, R);
  if (R > mid) ret = ret + query(((rt) << 1 | 1), mid + 1, r, L, R);
  tr[rt] = tr[((rt) << 1)] + tr[((rt) << 1 | 1)];
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  p = 100 / p;
  for (int i = 1; i <= n; i++) scanf("%d", &rd[i]);
  build(1, 1, n);
  while (m--) {
    int tp, l, r, valu;
    scanf("%d%d%d", &tp, &l, &r);
    if (tp == 1) {
      scanf("%d", &valu);
      update(1, 1, n, l, r, valu);
    } else {
      node tmp = query(1, 1, n, l, r);
      printf("%d ", tmp.sz);
      for (int i = 0; i < tmp.sz; i++) printf("%d ", tmp.a[i]);
      puts("");
    }
  }
  return 0;
}

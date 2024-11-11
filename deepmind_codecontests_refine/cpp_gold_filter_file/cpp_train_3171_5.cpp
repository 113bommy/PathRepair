#include <bits/stdc++.h>
using namespace std;
int n, q, l, r;
int tree[2 * 1234567];
int line[1234567];
void build(int v, int l, int r) {
  if (l + 1 == r) {
    tree[v] = 1;
    line[r] = 1;
    return;
  }
  int ls = v << 1, rs = ls + 1, mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid, r);
  tree[v] = tree[ls] + tree[rs];
}
void update(int v, int l, int r, int whe, int val) {
  if (whe <= l || whe > r) return;
  if (l == r - 1 && r == whe) {
    tree[v] = val;
    line[whe] = val;
    return;
  }
  int midn = (l + r) >> 1, ls = v << 1, rs = ls + 1;
  update(ls, l, midn, whe, val);
  update(rs, midn, r, whe, val);
  tree[v] = tree[ls] + tree[rs];
}
int query(int v, int l, int r, int ql, int qr) {
  if (r <= ql || l >= qr) return 0;
  if (ql <= l && r <= qr) return tree[v];
  int midn = (l + r) >> 1, ls = v << 1, rs = ls + 1;
  return query(ls, l, midn, ql, qr) + query(rs, midn, r, ql, qr);
}
void init() {
  scanf("%d%d", &n, &q);
  l = 0;
  r = n;
  build(1, 0, n);
}
void solve() {
  int rev = 0;
  for (int t = 1; t <= q; t++) {
    int tmp;
    scanf("%d", &tmp);
    if (tmp == 1) {
      int pos;
      scanf("%d", &pos);
      if (rev) rev = 0, pos = r - l - pos;
      if (pos <= (r - l) >> 1) {
        for (int i = 0; i < pos; i++) {
          update(1, 0, n, l + pos + i + 1,
                 line[l + pos + i + 1] + line[l + pos - i]);
          update(1, 0, n, l + pos - i, 0);
        }
        l = l + pos;
      } else {
        for (int i = 0; i < r - (l + pos); i++) {
          update(1, 0, n, l + pos - i,
                 line[l + pos - i] + line[l + pos + i + 1]);
          update(1, 0, n, l + pos + i + 1, 0);
        }
        r = l + pos;
        rev ^= 1;
      }
    } else {
      int posl, posr;
      scanf("%d%d", &posl, &posr);
      if (rev) {
        int tmp = posr;
        posr = (r - l) - posl;
        posl = (r - l) - tmp;
      }
      printf("%d\n", query(1, 0, n, l + posl, l + posr));
    }
  }
}
int main() {
  init();
  solve();
}

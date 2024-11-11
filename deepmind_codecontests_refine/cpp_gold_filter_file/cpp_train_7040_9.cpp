#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
double seg[N * 4], m[N * 4], ad[N * 4];
int a[N];
void init(int pos, int l, int r) {
  m[pos] = 1, ad[pos] = 0;
  if (l == r) {
    seg[pos] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  init(pos * 2, l, mid), init(pos * 2 + 1, mid + 1, r);
  seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}
void push(int pos, int l, int r) {
  seg[pos] = seg[pos] * m[pos] + (r - l + 1) * ad[pos];
  if (l != r) {
    m[pos * 2] *= m[pos];
    ad[pos * 2] *= m[pos];
    ad[pos * 2] += ad[pos];
    m[pos * 2 + 1] *= m[pos];
    ad[pos * 2 + 1] *= m[pos];
    ad[pos * 2 + 1] += ad[pos];
  }
  m[pos] = 1, ad[pos] = 0;
}
double query(int pos, int l, int r, int ql, int qr) {
  push(pos, l, r);
  if (r < ql || qr < l) return 0;
  if (ql <= l && r <= qr) return seg[pos];
  int mid = (l + r) >> 1;
  return query(pos * 2, l, mid, ql, qr) +
         query(pos * 2 + 1, mid + 1, r, ql, qr);
}
void update(int pos, int l, int r, int ql, int qr, double mul, double add) {
  push(pos, l, r);
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    m[pos] = mul;
    ad[pos] = add;
    push(pos, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  update(pos * 2, l, mid, ql, qr, mul, add),
      update(pos * 2 + 1, mid + 1, r, ql, qr, mul, add);
  seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}
void solve() {
  int n, q;
  scanf("%d %d ", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  init(1, 1, n);
  while (q--) {
    int type, l1, r1;
    scanf("%d %d %d ", &type, &l1, &r1);
    if (type == 1) {
      int l2, r2;
      scanf("%d %d ", &l2, &r2);
      double a1 = query(1, 1, n, l1, r1), a2 = query(1, 1, n, l2, r2);
      double len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
      update(1, 1, n, l1, r1, (len1 - 1) / len1, a2 / (len1 * len2)),
          update(1, 1, n, l2, r2, (len2 - 1) / len2, a1 / (len1 * len2));
    } else {
      printf("%0.9lf\n", query(1, 1, n, l1, r1));
    }
  }
}
int main() {
  solve();
  return 0;
}

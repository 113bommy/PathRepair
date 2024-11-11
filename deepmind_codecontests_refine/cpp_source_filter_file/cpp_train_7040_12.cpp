#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, off = 1 << 17;
int n, q;
long double tour[2 * off];
long double prop1[2 * off], prop2[2 * off];
int ql, qr;
int ul, ur;
long double uadd, ulen;
inline void prop(int i, int l, int r) {
  if (prop1[i] != 1.0 || prop2[i] != 0.0) {
    tour[i] = tour[i] * prop1[i] + (r - l + 1) * prop2[i];
    if (l != r) {
      prop1[i * 2 + 0] *= prop1[i];
      prop1[i * 2 + 1] *= prop1[i];
      prop2[i * 2 + 0] = prop2[i * 2 + 0] * prop1[i] + prop2[i];
      prop2[i * 2 + 1] = prop2[i * 2 + 1] * prop1[i] + prop2[i];
    }
    prop1[i] = 1.0;
    prop2[i] = 0.0;
  }
}
long double t_query(int i, int l, int r) {
  prop(i, l, r);
  if (l >= ql && r <= qr) {
    return tour[i];
  }
  if (l > qr || r < ql) {
    return 0.0;
  }
  int m = (l + r + 1) / 2;
  return t_query(i * 2, l, m - 1) + t_query(i * 2 + 1, m, r);
}
long double t_query(int l, int r) {
  ql = l, qr = r;
  return t_query(1, 1, off);
}
long double t_update(int i, int l, int r) {
  prop(i, l, r);
  if (l >= ul && r <= ur) {
    prop1[i] = ulen;
    prop2[i] = uadd;
    prop(i, l, r);
    return tour[i];
  }
  if (l > ur || r < ul) {
    return tour[i];
  }
  int m = (l + r + 1) / 2;
  return tour[i] = t_update(i * 2, l, m - 1) + t_update(i * 2 + 1, m, r);
}
void t_update(int l, int r, long double x) {
  ul = l, ur = r, uadd = x, ulen = 1.0 - 1.0 / (r - l + 1);
  t_update(1, 1, off);
}
int main() {
  scanf("%d%d", &n, &q);
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    tour[off + i] = x;
  }
  for (int i = 1; i < 2 * off; i++) {
    prop1[i] = 1.0;
  }
  for (int i = off - 1; i > 0; i--) {
    tour[i] = tour[i * 2] + tour[i * 2 + 1];
  }
  int id, l1, r1, l2, r2;
  long double ans1, ans2;
  for (int it = 0; it < q; it++) {
    scanf("%d%d%d", &id, &l1, &r1);
    if (id == 1) {
      scanf("%d%d", &l2, &r2);
      ans1 = t_query(l1, r1) / (r1 - l1 + 1);
      ans2 = t_query(l2, r2) / (r2 - l2 + 1);
      t_update(l1, r1, ans2 / (r1 - l1 + 1));
      t_update(l2, r2, ans1 / (r2 - l2 + 1));
    } else {
      printf("%.8llf\n", t_query(l1, r1));
    }
  }
  return 0;
}

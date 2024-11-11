#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
const int inf = 1e18 + 1;
struct sg_tree {
  int l, r;
  long long A, B, rmax;
} ss[maxn << 2];
int n;
int lenth, q;
long long d[maxn], h[maxn], sum[maxn];
void push_up(int k) {
  int ls = (k << 1) + 1;
  int rs = ls + 1;
  ss[k].rmax = max(ss[ls].B + ss[rs].A, max(ss[ls].rmax, ss[rs].rmax));
  ss[k].A = max(ss[ls].A, ss[rs].A);
  ss[k].B = max(ss[ls].B, ss[rs].B);
}
void build(int k, int l, int r) {
  ss[k].l = l;
  ss[k].r = r;
  if (l == r) {
    if (l >= lenth << 1)
      ss[k].A = ss[k].B = ss[k].rmax = -inf;
    else if (l >= lenth) {
      ss[k].A = h[l - lenth] * 2 + sum[l];
      ss[k].B = h[l - lenth] * 2 - sum[l];
      ss[k].rmax = h[l - lenth] << 1;
    } else {
      ss[k].A = h[l] * 2 + sum[l];
      ss[k].B = h[l] * 2 - sum[l];
      ss[k].rmax = h[l] << 1;
    }
    return;
  }
  build((k << 1) + 1, l, (l + r) / 2);
  build((k << 1) + 2, (l + r) / 2 + 1, r);
  push_up(k);
}
void init(int _n) {
  n = 1;
  while (n < _n) n *= 2;
  build(0, 0, n - 1);
}
void query(int k, int a, int b, sg_tree &x) {
  if (b < ss[k].l || a > ss[k].r) return;
  if (a <= ss[k].l && ss[k].r <= b) {
    x = ss[k];
    return;
  } else {
    sg_tree m1, m2;
    m1.A = m1.B = m1.rmax = -inf;
    m2.A = m2.B = m2.rmax = -inf;
    query((k << 1) + 1, a, b, m1);
    query((k << 1) + 2, a, b, m2);
    x.rmax = max(m2.A + m1.B, max(m1.rmax, m2.rmax));
    x.A = max(m1.A, m2.A);
    x.B = max(m1.B, m2.B);
    return;
  }
}
void debug() {
  cout << endl;
  cout << endl;
  for (int i = 0; i < (n << 1) - 1; i++)
    printf("l=%d r=%d k=%d rmax=%lld A=%lld B=%lld\n", ss[i].l, ss[i].r, i,
           ss[i].rmax, ss[i].A, ss[i].B);
  cout << endl;
}
int main() {
  int a, b;
  scanf("%d%d", &lenth, &q);
  for (int i = 0; i < lenth; i++) scanf("%lld", &d[i]);
  for (int i = 0; i < lenth; i++) scanf("%lld", &h[i]);
  sum[0] = 0;
  for (int i = 1; i < lenth; i++) sum[i] = sum[i - 1] + d[i - 1];
  sum[lenth] = sum[lenth - 1] + d[lenth - 1];
  for (int i = lenth + 1; i < lenth << 1; i++)
    sum[i] = sum[i - 1] + d[i - lenth - 1];
  init(lenth << 1);
  while (q--) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    sg_tree mid;
    mid.A = mid.B = mid.rmax = -1;
    if (a <= b)
      query(0, b + 1, a + lenth - 1, mid);
    else
      query(0, min(a, b) + 1, max(a, b) - 1, mid);
    printf("%lld\n", mid.rmax);
  }
  return 0;
}

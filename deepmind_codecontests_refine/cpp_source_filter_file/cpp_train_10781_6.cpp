#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
struct Node {
  long long l, r, add;
  int lu, ld, ru, rd, len, mx;
};
int sz = 1;
Node t[N << 2];
void update(int k) {
  const Node &l = t[k << 1], &r = t[k << 1 | 1];
  t[k].l = l.l, t[k].r = r.r;
  t[k].ld = l.ld + (l.ld == l.len && r.l < l.r ? r.ld : 0);
  t[k].ru = r.ru + (r.ru == r.len && l.r < r.l ? l.ru : 0);
  t[k].lu = l.lu;
  if (l.ru == l.len && l.r < r.l)
    t[k].lu = max(t[k].lu, l.len + max(r.lu, r.ld));
  if (l.lu == l.len && l.r > r.l) t[k].lu = max(t[k].lu, l.len + r.ld);
  t[k].rd = r.rd;
  if (r.ld == r.len && r.l > l.r)
    t[k].rd = max(t[k].rd, r.len + max(l.rd, l.ru));
  if (r.rd == r.len && r.l < l.r) t[k].rd = max(t[k].rd, r.len + l.ru);
  t[k].mx = max(l.mx, r.mx);
  if (l.r < r.l) t[k].mx = max(t[k].mx, l.ru + max(r.lu, r.ld));
  if (l.r > r.l) t[k].mx = max(t[k].mx, r.ld + max(l.ru, l.rd));
}
void pushdown(int k) {
  if (t[k].add == 0) return;
  t[k].l += t[k].add, t[k].r += t[k].add;
  if (k < sz) t[k << 1].add += t[k].add, t[k << 1 | 1].add += t[k].add;
  t[k].add = 0;
}
void modify(int k, int l, int r, int a, int b, int x) {
  pushdown(k);
  if (a > r || b < l) return;
  if (a >= l && b <= r) {
    t[k].add += x;
    pushdown(k);
    return;
  }
  int mid = (a + b) >> 1;
  modify(k << 1, l, r, a, mid, x), modify(k << 1 | 1, l, r, mid + 1, b, x);
  update(k);
}
int n, m;
int val[N];
void build(int k, int a, int b) {
  if (a > n) return;
  if (a == b) {
    t[k].l = t[k].r = val[a], t[k].add = 0;
    t[k].lu = t[k].ru = t[k].ld = t[k].rd = t[k].len = t[k].mx = 1;
    return;
  }
  int mid = (a + b) >> 1;
  build(k << 1, a, mid), build(k << 1 | 1, mid + 1, b);
  update(k);
  t[k].len = t[k << 1].len + t[k << 1 | 1].len;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  while (sz < n) sz <<= 1;
  build(1, 1, sz);
  scanf("%d", &m);
  while (m--) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    modify(1, l, r, 1, sz, d);
    printf("%d\n", t[1].mx);
  }
  return 0;
}

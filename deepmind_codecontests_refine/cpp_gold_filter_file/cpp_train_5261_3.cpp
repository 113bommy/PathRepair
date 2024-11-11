#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct P {
  int l, r, id;
  P(int l, int r, int id) : l(l), r(r), id(id) {}
  P() {}
  bool operator<(const P& x) const { return l < x.l; }
};
P p[maxn];
int v[maxn * 2], tot, ans[maxn], c[maxn << 1], n;
int lowbit(int x) { return x & -x; }
void add(int x, int d) {
  for (int i = x; i <= tot; i += lowbit(i)) c[i] += d;
}
int sum(int x) {
  int ret = 0;
  while (x) {
    ret += c[x];
    x -= lowbit(x);
  }
  return ret;
}
int main() {
  int x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    p[i] = P(x, y, i);
    v[tot++] = x, v[tot++] = y;
  }
  sort(v, v + tot);
  tot = unique(v, v + tot) - v;
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    p[i].l = lower_bound(v, v + tot, p[i].l) - v + 1;
    p[i].r = lower_bound(v, v + tot, p[i].r) - v + 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    ans[p[i].id] = sum(p[i].r) - sum(p[i].l - 1);
    add(p[i].r, 1);
  }
  for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  return 0;
}

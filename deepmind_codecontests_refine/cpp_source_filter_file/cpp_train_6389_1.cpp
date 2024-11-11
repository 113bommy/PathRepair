#include <bits/stdc++.h>
using namespace std;
struct seg {
  int l, r, v;
} t[2][100005 << 2];
map<int, int> c[2];
int n, m, p, h;
inline int max(int a, int b) { return a > b ? a : b; }
void build(int z, int k, int l, int r) {
  t[z][k] = (seg){l, r, 0};
  if (l + 1 < r) {
    int a = (l + r) >> 1;
    build(z, ((k) << 1), l, a);
    build(z, ((k) << 1 | 1), a, r);
  }
}
void update(int z, int k, int p, int v) {
  if (t[z][k].l + 1 == t[z][k].r)
    t[z][k].v = v;
  else {
    update(z, p <= ((t[z][k].l + t[z][k].r) >> 1) ? ((k) << 1) : ((k) << 1 | 1),
           p, v);
    t[z][k].v = max(t[z][((k) << 1)].v, t[z][((k) << 1 | 1)].v);
  }
}
int query(int z, int k, int l, int r) {
  if (l >= r) return 0;
  if (l <= t[z][k].l && r >= t[z][k].r) return t[z][k].v;
  int a = (t[z][k].l + t[z][k].r) >> 1;
  return r <= a ? query(z, ((k) << 1), l, r)
         : l >= a
             ? query(z, ((k) << 1 | 1), l, r)
             : max(query(z, ((k) << 1), l, r), query(z, ((k) << 1 | 1), l, r));
}
int main() {
  scanf("%d%d", &n, &m);
  build(0, 1, 0, n);
  build(1, 1, -100005, 10);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &p);
    if (p == 1) {
      scanf("%d%d", &p, &h);
      h -= i;
      c[0][p] = h;
      c[1][h] = p;
      auto k = c[1].begin();
      for (int j = 0; j < 10 && k != c[1].end(); ++j, ++k)
        update(0, 1, k->second, 0);
      do {
        --k;
        int f = query(0, 1, k->second, n) + 1;
        update(0, 1, k->second, f);
        update(1, 1, k->first, f);
      } while (k != c[1].begin());
    } else {
      scanf("%d", &p);
      auto k = c[0].begin();
      while (--p) ++k;
      int a = k->first, b = k->second;
      update(0, 1, a, 0);
      update(1, 1, b, 0);
      c[0].erase(a);
      c[1].erase(b);
      if (c[0].size()) {
        k = c[0].begin();
        for (int j = 0; j < 10 && k != c[0].end(); ++j, ++k)
          update(1, 1, k->second, 0);
        do {
          --k;
          int f = query(1, 1, k->second, 10) + 1;
          update(0, 1, k->first, f);
          update(1, 1, k->second, f);
        } while (k != c[0].begin());
      }
    }
    printf("%d\n", query(0, 1, 0, n));
  }
  return 0;
}

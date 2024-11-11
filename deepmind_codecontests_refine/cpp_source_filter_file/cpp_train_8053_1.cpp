#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y;
  pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  inline bool read() { return scanf("%d%d", &x, &y) == 2; }
  inline long long abs() const { return (long long)x * x + (long long)y * y; }
};
inline pt operator-(const pt &p1, const pt &p2) {
  return pt(p1.x - p2.x, p1.y - p2.y);
}
const int maxn = (int)1e5 + 1;
pt ps[maxn];
int ys[maxn];
int a[2], b[2];
int n;
int typeComp;
inline long long getfunc(const pt &p) {
  return (long long)a[typeComp] * p.x - (long long)b[typeComp] * p.y;
}
inline bool myfunc(const pt &p1, const pt &p2) {
  return getfunc(p1) != getfunc(p2) ? getfunc(p1) < getfunc(p2)
                                    : p1.abs() < p2.abs();
}
struct SegmTree {
  const static int maxn = 1 << 17;
  int a[2 * maxn];
  int n;
  void build(int _n) {
    for (n = 1; n < _n; n <<= 1)
      ;
    for (int i = 1; i < 2 * n; i++) a[i] = 0;
  }
  void update(int x, int newval) {
    x += n;
    a[x] = max(a[x], newval);
    for (x >>= 1; x; x >>= 1) a[x] = max(a[x * 2], a[x * 2 + 1]);
  }
  int get(int v, int l, int r, int l0, int r0) {
    if (l >= r0 || l0 >= r) return 0;
    if (l0 <= l && r <= r0) return a[v];
    return max(get(2 * v, l, (l + r) / 2, l0, r0),
               get(2 * v + 1, (l + r) / 2, r, l0, r0));
  }
  int get(int l, int r) { return get(1, 0, n, l, r); }
};
SegmTree S;
int main() {
  while (scanf("%d%d/%d%d/%d", &n, &a[0], &b[0], &a[1], &b[1]) >= 1) {
    a[1] = -a[1], b[1] = -b[1];
    for (int i = 0; i < n; i++) assert(ps[i].read());
    ps[n++] = pt(0, 0);
    typeComp = 1;
    for (int i = 0; i < n; i++) ys[i] = getfunc(ps[i]);
    sort(ys, ys + n);
    int m = unique(ys, ys + n) - ys;
    S.build(m);
    typeComp = 0;
    sort(ps, ps + n, myfunc);
    typeComp = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int y = lower_bound(ys, ys + m, getfunc(ps[i])) - ys;
      int d = S.get(0, y) + 1;
      S.update(y, d);
      if (!ps[i].x && !ps[i].y) ans = d;
    }
    printf("%d\n", ans - 1);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline int read() {
  static int x;
  scanf("%d", &x);
  return x;
}
const int N = 4e5 + 5;
int n, m;
int p[N], s[N], b[N];
int ans[N];
struct P {
  int x, y, i;
} a[N];
bool Pcmp_x(const P &u, const P &v) { return u.x < v.x; }
bool Pcmp_y(const P &u, const P &v) { return u.y < v.y; }
struct bitr {
  int n, c[N << 2];
  void init(int _n) {
    n = _n;
    memset(c, 0, sizeof c);
  }
  void add(int x, int v) {
    assert(abs(v) <= 1);
    assert(x <= n && x >= 1);
    for (; x <= n; x += x & (-x)) c[x] += v;
  }
  int sum(int x, int ret = 0) {
    assert(x <= n && x >= 1);
    for (; x; x -= x & (-x)) ret += c[x];
    return ret;
  }
};
struct interv {
  int l, r, v;
  bool operator<(const interv &o) const { return r == o.r ? v < o.v : r > o.r; }
};
struct triangle {
  int x, y, v;
};
bool Tcmp_x(const triangle &u, const triangle &v) { return u.x < v.x; }
bool Tcmp_y(const triangle &u, const triangle &v) { return u.y < v.y; }
int nt;
triangle tri[N << 1];
int nf;
interv f[N << 2];
int nv, val[N << 3];
bitr t;
namespace Triangles {
void discrete() {
  nv = 0;
  for (int i = 1; i <= nf; ++i) val[++nv] = f[i].l, val[++nv] = f[i].r;
  sort(val + 1, val + 1 + nv), nv = unique(val + 1, val + 1 + nv) - val - 1;
  for (int i = 1; i <= nf; ++i) {
    f[i].l = lower_bound(val + 1, val + 1 + nv, f[i].l) - val;
    f[i].r = lower_bound(val + 1, val + 1 + nv, f[i].r) - val;
  }
  sort(f + 1, f + 1 + nf);
}
void main_solve() {
  sort(a + 1, a + m + 1, Pcmp_x);
  nt = 0;
  for (int i = 1; i <= n; ++i) {
    tri[++nt] = (triangle){p[i], b[i], 0};
    tri[++nt] = (triangle){s[i] + 1, b[i] + s[i] - p[i] + 1, -1};
  }
  sort(tri + 1, tri + nt + 1, Tcmp_x);
  int limit = max(a[m].x, tri[nt].x);
  nf = 0;
  for (int i = 1; i <= nt; ++i)
    f[++nf] = (interv){tri[i].y - (limit - tri[i].x),
                       tri[i].y + (limit - tri[i].x), tri[i].v};
  for (int i = 1; i <= m; ++i)
    f[++nf] =
        (interv){a[i].y - (limit - a[i].x), a[i].y + (limit - a[i].x), a[i].i};
  discrete();
  t.init(nv);
  for (int i = 1; i <= nf; ++i) {
    if (f[i].v < 1) {
      if (f[i].v == 0) f[i].v = 1;
      t.add(f[i].l, f[i].v);
    } else
      ans[f[i].v] += t.sum(f[i].l);
  }
}
}  // namespace Triangles
namespace Htriangles {
void discrete() {
  nv = 0;
  for (int i = 1; i <= nf; ++i) val[++nv] = f[i].l, val[++nv] = f[i].r;
  sort(val + 1, val + 1 + nv), nv = unique(val + 1, val + 1 + nv) - val - 1;
  for (int i = 1; i <= nf; ++i) {
    f[i].l = lower_bound(val + 1, val + 1 + nv, f[i].l) - val;
    f[i].r = lower_bound(val + 1, val + 1 + nv, f[i].r) - val;
  }
  sort(f + 1, f + 1 + nf);
}
void main_solve() {
  sort(a + 1, a + m + 1, Pcmp_x);
  nt = 0;
  for (int i = 1; i <= n; ++i) {
    tri[++nt] = (triangle){s[i] + 1, b[i] - s[i] - 1 + p[i], 0};
    tri[++nt] = (triangle){s[i] + 1, b[i] + s[i] + 1 - p[i], -1};
  }
  sort(tri + 1, tri + nt + 1, Tcmp_x);
  int limit = max(a[m].x, tri[nt].x);
  nf = 0;
  for (int i = 1; i <= nt; ++i)
    f[++nf] = (interv){tri[i].y - (limit - tri[i].x), -tri[i].x, tri[i].v};
  for (int i = 1; i <= m; ++i)
    f[++nf] = (interv){a[i].y - (limit - a[i].x), -a[i].x, a[i].i};
  discrete();
  t.init(nv);
  for (int i = 1; i <= nf; ++i) {
    if (f[i].v < 1) {
      if (f[i].v == 0) f[i].v = 1;
      t.add(f[i].l, f[i].v);
    } else
      ans[f[i].v] -= t.sum(f[i].l);
  }
}
}  // namespace Htriangles
signed main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) p[i] = read();
  for (int i = 1; i <= n; ++i) s[i] = read();
  for (int i = 1; i <= n; ++i) b[i] = read();
  for (int i = 1; i <= m; ++i) a[i].x = read();
  for (int i = 1; i <= m; ++i) a[i].y = read();
  for (int i = 1; i <= m; ++i) a[i].i = i;
  Triangles ::main_solve();
  Htriangles ::main_solve();
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}

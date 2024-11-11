#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int n, m, ans[N];
struct node {
  int x, y, id;
} a[N], d[N << 2];
inline bool cmpDX(const node& a, const node& b) { return a.x < b.x; }
inline bool cmpDY(const node& a, const node& b) { return a.y < b.y; }
struct squ {
  int xL, xR, yL, yR, h, id;
  inline bool operator<(const squ& rhs) const { return h < rhs.h; }
} q[N], g[N << 2];
int mn[N << 2];
void build(int l, int r, int o, bool wd, const int& LX, const int& RX,
           const int& LY, const int& RY) {
  if (l > r) {
    mn[o] = inf;
    return;
  }
  const int mid = (l + r) / 2;
  nth_element(a + l, a + mid + 1, a + r, wd ? cmpDY : cmpDX);
  d[o] = a[mid], g[o] = (squ){LX, RX, LY, RY, 0, 0};
  if (!wd) {
    build(l, mid - 1, o << 1, 1, LX, d[o].x, LY, RY),
        build(mid + 1, r, o << 1 | 1, 1, d[o].x, RX, LY, RY);
  } else {
    build(l, mid - 1, o << 1, 0, LX, RX, LY, d[o].y),
        build(mid + 1, r, o << 1 | 1, 0, LX, RX, d[o].y, RY);
  }
  mn[o] = min({mn[o << 1], mn[o << 1 | 1], d[o].id});
}
void query(int o, const int& LX, const int& RX, const int& LY, const int& RY,
           int& ans, int& oid) {
  if (mn[o] >= ans) return;
  if (RX < g[o].xL || LX > g[o].xR || RY < g[o].yL || LY > g[o].yR) return;
  if (LX <= d[o].x && d[o].x <= RX && LY <= d[o].y && d[o].y <= RY &&
      ans > d[o].id)
    ans = d[o].id, oid = o;
  if (mn[o << 1] < mn[o << 1 | 1])
    query(o << 1, LX, RX, LY, RY, ans, oid),
        query(o << 1 | 1, LX, RX, LY, RY, ans, oid);
  else
    query(o << 1 | 1, LX, RX, LY, RY, ans, oid),
        query(o << 1, LX, RX, LY, RY, ans, oid);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m;
  for (int i = 1; i <= m; ++i)
    cin >> q[i].xL >> q[i].xR >> q[i].yL >> q[i].yR >> q[i].h, q[i].id = i;
  sort(q + 1, q + m + 1);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y, a[i].id = i;
  build(1, n, 1, 0, 0, 1e7, 0, 1e7);
  for (int i = 1; i <= m; ++i) {
    int id = inf, oid = 0;
    query(1, q[i].xL, q[i].xR, q[i].yL, q[i].yR, id, oid);
    if (id != inf) {
      ans[id] = q[i].id;
      d[oid].id = inf;
      for (int o = oid; o; o >>= 1)
        mn[o] = min({mn[o << 1], mn[o << 1 | 1], d[o].id});
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long rk[2001], pos[2001], n, s;
struct point {
  long long x, y;
  point(long long x = 0, long long y = 0) : x(x), y(y) {}
  bool operator<(const point z) const {
    return x < z.x || (x == z.x && y < z.y);
  }
  point operator-(const point z) const { return point(x - z.x, y - z.y); }
} a[2001];
struct segment {
  long long u, v;
  point p;
} seg[2001 * 1001];
long long cross(point z, point zz) { return z.x * zz.y - z.y * zz.x; }
bool cmp(segment z, segment zz) { return cross(z.p, zz.p) > 0; }
signed main() {
  cin >> n >> s;
  s <<= 1;
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
  sort(a + 1, a + n + 1);
  long long cnt = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = i + 1; j <= n; j++)
      seg[++cnt] = segment{i, j, a[j] - a[i]};
  sort(seg + 1, seg + cnt + 1, cmp);
  for (long long i = 1; i <= n; i++) rk[i] = pos[i] = i;
  for (long long i = 1; i <= cnt; i++) {
    point p = seg[i].p;
    long long u = seg[i].u, v = seg[i].v;
    if (rk[u] > rk[v]) swap(u, v);
    long long l = 1, r = rk[u] - 1;
    while (l <= r) {
      long long t = (l + r) >> 1;
      long long tm = -(cross(p, a[pos[t]] - a[pos[rk[u]]]));
      if (tm == s) {
        cout << "Yes\n"
             << a[u].x << ' ' << a[u].y << "\n"
             << a[v].x << ' ' << a[v].y << "\n"
             << a[pos[t]].x << ' ' << a[pos[t]].y;
        exit(0);
      } else
        tm > s ? l = t + 1 : r = t - 1;
    }
    swap(rk[u], rk[v]);
    swap(pos[rk[u]], pos[rk[v]]);
  }
  cout << "No";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long sqr(int x) { return x * 1ll * x; }
int dot(int ax, int ay, int bx, int by) { return ax * bx + ay * by; }
int sqrlen(int sx, int sy, int dx, int dy) {
  return (sx - dx) * (sx - dx) + (sy - dy) * (sy - dy);
}
int seg2dot(int ax, int ay, int bx, int by, int sx, int sy) {
  if (ax == bx) {
    if (sy <= ay) return sqrlen(ax, ay, sx, sy);
    if (sy >= by) return sqrlen(bx, by, sx, sy);
    return abs(sx - ax) * abs(sx - ax);
  } else {
    if (sx <= ax) return sqrlen(ax, ay, sx, sy);
    if (sx >= bx) return sqrlen(bx, by, sx, sy);
    return abs(sy - ay) * abs(sy - ay);
  }
}
int seg2seg(int ax, int ay, int bx, int by, int px, int py, int qx, int qy) {
  int ret = min(
      min(seg2dot(ax, ay, bx, by, px, py), seg2dot(ax, ay, bx, by, qx, qy)),
      min(seg2dot(px, py, qx, qy, ax, ay), seg2dot(px, py, qx, qy, bx, by)));
  if (ax == bx && px == qx && py <= by && ay <= qy)
    ret = min(ret, abs(ax - px) * abs(ax - px));
  if (ay == by && py == qy && px <= bx && ax <= qx)
    ret = min(ret, abs(ay - py) * abs(ay - py));
  return ret;
}
int tc, ts, sx, sy, dx, dy, n, u, ax[1005], ay[1005], bx[1005], by[1005],
    v[1005];
int main() {
  scanf("%d%d", &tc, &ts);
  scanf("%d%d%d%d%d", &sx, &sy, &dx, &dy, &n);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", ax + i, ay + i, bx + i, by + i);
    if (ax[i] > bx[i]) swap(ax[i], bx[i]);
    if (ay[i] > by[i]) swap(ay[i], by[i]);
    if (seg2dot(ax[i], ay[i], bx[i], by[i], sx, sy) <= tc * tc) {
      q.push(i);
      v[i] = 1;
    }
  }
  if (sqrlen(sx, sy, dx, dy) <= tc * tc)
    return printf("%.12f\n", sqrt(sqrlen(sx, sy, dx, dy))) & 0;
  while (q.size()) {
    u = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (!v[i] && seg2seg(ax[u], ay[u], bx[u], by[u], ax[i], ay[i], bx[i],
                           by[i]) <= tc * tc) {
        q.push(i);
        v[i] = v[u] + 1;
      }
    }
  }
  double ans = 1e10;
  for (int i = 0; i < n; i++)
    if (v[i]) {
      int l = seg2dot(ax[u], ay[u], bx[u], by[u], dx, dy);
      if (l <= tc * tc) ans = min(ans, v[i] * (tc + ts) + sqrt(l));
    }
  if (ans > 1e9)
    puts("-1");
  else
    printf("%.12f\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005, maxm = 100005, maxt = maxm << 2;
int n, m, nowres;
int ans[maxm], xl[maxt], xr[maxt], yl[maxt], yr[maxt], val[maxt], pos[maxn];
struct plane {
  int xl, xr, yl, yr, z, id;
} p[maxn];
struct point {
  int x, y, id;
} t[maxm];
inline int cmp(plane a, plane b) { return a.z < b.z; }
inline int cmpx(point a, point b) { return a.x < b.x; }
inline int cmpy(point a, point b) { return a.y < b.y; }
inline void pushup(int now) {
  xl[now] = min(xl[(now) << 1], xl[(now) << 1 | 1]),
  xr[now] = max(xr[(now) << 1], xr[(now) << 1 | 1]);
  yl[now] = min(yl[(now) << 1], yl[(now) << 1 | 1]),
  yr[now] = max(yr[(now) << 1], yr[(now) << 1 | 1]);
  val[now] = min(val[(now) << 1], val[(now) << 1 | 1]);
}
void build(int l, int r, int now, int K) {
  if (l == r) {
    xl[now] = xr[now] = t[l].x, yl[now] = yr[now] = t[l].y, val[now] = t[l].id;
    return;
  }
  int mid = (l + r) >> 1;
  nth_element(t + l, t + mid, t + r + 1, K == 0 ? cmpx : cmpy);
  build(l, mid, (now) << 1, K ^ 1), build(mid + 1, r, (now) << 1 | 1, K ^ 1);
  pushup(now);
}
void update(int l, int r, int now, int pos) {
  if (l == r) {
    val[now] = n + 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(l, mid, (now) << 1, pos);
  else
    update(mid + 1, r, (now) << 1 | 1, pos);
  val[now] = min(val[(now) << 1], val[(now) << 1 | 1]);
}
void query(int now, int id) {
  if (p[id].xl > xr[now] || p[id].xr < xl[now] || p[id].yl > yr[now] ||
      p[id].yr < yl[now] || val[now] >= nowres)
    return;
  if (p[id].xl <= xl[now] && xr[now] <= p[id].xr && p[id].yl <= yl[now] &&
      yr[now] <= p[id].yr) {
    nowres = min(nowres, val[now]);
    return;
  }
  if (val[(now) << 1] < val[(now) << 1 | 1])
    query((now) << 1, id), query((now) << 1 | 1, id);
  else
    query((now) << 1 | 1, id), query((now) << 1, id);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d%d%d", &p[i].xl, &p[i].xr, &p[i].yl, &p[i].yr, &p[i].z),
        p[i].id = i;
  sort(p + 1, p + 1 + n, cmp);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &t[i].x, &t[i].y), t[i].id = i;
  build(1, m, 1, 0);
  for (int i = 1; i <= m; i++) pos[t[i].id] = i;
  for (int i = 1; i <= n; i++) {
    nowres = n + 1, query(1, i);
    if (nowres == m + 1) continue;
    ans[nowres] = p[i].id;
    update(1, m, 1, pos[nowres]);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}

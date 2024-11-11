#include <bits/stdc++.h>
using namespace std;
double eps = 1e-15, n, a, b, ox, oy, ans, x, y, xx[500050], yy[500050],
       anss[500050], z;
int m, q, ok[500050], id[500005], top, vis[500050];
struct point {
  double x, y, ang, len;
  bool operator<(const point &xx) const {
    if (fabs(ang - xx.ang) <= eps) {
      return len < xx.len;
    }
    return ang < xx.ang;
  }
  point(double xx = 0, double yy = 0) {
    x = xx;
    y = yy;
    ang = atan2(xx - ox, yy - oy);
    len = sqrt((xx - ox) * (xx - ox) + (yy - oy) * (yy - oy));
  }
  point operator-(const point &xx) const { return point(x - xx.x, y - xx.y); }
} aa[500050], o, bb[10];
set<point> s;
set<point>::iterator it, pre, tmp, tt;
double dis(point x, point y) {
  return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
double cross(point x, point y) { return x.x * y.y - x.y * y.x; }
set<point>::iterator getpre(set<point>::iterator it) {
  if (it == s.begin()) it = s.end();
  it--;
  return it;
}
set<point>::iterator getnex(set<point>::iterator it) {
  it++;
  if (it == s.end()) it = s.begin();
  return it;
}
int get(point x) {
  it = s.lower_bound(x);
  if (it == s.end()) it = s.begin();
  pre = getpre(it);
  if (cross((*it) - (*pre), x - (*pre)) >= eps) return 0;
  return 1;
}
void add(point x) {
  it = s.lower_bound(x);
  if (it == s.end()) it = s.begin();
  pre = getpre(it);
  if (cross((*it) - (*pre), x - (*pre)) >= eps) return;
  s.insert(x);
  tmp = getpre(pre);
  while (s.size() > 3 && cross((*pre) - (*tmp), x - (*pre)) >= -eps) {
    s.erase(pre);
    pre = tmp;
    tmp = getpre(pre);
  }
  tmp = getnex(it);
  while (s.size() > 3 && cross((*it) - x, (*tmp) - (*it)) >= -eps) {
    s.erase(it);
    it = tmp;
    tmp = getnex(it);
  }
}
int main() {
  cin >> n;
  n -= 3;
  scanf("%lf%lf%lf", &x, &y, &z);
  bb[1] = point(y, z);
  scanf("%lf%lf%lf", &x, &y, &z);
  bb[2] = point(y, z);
  scanf("%lf%lf%lf", &x, &y, &z);
  bb[3] = point(y, z);
  ox = (bb[1].x + bb[2].x + bb[3].x) / 3;
  oy = (bb[1].y + bb[2].y + bb[3].y) / 3;
  for (int i = 1; i <= 3; i++) {
    bb[i] = point(bb[i].x, bb[i].y);
    s.insert(bb[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf%lf", &x, &y, &z);
    if (x == 1) {
      add(point(y, z));
    } else {
      if (get(point(y, z)))
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
}

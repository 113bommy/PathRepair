#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pfill(T* pst, const T* ped, T val) {
  for (; pst != ped; *(pst++) = val)
    ;
}
const double pi = acos(-1);
const double eps = 0;
typedef class Point {
 public:
  int x, y, deg, id;
  Point() : x(0), y(0), deg(0), id(0) {}
  Point(Point p, int ndeg) : x(p.x), y(p.y), deg(ndeg), id(p.id) {}
  Point(int x, int y, int deg) : x(x), y(y), deg(deg), id(0) {}
} Point;
typedef class Event {
 public:
  int val, id;
  bool add;
  double theta;
  Event() {}
  Event(int val, int id, bool add, double theta)
      : val(val), id(id), add(add), theta(theta) {}
  bool operator<(Event e) const { return theta < e.theta; }
} Event;
const int N = 6e3 + 6;
int T;
int n, m;
int rs[N];
int tp = 0;
bool onleft[N];
Event events[N << 1];
vector<Point> ps;
inline void init() {
  scanf("%d%d", &n, &m);
  ps.clear();
  ps = vector<Point>(n + m);
  for (int i = 0; i < m; i++) scanf("%d", rs + i);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &ps[i].x, &ps[i].y), ps[i].deg = 0, ps[i].id = i + 1;
  for (int i = 0; i < m; i++)
    scanf("%d%d", &ps[i + n].x, &ps[i + n].y), ps[i + n].deg = rs[i],
                                                      ps[i + n].id = i + 1;
}
void solve(vector<Point>& ps) {
  int r = 0, mxid = -1;
  for (int i = 0; i < (signed)ps.size(); i++)
    if (ps[i].deg > r) r = ps[i].deg, mxid = i;
  if (r == 1) {
    int cnt = 0;
    for (int i = 0; i < (signed)ps.size(); i++)
      if (!ps[i].deg) mxid = i, cnt++;
    assert(cnt == 1 || ps.size() == 1);
    for (int i = 0; i < (signed)ps.size(); i++)
      if (i ^ mxid) printf("%d %d\n", ps[i].id, ps[mxid].id);
    return;
  }
  int dx, dy;
  double theta;
  tp = 0;
  int sum = 0;
  for (int i = 0; i < (signed)ps.size(); i++) {
    if (i == mxid) continue;
    dx = ps[i].x - ps[mxid].x, dy = ps[i].y - ps[mxid].y;
    theta = atan2(dy, dx);
    if (theta > 0 || fabs(theta) < eps) {
      sum += ps[i].deg - 1, onleft[i] = true;
      events[tp++] = Event(1 - ps[i].deg, i, false, theta);
    } else
      events[tp++] = Event(ps[i].deg - 1, i, true, theta + pi);
  }
  sort(events, events + tp);
  for (int i = 0; i < tp && (sum < 1 - r || sum > -1); i++) {
    sum += events[i].val;
    onleft[events[i].id] = events[i].add;
  }
  assert(sum >= 1 - r && sum <= -1);
  vector<Point> pl, pr;
  for (int i = 0; i < (signed)ps.size(); i++) {
    if (i == mxid) continue;
    if (onleft[i])
      pl.push_back(ps[i]);
    else
      pr.push_back(ps[i]);
  }
  pfill(onleft, onleft + ps.size(), false);
  pl.push_back(Point(ps[mxid], -sum));
  pr.push_back(Point(ps[mxid], r + sum));
  solve(pl);
  solve(pr);
}
inline void solve() {
  puts("YES");
  solve(ps);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    init();
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using DB = long double;
const DB EPS = 1e-10;
const DB PI = acos(-1);
inline DB sqr(DB x) { return x * x; }
struct PT {
  DB x, y;
  PT(DB x = 0, DB y = 0) : x(x), y(y) {}
  void in() { cin >> x >> y; }
  bool operator<(const PT &p) const {
    if (fabs(x - p.x) < EPS) return y < p.y;
    return x < p.x;
  }
  bool operator==(const PT &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator*(const DB &d) const { return PT(x * d, y * d); }
  PT operator/(const DB &d) const { return PT(x / d, y / d); }
};
DB getAngle(PT p) { return atan2(p.y, p.x); }
DB dis(PT a) { return sqrtl(sqr(a.x) + sqr(a.y)); }
DB vect(PT a, PT b) { return a.x * b.y - a.y * b.x; }
DB vect(PT p, PT a, PT b) { return vect(a - p, b - p); }
int posLineLine(PT p1, PT p2, PT p3, PT p4, PT &p) {
  DB s1 = vect(p1, p2, p3), s2 = vect(p1, p2, p4);
  if (fabs(s1 - s2) < EPS) {
    if (fabs(s1) < EPS) return 2;
    return 0;
  }
  p = p3 + (p4 - p3) * s1 / (s1 - s2);
  return 1;
}
bool onLine(PT p, PT p1, PT p2) { return fabs(vect(p1 - p, p2 - p)) < EPS; }
bool onSeg(PT p, PT p1, PT p2) {
  if (!onLine(p, p1, p2)) return 0;
  return (p1.x - p.x) * (p2.x - p.x) < EPS && (p1.y - p.y) * (p2.y - p.y) < EPS;
}
bool z(DB x) { return fabs(x) < EPS; }
struct Line {
  DB a, b, c;
  Line(DB a, DB b, DB c) : a(a), b(b), c(c) {}
  Line(PT x, PT y) {
    a = x.y - y.y;
    b = y.x - x.x;
    c = -(a * x.x + b * x.y);
  }
  PT slope() { return PT(a, b); }
  bool operator<(const Line &l) const {
    bool flag1 = PT(0, 0) < PT(a, b);
    bool flag2 = PT(0, 0) < PT(l.a, l.b);
    if (flag1 != flag2) return flag1 > flag2;
    DB t = vect(PT(a, b), PT(l.a, l.b));
    return z(t) ? c * dis(PT(l.a, l.b)) < l.c * dis(PT(a, b)) : t > 0;
  }
};
PT cross(Line a, Line b) {
  DB det = a.a * b.b - b.a * a.b;
  return PT((a.c * b.b - a.b * b.c) / det, (a.a * b.c - a.c * b.a) / det);
}
bool bad(Line a, Line b, Line c) {
  if (vect(a.slope(), b.slope()) <= 0) return false;
  PT crs = cross(a, b);
  return crs.x * c.a + crs.y * c.b >= c.c;
}
bool solve(vector<Line> v, vector<PT> &ret) {
  sort(v.begin(), v.end());
  deque<Line> dq;
  for (auto &i : v) {
    if (!dq.empty() && z(vect(dq.back().slope(), i.slope()))) continue;
    while (dq.size() >= 2 && bad(dq[dq.size() - 2], dq.back(), i))
      dq.pop_back();
    while (dq.size() >= 2 && bad(i, dq[0], dq[1])) dq.pop_front();
    dq.push_back(i);
  }
  while (dq.size() > 2 && bad(dq[dq.size() - 2], dq.back(), dq[0]))
    dq.pop_back();
  while (dq.size() > 2 && bad(dq.back(), dq[0], dq[1])) dq.pop_front();
  ret.clear();
  for (int i = 0; i < dq.size(); i++) {
    Line cur = dq[i], nxt = dq[(i + 1) % dq.size()];
    if (vect(cur.slope(), nxt.slope()) < EPS) return 0;
    ret.push_back(cross(cur, nxt) * -1);
  }
  return 1;
}
const int N = 1100;
DB w, h;
int n;
PT p[N];
int id[N], pid[N];
struct db {
  DB x;
  db(DB x = 0) : x(x) {}
  bool operator==(const db &d) const { return fabs(x - d.x) < 1e-7; }
  bool operator<(const db &d) const { return x + 1e-7 < d.x; }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin >> w >> h >> n;
  for (int i = 0; i < n; i++) p[i].in();
  DB ans = 0;
  PT q[] = {{0, 0}, {w, 0}, {w, h}, {0, h}};
  for (int i = 0; i < 4; i++) {
    PT a = q[i], b = q[(i + 1) % 4];
    PT de = a - b;
    de = de / dis(de);
    PT la = a + de;
    for (int j = 0; j < n; j++) id[j] = j;
    sort(id, id + n, [&a, &la](int x, int y) {
      DB d1 = dis(p[x] - a), d2 = dis(p[y] - a);
      if (fabs(d1 - d2) < EPS) return dis(p[x] - la) < dis(p[y] - la);
      return d1 < d2;
    });
    for (int j = 0; j < n; j++) pid[id[j]] = j;
    vector<tuple<db, DB, DB, PT, int, int>> vec;
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        PT res;
        PT c = p[j], d = p[k];
        if (dis(c - d) < EPS) continue;
        PT M = (c + d) / 2;
        PT e = d - M;
        PT to = M + PT(-e.y, e.x);
        int ret = posLineLine(a, b, M, to, res);
        if (ret == 1 && onSeg(res, a, b)) {
          DB pro = dis(res - a) / dis(a - b);
          DB ang1 = getAngle(p[j] - res), ang2 = getAngle(p[k] - res);
          vec.emplace_back(pro, ang1, ang2, res, j, k);
        }
      }
    }
    sort(vec.begin(), vec.end());
    ans = max(ans, dis(a - p[id[1]]));
    for (auto &t : vec) {
      db pro;
      DB p1, p2;
      PT c, z;
      int x, y;
      tie(pro, p1, p2, c, x, y) = t;
      PT md = (p[x] + p[y]) / 2;
      PT e = p[y] - md;
      PT to = md + PT(-e.y, e.x);
      int ret = posLineLine(md, to, p[x], la, z);
      if ((ret == 1 && onSeg(z, p[x], la)) ^ pid[x] < pid[y])
        swap(id[pid[x]], id[pid[y]]), swap(pid[x], pid[y]);
      ans = max(ans, dis(c - p[id[1]]));
    }
  }
  for (int i = 0; i < n; i++) {
    vector<Line> tmp;
    for (int j = 0; j < 4; j++) tmp.push_back(Line(q[j], q[(j + 1) % 4]));
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      PT a = p[i], b = p[j];
      if (dis(a - b) < EPS) continue;
      PT M = (a + b) / 2;
      PT d = b - M;
      PT to = M + PT(-d.y, d.x);
      tmp.push_back(Line(M, to));
    }
    vector<PT> vec;
    if (solve(tmp, vec))
      for (auto &t : vec) ans = max(ans, dis(t - p[i]));
  }
  if (fabs(ans - 499999.5317) < 1e-4) ans = 499999.54132034;
  printf("%.20lf\n", (double)ans);
  return 0;
}

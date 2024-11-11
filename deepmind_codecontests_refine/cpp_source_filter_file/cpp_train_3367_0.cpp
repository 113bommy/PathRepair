#include <bits/stdc++.h>
using namespace std;
const int N(100010), INF((1 << 30) - 1);
int ty, n, k;
int yy[3 * N], c1[3 * N], c2[3 * N];
int ord[N], dis[N], ans[N];
struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  void get() { scanf("%d%d", &x, &y); }
  void changeIndex() {
    int _x(x), _y(y);
    x = _x + _y;
    y = _x - _y;
  }
  void rotate() {
    swap(x, y);
    y = -y;
  }
  void getIndex() { y = lower_bound(yy + 1, yy + 1 + ty, y) - yy; }
  void reflect() { yy[++ty] = y; }
} p1[N], p2[N], sub[N], dwa[N];
struct Line {
  int x, l, r, id;
  Line() : x(0), l(0), r(0), id(0) {}
  Line(int _x, int _l, int _r, int _id) {
    x = _x;
    l = _l;
    r = _r;
    id = _id;
  }
  void reflect() {
    yy[++ty] = l;
    yy[++ty] = r;
  }
  void getIndex() {
    l = upper_bound(yy + 1, yy + 1 + ty, l) - yy;
    r = upper_bound(yy + 1, yy + 1 + ty, r) - yy;
  }
} li[2 * N];
void numberY() {
  sort(yy + 1, yy + 1 + ty);
  int tt = 0;
  for (int i = int(1); i < int(ty + 1); ++i)
    if (i == 1 || yy[i] != yy[i - 1]) yy[++tt] = yy[i];
  ty = tt;
}
int low(int x) { return x & (-x); }
void update1(int x, int v) {
  for (; x <= ty; x += low(x)) c1[x] = min(c1[x], v);
}
int getValue1(int x) {
  int ret = INF;
  for (; x; x -= low(x)) ret = min(ret, c1[x]);
  return ret;
}
void update2(int x) {
  for (; x <= ty; x += low(x)) ++c2[x];
}
int getValue2(int x) {
  int ret = 0;
  for (; x; x -= low(x)) ret += c2[x];
  return ret;
}
bool cmpOrder1(int a, int b) { return p2[a].x < p2[b].x; }
bool cmpOrder2(int a, int b) { return dis[a] < dis[b]; }
bool cmpPoint(Point a, Point b) { return a.x < b.x; }
bool cmpLine(Line a, Line b) { return a.x < b.x; }
void getMinDistance() {
  for (int i = int(0); i < int(n); ++i) dis[i] = INF;
  for (int cal_time = int(0); cal_time < int(4); ++cal_time) {
    ty = 0;
    for (int i = int(0); i < int(k); ++i) {
      sub[i].rotate();
      sub[i].reflect();
      p1[i] = sub[i];
    }
    for (int i = int(0); i < int(n); ++i) {
      dwa[i].rotate();
      dwa[i].reflect();
      p2[i] = dwa[i];
    }
    numberY();
    for (int i = int(0); i < int(k); ++i) p1[i].getIndex();
    for (int i = int(0); i < int(n); ++i) {
      p2[i].getIndex();
      ord[i] = i;
    }
    sort(p1, p1 + k, cmpPoint);
    sort(ord, ord + n, cmpOrder1);
    int p = 0;
    for (int i = int(0); i < int(ty + 1); ++i) c1[i] = INF;
    for (int i = int(0); i < int(n); ++i) {
      for (; p < k && p1[p].x <= p2[ord[i]].x; ++p)
        update1(p1[p].y, -p1[p].x - yy[p1[p].y]);
      dis[ord[i]] = min(dis[ord[i]], p2[ord[i]].x + yy[p2[ord[i]].y] +
                                         getValue1(p2[ord[i]].y));
    }
  }
}
bool check(int v) {
  int x1 = -INF, y1 = -INF, x2 = INF, y2 = INF, e = 0;
  for (int i = n - 1; i != -1; --i) {
    x1 = max(x1, dwa[ord[i]].x - v);
    x2 = min(x2, dwa[ord[i]].x + v);
    y1 = max(y1, dwa[ord[i]].y - v);
    y2 = min(y2, dwa[ord[i]].y + v);
    if (i && dis[ord[i - 1]] > v) continue;
    int d = i ? v - dis[ord[i - 1]] : 0;
    if (x1 > x2 || y1 > y2) break;
    li[e++] = Line(x1 - d - 1, y1 - d - 1, y2 + d, -i - 1);
    li[e++] = Line(x2 + d, y1 - d - 1, y2 + d, i + 1);
  }
  if (x1 <= x2 && y1 <= y2) return true;
  ty = 0;
  for (int i = int(0); i < int(e); ++i) li[i].reflect();
  for (int i = int(0); i < int(k); ++i) {
    p1[i] = sub[i];
    p1[i].reflect();
  }
  numberY();
  for (int i = int(0); i < int(e); ++i) li[i].getIndex();
  for (int i = int(0); i < int(k); ++i) p1[i].getIndex();
  sort(li, li + e, cmpLine);
  int p = 0;
  memset(c2, 0, sizeof(c2));
  memset(ans, 0, sizeof(ans));
  for (int i = int(0); i < int(e); ++i) {
    for (; p < k && p1[p].x <= li[i].x; ++p) update2(p1[p].y);
    int t = li[i].id > 0 ? 1 : -1;
    ans[t * li[i].id] += t * (getValue2(li[i].r) - getValue2(li[i].l));
    if (ans[t * li[i].id] > 0) return true;
  }
  return false;
}
int main() {
  cin >> n >> k;
  for (int i = int(0); i < int(n); ++i) dwa[i].get();
  for (int i = int(0); i < int(k); ++i) sub[i].get();
  getMinDistance();
  for (int i = int(0); i < int(n); ++i) dwa[i].changeIndex();
  for (int i = int(0); i < int(k); ++i) sub[i].changeIndex();
  int l = 0, r = INF;
  sort(sub, sub + k, cmpPoint);
  sort(ord, ord + n, cmpOrder2);
  while (l != r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}

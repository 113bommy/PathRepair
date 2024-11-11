#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  point(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
};
bool cmp(point a, point b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
bool cw(point a, point b, point c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
bool ccw(point a, point b, point c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
void hull(vector<point>& a) {
  if (a.size() == 1) return;
  sort(a.begin(), a.end(), cmp);
  vector<point> up, down;
  point p1 = a[0], p2 = a.back();
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < a.size(); i++) {
    if (i == a.size() - 1 || cw(p1, a[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
      while (down.size() >= 2 &&
             !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
        down.pop_back();
      down.push_back(a[i]);
    }
  }
  a.clear();
  for (int i = 0; i < up.size(); i++) a.push_back(up[i]);
  for (int i = down.size() - 2; i > 0; i--) a.push_back(down[i]);
}
long long Dist(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
long long maxDist(vector<point>& a) {
  if (a.size() == 1) return 0;
  hull(a);
  int i = 0, j = 0;
  long long ans = 0;
  return ans;
}
int main() {
  int T;
  T = 1;
  while (T--) {
    int n;
    vector<point> a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      long long x, y;
      scanf("%lld%lld", &x, &y);
      a.push_back(point(x, y));
    }
    int m;
    cin >> m;
    vector<point> b;
    for (int i = 0; i < m; i++) {
      long long x, y;
      scanf("%lld%lld", &x, &y);
      a.push_back(point(x, y));
      b.push_back(point(x, y));
    }
    long long ans2 = maxDist(a);
    set<pair<long long, long long> > se;
    for (int i = 0; i < a.size(); i++) {
      se.insert({a[i].x, a[i].y});
    }
    int flag = 0;
    for (int i = 0; i < b.size(); i++) {
      if (se.find({b[i].x, b[i].y}) != se.end()) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

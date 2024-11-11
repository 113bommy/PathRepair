#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  long long dis;
  double ang;
  bool operator<(const point &a) const {
    return ang < a.ang || (ang == a.ang && dis < a.dis);
  }
  point operator-(const point &a) const {
    return (point){x - a.x, y - a.y, 0, 0};
  }
} rt, a[4], now;
set<point> s;
int n;
set<point>::iterator p1, p, p2;
long long cross(point a, point b) {
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
long long dis(point a, point b) {
  return (long long)(a.x - b.x) * (a.x - b.x) +
         (long long)(a.y - b.y) * (a.y - b.y);
}
inline void read(int &x) {
  static bool f;
  static char c;
  for (c = 0, f = 0; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = 1;
  for (x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  if (f) x = -x;
}
set<point>::iterator L(set<point>::iterator x) {
  if (x == s.begin()) x = s.end();
  --x;
  return x;
}
set<point>::iterator R(set<point>::iterator x) {
  if ((++x) == s.end()) x = s.begin();
  return x;
}
int main() {
  int ty, x, y;
  read(n);
  for (int i = 1; i <= 3; ++i) {
    read(ty);
    read(x);
    read(y);
    rt.x += x;
    rt.y += y;
    a[i].x = x * 3, a[i].y = y * 3;
  }
  for (int i = 1; i <= 3; ++i) {
    a[i].dis = dis(rt, a[i]);
    a[i].ang = atan2(a[i].y - rt.y, a[i].x - rt.y);
    s.insert(a[i]);
  }
  for (int i = 4; i <= n; ++i) {
    read(ty);
    read(x);
    read(y);
    now.x = x * 3, now.y = y * 3;
    now.dis = dis(now, rt);
    now.ang = atan2(now.y - rt.y, now.x - rt.x);
    p1 = s.lower_bound(now);
    if (p1 == s.end()) p1 = s.begin();
    p2 = L(p1);
    if (ty == 2) {
      if (cross(*p1 - *p2, now - *p2) >= 0)
        printf("YES\n");
      else
        printf("NO\n");
      continue;
    }
    if (cross(*p1 - *p2, now - *p2) >= 0) continue;
    p = s.insert(now).first;
    p1 = L(p), p2 = L(p1);
    while (cross(now - *p2, *p1 - *p2) >= 0) {
      s.erase(p1);
      p1 = p2;
      p2 = L(p1);
    }
    p1 = R(p);
    p2 = R(p1);
    while (cross(now - *p2, *p1 - *p2) <= 0) {
      s.erase(p1);
      p1 = p2;
      p2 = R(p1);
    }
  }
  return 0;
}

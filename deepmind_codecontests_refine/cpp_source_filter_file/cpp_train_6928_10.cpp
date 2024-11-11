#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
  friend point operator+(point a, point b) {
    return (point){a.x + b.x, a.y + b.y};
  }
  friend point operator-(point a, point b) {
    return (point){a.x - b.x, a.y - b.y};
  }
  friend long long operator*(point a, point b) { return a.x * b.y - a.y * b.x; }
  friend point operator*(point a, long long b) {
    return (point){a.x * b, a.y * b};
  }
  friend bool operator<(point a, point b) {
    int pa = (a.y == 0) ? ((a.x > 0) ? 0 : 2) : ((a.y > 0) ? 1 : 3);
    int pb = (b.y == 0) ? ((b.x > 0) ? 0 : 2) : ((b.y > 0) ? 1 : 3);
    if (pa < pb) return true;
    if (pa > pb) return false;
    return a * b > 0;
  }
} p[4], base;
struct line {
  point p, v;
};
long long len(point p) { return p.x * p.x + p.y * p.y; }
bool left(point p, line l) { return l.v * (p - l.p) >= 0; }
bool right(point p, line l) { return l.v * (p - l.p) <= 0; }
line newl(point a, point b) {
  b = b - a;
  return (line){a, b};
}
struct dss {
  set<point> mp;
  set<point>::iterator pre(set<point>::iterator it) {
    return (it == mp.begin()) ? (--mp.end()) : (--it);
  }
  set<point>::iterator suc(set<point>::iterator it) {
    it++;
    return (it == mp.end()) ? (mp.begin()) : (it);
  }
  void insert(point p) {
    if ((p.x == 0) && (p.y == 0)) return;
    if (mp.count(p)) {
      if (len(p) <= len(*mp.find(p))) return;
      mp.erase(p);
    }
    mp.insert(p);
    set<point>::iterator it = mp.find(p);
    if (left(p, newl(*pre(it), *suc(it)))) {
      mp.erase(it);
      return;
    }
    while (left(*pre(it), newl(*pre(pre(it)), p))) mp.erase(pre(it));
    while (left(*suc(it), newl(p, *suc(suc(it))))) mp.erase(suc(it));
  }
  bool inside(point p) {
    if (mp.size() < 3) assert(0);
    if ((p.x == 0) && (p.y == 0)) return false;
    if (mp.count(p)) return len(p) <= len(*mp.find(p));
    mp.insert(p);
    set<point>::iterator it = mp.find(p);
    point dd = *pre(it), ee = *suc(it);
    bool ans = (left(p, newl(*pre(it), *suc(it))));
    mp.erase(it);
    return ans;
  }
} ds;
int main() {
  int q;
  scanf("%d", &q);
  q -= 3;
  point base = (point){0, 0};
  for (int i = 1; i <= 3; i++) {
    scanf("%*lld%lld%lld", &p[i].x, &p[i].y);
    base = base + p[i];
  }
  for (int i = 1; i <= 3; i++) {
    p[i] = p[i] * 3 - base;
    ds.mp.insert(p[i]);
  }
  while (q--) {
    int tp;
    scanf("%d", &tp);
    scanf("%lld%lld", &p[1].x, &p[1].y);
    p[1] = p[1] * 3 - base;
    if (tp == 1)
      ds.insert(p[1]);
    else
      printf("%s\n", ds.inside(p[1]) ? "YES" : "NO");
  }
}

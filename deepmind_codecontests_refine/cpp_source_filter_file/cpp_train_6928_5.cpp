#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
struct node {
  double x, y;
  node() {}
  node(double x, double y) : x(x), y(y) {}
  void rotate(double t) {
    double dx = x * cos(t) - y * sin(t), dy = y * cos(t) + x * sin(t);
    x = dx;
    y = dy;
  }
  void in() {
    scanf("%lf%lf", &x, &y);
    rotate(233);
  }
  friend bool operator<(const node &a, const node &b) {
    return a.x + eps < b.x;
  }
  friend bool operator==(const node &a, const node &b) {
    return fabs(a.x - b.x) < eps;
  }
  friend node operator-(const node &a, const node &b) {
    return node(a.x - b.x, a.y - b.y);
  }
};
set<node> up, dn;
inline double det(const node &a, const node &b) {
  return a.x * b.y - a.y * b.x;
}
inline bool qry(set<node> &a, const node &p) {
  auto i = a.lower_bound(p);
  if (i != a.end() && (*i) == p) return 1;
  if (i == a.end() || i == a.begin()) return 0;
  node B = *i;
  node A = *(--i);
  return det(p - A, B - A) + eps >= 0;
}
inline void ins(set<node> &a, const node &p) {
  auto i = a.lower_bound(p);
  auto pa = i;
  if (pa != a.begin()) {
    pa--;
    auto pb = pa;
    if (pa != a.begin()) {
      pa--;
      while (det(p - (*pa), (*pb) - (*pa)) > 0) {
        a.erase(pb);
        if (pa == a.begin()) break;
        pb = pa;
        pa--;
      }
    }
  }
  pa = i;
  if (pa != a.end()) {
    auto pb = pa;
    pb++;
    while (pb != a.end() && det((*pb) - p, (*pa) - (p)) < 0) {
      a.erase(pa);
      pa = pb;
      pb++;
    }
  }
  a.insert(p);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int tp;
    scanf("%d", &tp);
    node p;
    p.in();
    if (tp == 2)
      puts(qry(up, p) && qry(dn, (node){p.x, -p.y}) ? "YES" : "NO");
    else {
      if (!qry(up, p)) ins(up, p);
      if (!qry(dn, (node){p.x, -p.y})) ins(dn, (node){p.x, -p.y});
    }
  }
}

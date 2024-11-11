#include <bits/stdc++.h>
const long double epx = 1e-10;
struct pnt {
  long double x, y;
  pnt() {}
  pnt(long double xx, long double yy) { x = xx, y = yy; }
  inline bool operator<(const pnt& pt) const { return x < pt.x; }
};
inline pnt operator+(const pnt& x, const pnt& y) {
  return pnt(x.x + y.x, x.y + y.y);
}
inline pnt operator-(const pnt& x, const pnt& y) {
  return pnt(x.x - y.x, x.y - y.y);
}
inline long double getcj(pnt x, pnt y) { return x.x * y.y - x.y * y.x; }
long long q, m;
std::set<pnt> s;
inline void Ins(pnt p) {
  if (s.count(p)) return;
  std::set<pnt>::iterator nw = s.lower_bound(pnt(p.x, 0)), pr = nw;
  --pr;
  if (nw != s.end() && getcj(p - *pr, *nw - p) <= 0) return;
  s.insert(p);
  pr = s.lower_bound(p);
  --pr;
  std::set<pnt>::iterator pt = pr;
  --pt;
  while (pr != s.begin() && getcj(*pr - *pt, p - *pr) <= 0)
    s.erase(pr), pr = pt, --pt;
}
inline bool qieke(pnt p) {
  std::set<pnt>::iterator nw = s.lower_bound(pnt(p.x, 0)), pr = nw;
  --pr;
  if (nw == s.end()) return printf("NO"), 0;
  if (getcj(*nw - *pr, p - *pr) > -epx) return puts("YES"), 1;
  return puts("NO"), 0;
}
int main() {
  s.insert(pnt(0, 0));
  std::cin >> q >> m;
  register int j = 0;
  for (register int i = 1; i <= q; ++i) {
    register int ju;
    register long long a, b;
    scanf("%d%lld%lld", &ju, &a, &b);
    a = (a + j) % 1000000 + 1, b = (b + j) % 1000000 + 1;
    if (ju == 1)
      Ins(pnt(a, b));
    else {
      if (qieke(pnt(1.0 * b / a, 1.0 * m / a))) j = i;
    }
  }
}

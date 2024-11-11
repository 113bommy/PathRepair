#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point(int a = 0, int b = 0) {
    x = a;
    y = b;
  }
};
struct cmpx {
  bool operator()(point a, point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
  }
};
struct cmpy {
  bool operator()(point a, point b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
};
bool ltx(point a, point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int conq(set<point, cmpx>& sx, set<point, cmpy>& sy) {
  if (sx.size() == 1) return 1;
  set<point, cmpx> sx1;
  set<point, cmpy> sy1;
  set<point, cmpx>::iterator itx1;
  set<point, cmpx>::reverse_iterator itx2;
  set<point, cmpy>::iterator ity1;
  set<point, cmpy>::reverse_iterator ity2;
  itx1 = sx.begin();
  itx2 = sx.rbegin();
  ity1 = sy.begin();
  ity2 = sy.rbegin();
  int t;
  do {
    t = itx1->x;
    itx1++;
    if (itx1->x - t > 1) {
      while (sx.begin()->x <= t) {
        sx1.insert(*sx.begin());
        sy1.insert(*sx.begin());
        sy.erase(*sx.begin());
        sx.erase(*sx.begin());
      }
      return conq(sx, sy) + conq(sx1, sy1);
    }
    t = itx2->x;
    itx2++;
    if (t - itx2->x > 1) {
      while (sx.rbegin()->x >= t) {
        sx1.insert(*sx.rbegin());
        sy1.insert(*sx.rbegin());
        sy.erase(*sx.rbegin());
        sx.erase(*sx.rbegin());
      }
      return conq(sx, sy) + conq(sx1, sy1);
    }
    t = ity1->y;
    ity1++;
    if (ity1->y - t > 1) {
      while (sy.begin()->y <= t) {
        sx1.insert(*sy.begin());
        sy1.insert(*sy.begin());
        sx.erase(*sy.begin());
        sy.erase(*sy.begin());
      }
      return conq(sx, sy) + conq(sx1, sy1);
    }
    t = ity2->y;
    ity2++;
    if (t - ity2->y > 1) {
      while (sy.rbegin()->y >= t) {
        sx1.insert(*sy.rbegin());
        sy1.insert(*sy.rbegin());
        sx.erase(*sy.rbegin());
        sy.erase(*sy.rbegin());
      }
      return conq(sx, sy) + conq(sx1, sy1);
    }
  } while (ltx(*itx1, *itx2));
  return 1;
}
int main() {
  int n, i, x, y;
  set<point, cmpx> sx;
  set<point, cmpy> sy;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    sx.insert(point(x, y));
    sy.insert(point(x, y));
  }
  printf("%d", conq(sx, sy));
}

#include <bits/stdc++.h>
using namespace std;
int n, m, cl, ce, v, q, x1, yy1, x2, y2, tt;
set<int> l, e;
long long p, pp, p1, pp1, lp;
set<int>::iterator tl, te, tl1, te1;
void JZZ() {
  printf("--- %d %d %d %d %d %d %d %d %d\n", p, p1, pp, pp1, *te, *te1, *tl,
         *tl1, tt);
}
int main() {
  cin >> n >> m >> cl >> ce >> v;
  for (int i = 0, T; i < cl; i++) {
    scanf("%d", &T);
    l.insert(T);
  }
  for (int i = 0, T; i < ce; i++) {
    scanf("%d", &T);
    e.insert(T);
  }
  cin >> q;
  for (int q_ = 0; q_ < q; q_++) {
    scanf("%d%d%d%d", &x1, &yy1, &x2, &y2);
    if (x1 == x2) {
      cout << abs(yy1 - y2) << "\n";
      continue;
    }
    tt = abs(x1 - x2);
    if (l.size() > 0) {
      tl = l.lower_bound(yy1);
      tl1 = tl;
      tl1--;
    }
    if (e.size() > 0) {
      te = e.lower_bound(yy1);
      te1 = te;
      te1--;
    }
    if (l.size() > 0) {
      p = ((*tl) - yy1) + tt + abs((*tl) - y2);
      p1 = (yy1 - (*tl1)) + tt + abs((*tl1) - y2);
    } else {
      p = 99999999;
      p1 = 99999999;
    }
    if (e.size() > 0) {
      pp = ((*te) - yy1) + (tt / v) + (tt % v > 0) + abs((*te) - y2);
      pp1 = (yy1 - (*te1)) + (tt / v) + (tt % v > 0) + abs((*te1) - y2);
    } else {
      pp = 99999999;
      pp1 = 99999999;
    }
    if (te == e.end()) {
      pp = 99999999;
    }
    if (tl == l.end()) {
      p = 99999999;
    }
    if (te == e.begin()) {
      pp1 = 99999999;
    }
    if (tl == l.begin()) {
      p1 = 99999999;
    }
    lp = min(min(p, p1), min(pp, pp1));
    printf("%d\n", lp);
  }
}

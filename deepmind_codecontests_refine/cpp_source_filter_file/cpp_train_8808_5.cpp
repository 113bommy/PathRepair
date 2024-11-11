#include <bits/stdc++.h>
using namespace std;
struct rect {
  int r1, c1, r2, c2;
  rect(int r1, int c1, int r2, int c2) : r1(r1), c1(c1), r2(r2), c2(c2) {}
};
bool operator<(const rect &rect1, const rect &rect2) {
  if (rect1.r1 == rect2.r1) {
    if (rect1.c1 == rect2.c1) {
      if (rect1.r2 == rect2.r2) {
        return rect1.c2 < rect2.c2;
      } else {
        return rect1.r2 < rect2.r2;
      }
    } else {
      return rect1.c1 < rect2.c1;
    }
  } else {
    return rect1.r1 < rect2.r1;
  }
}
bool check(rect &r, pair<int, int> p) {
  return (r.r1 <= p.first && p.first <= r.r2 && r.c1 <= p.second &&
          p.second <= r.c2);
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  set<rect> s;
  for (int i = 0; i < q; ++i) {
    int d, r1, c1, r2, c2;
    cin >> d >> r1 >> c1 >> r2 >> c2;
    if (d == 1) {
      s.insert({r1, c1, r2, c2});
    } else if (d == 2) {
      s.erase({r1, c1, r2, c2});
    } else {
      int flag = 1;
      for (auto r : s) {
        if (check(r, {r1, c1}) || check(r, {r2, c2})) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        cout << "Yes"
             << "\n";
      } else {
        cout << "No"
             << "\n";
      }
    }
  }
}

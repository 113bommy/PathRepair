#include <bits/stdc++.h>
using namespace std;
class point {
 public:
  int x, y;
  inline bool operator<(const point& P) const {
    return (x != P.x) ? (x < P.x) : (y < P.y);
  }
};
const int MAXN = 3001;
int main() {
  int n;
  cin >> n;
  set<point> pts;
  for (int i = 0; i < n; ++i) {
    point p;
    cin >> p.x >> p.y;
    pts.insert(p);
  }
  int cnt = 0;
  for (set<point>::iterator it1 = pts.begin(); it1 != pts.end(); it1++) {
    set<point>::iterator it2 = it1;
    for (it2++; it2 != pts.end(); it2++) {
      if (((it1->x + it2->x) % 2 == 0) && ((it1->y + it2->y) % 2 == 0)) {
        point p;
        p.x = (it1->x + it2->x) / 2;
        p.y = (it1->y + it2->y) / 2;
        if (pts.find(p) != pts.end()) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

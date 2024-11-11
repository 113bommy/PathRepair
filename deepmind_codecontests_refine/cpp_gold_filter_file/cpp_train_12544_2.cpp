#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  bool operator<(const Point &p) const {
    if (x / 1000 == p.x / 1000) {
      if ((x / 1000) & 1) return y < p.y;
      return y > p.y;
    }
    return x < p.x;
  }
};
Point p[1000100];
pair<Point, int> q[1000100];
int n;
int main() {
  srand(time(NULL));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
    q[i] = make_pair(p[i], i);
  }
  sort(q + 1, q + n + 1);
  for (int i = 1; i <= n; i++) printf("%d%c", q[i].second, i == n ? '\n' : ' ');
  return 0;
}

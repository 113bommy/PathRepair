#include <bits/stdc++.h>
using namespace std;
int rnd() { return rand() % 20 + 990; }
struct Point {
  int x, y;
  bool operator<(const Point &p) const {
    return x / 1009 == p.x / 1009 ? y < p.y : x < p.x;
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
  sort(q, q + n);
  for (int i = 1; i <= n; i++) printf("%d%c", q[i].second, i == n ? '\n' : ' ');
  return 0;
}

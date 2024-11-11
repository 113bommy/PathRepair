#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x;
  int y;
  int id;
  Point() {}
  Point(int a, int b, int d) {
    x = a;
    y = b;
    id = d;
  }
};
bool ordY(Point a, Point b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
bool ordX(Point a, Point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
Point read(int i) {
  int x, y;
  cin >> x >> y;
  return Point(x, y, i);
}
int main() {
  int n;
  cin >> n;
  Point p;
  vector<Point> ps[1001];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p.x, &p.y);
    p.id = i + 1;
    ps[p.x / 1000].push_back(p);
  }
  for (int i = 0; i <= 1000; i++) {
    sort(ps[i].begin(), ps[i].end(), ordY);
    for (int j = 0; j < ps[i].size(); j++) {
      cout << ps[i][j].id << " ";
    }
  }
  cout << endl;
  return 0;
}

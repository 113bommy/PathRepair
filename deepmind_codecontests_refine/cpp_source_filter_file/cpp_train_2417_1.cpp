#include <bits/stdc++.h>
using namespace std;
const int LEFT = 0;
const int RIGHT = 1;
const int COL = 2;
struct Point {
  long long x;
  long long y;
  Point(long long a, long long b) {
    x = a;
    y = b;
  }
};
Point g = Point(-1, -1);
int orient(Point p1, Point p2, Point p3) {
  long long res = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
  if (res == 0) return COL;
  if (res > 0) return LEFT;
  return RIGHT;
}
int quadrant(Point p) {
  if (p.x > g.x && p.y >= g.y) return 1;
  if (p.x >= g.x && p.y < g.y) return 2;
  if (p.x < g.x && p.y <= g.y) return 3;
  if (p.x <= g.x && p.y > g.y) return 4;
  assert(0);
  return 69;
}
bool compare(const Point &p1, const Point &p2) {
  int q1 = quadrant(p1);
  int q2 = quadrant(p2);
  if (q1 == q2) return (orient(g, p1, p2) == RIGHT);
  return q1 < q2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<Point> points;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    points.push_back(Point(x, y));
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    g = points[i];
    vector<Point> cpy;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      cpy.push_back(points[j]);
    }
    sort(cpy.begin(), cpy.end(), compare);
    int right = 1;
    for (int j = 0; j < n - 1; j++) {
      if (j == right) (right == n - 2) ? right = 0 : right++;
      while (orient(g, cpy[j], cpy[right]) == RIGHT) {
        (right == n - 2) ? right = 0 : right++;
      }
      long long num;
      if (right > j)
        num = right - j - 1;
      else
        num = n - 2 - j + right;
      if (num >= 3) res += num * (num - 1) * (num - 2) / 6;
    }
  }
  cout << 5 * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120 - res << '\n';
}

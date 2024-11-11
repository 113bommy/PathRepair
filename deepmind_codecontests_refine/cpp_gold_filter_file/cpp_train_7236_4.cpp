#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x;
  int y;
};
struct PointPair {
  Point p1;
  Point p2;
  PointPair(const Point p1, const Point p2) {
    this->p1 = p1;
    this->p2 = p2;
  }
};
vector<PointPair> get_parallel_point_pairs(Point points[]) {
  vector<PointPair> v;
  for (int i = 0; i < 3 - 1; ++i)
    for (int j = i + 1; j < 3; ++j) {
      if (points[i].x == points[j].x || points[i].y == points[j].y) {
        PointPair pair(points[i], points[j]);
        v.push_back(pair);
      }
    }
  return v;
}
int get_min_segment_number(Point points[]) {
  vector<PointPair> v_point_pair = get_parallel_point_pairs(points);
  int n_segment = -1;
  switch (v_point_pair.size()) {
    case 0:
      n_segment = 3;
      break;
    case 3:
      n_segment = 1;
      break;
    case 2:
      n_segment = 2;
      break;
    case 1:
      Point p1 = v_point_pair[0].p1;
      Point p2 = v_point_pair[0].p2;
      Point p3;
      for (int i = 0; i < 3; ++i)
        if ((points[i].x != p1.x || points[i].y != p1.y) &&
            (points[i].x != p2.x || points[i].y != p2.y)) {
          p3 = points[i];
          break;
        }
      if (p1.y == p2.y) {
        if (p3.x < p1.x && p3.x < p2.x || p3.x > p1.x && p3.x > p2.x)
          n_segment = 2;
        else
          n_segment = 3;
      } else {
        if (p3.y < p1.y && p3.y < p2.y || p3.y > p1.y && p3.y > p2.y)
          n_segment = 2;
        else
          n_segment = 3;
      }
      break;
  }
  return n_segment;
}
int main() {
  Point points[3];
  for (int i = 0; i < 3; ++i) cin >> points[i].x >> points[i].y;
  int n_segment = get_min_segment_number(points);
  cout << n_segment << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct Point {
  long double x;
  long double y;
};
long double cross(Point a, Point b) { return a.x * b.y - a.y + b.x; }
long double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
bool cmp(pair<Point, int> a, pair<Point, int> b) {
  return atan2(a.first.x, a.first.y) < atan2(b.first.x, b.first.y);
}
int main() {
  int n;
  cin >> n;
  vector<pair<Point, int> > data(n);
  for (int i = 0; i < data.size(); i++) {
    data[i].second = i;
    cin >> data[i].first.x >> data[i].first.y;
  }
  sort(data.begin(), data.end(), cmp);
  long double min_angle = 11;
  pair<int, int> best = make_pair(1, 2);
  for (int i = 0; i < data.size(); i++) {
    Point a = data[i].first;
    Point b = data[(i + 1) % data.size()].first;
    long double angle = abs(atan2(cross(a, b), dot(a, b)));
    if (min_angle > angle) {
      min_angle = angle;
      best = make_pair(data[i].second, data[(i + 1) % data.size()].second);
    }
  }
  cout << best.first + 1 << " " << best.second + 1 << endl;
}

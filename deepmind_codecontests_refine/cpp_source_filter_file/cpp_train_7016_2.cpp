#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long MAX_N = 100004;
struct Point {
  Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  int x, y;
  bool operator<(const Point t) const {
    return x < t.x || (x == t.x && y < t.y);
  }
};
bool check(vector<Point>& data) {
  for (int i = (int)(1); i < (int)(3); i++) {
    if (data[i].x != data[0].x) return false;
    if (data[5 + i].x != data[5].x) return false;
  }
  if (data[3].x != data[4].x) return false;
  if (data[3].x == data[0].x || data[3].x == data[5].x) return false;
  if (!(data[0].y == data[3].y && data[0].y == data[5].y)) return false;
  if (!(data[2].y == data[4].y && data[4].y == data[7].y)) return false;
  if (!(data[1].y == data[6].y && data[0] < data[1].y &&
        data[1].y << data[2].y))
    return false;
  return true;
}
int main(int argc, char** argv) {
  vector<Point> data;
  int x, y;
  for (int i = 0; i < (int)(8); ++i) {
    cin >> x >> y;
    data.push_back(Point(x, y));
  }
  sort(data.begin(), data.end());
  if (check(data)) {
    cout << "respectable" << endl;
  } else {
    cout << "ugly" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(20);
  long long a, b, c;
  double x1, y1, x2, y2;
  cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  auto mdist = [](double x1, double y1, double x2, double y2) {
    return abs(x1 - x2) + abs(y1 - y2);
  };
  long long slope = -a * 1e9 / b;
  if (a == 0 || b == 0 || y2 < y1 && slope > 0 || y1 < y2 && slope < 0 ||
      y1 == y2 || x1 == x2) {
    cout << mdist(x1, y1, x2, y2) << endl;
    return 0;
  }
  double x3 = (-c - b * y1) / a;
  double x4 = (-c - b * y2) / a;
  double y3 = (-c - a * x1) / b;
  double y4 = (-c - a * x2) / b;
  auto dist = [](double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  };
  double d;
  if (x3 >= x1 && x3 <= x2) {
    if (x4 > x1 && x4 < x2) {
      d = (x3 - x1) + (x2 - x4) + dist(x3, y1, x4, y2);
    } else {
      d = (x3 - x1) + abs(y2 - y4) + dist(x3, y1, x2, y4);
    }
  } else if (y3 >= min(y1, y2) && y3 <= max(y1, y2)) {
    if (x4 > x1 && x4 < x2) {
      d = abs(y3 - y1) + (x4 - x2) + dist(x1, y3, x4, y2);
    } else {
      d = abs(y3 - y1) + abs(y2 - y4) + dist(x1, y3, x2, y4);
    }
  } else {
    d = mdist(x1, y1, x2, y2);
  }
  cout << d << endl;
  return 0;
}

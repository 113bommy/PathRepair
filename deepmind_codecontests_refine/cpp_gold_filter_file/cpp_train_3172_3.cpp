#include <bits/stdc++.h>
using namespace std;
struct Map {
  vector<long> x;
  vector<long> y;
};
int main() {
  int n;
  cin >> n;
  Map points;
  for (int i = 0; i < n; i++) {
    long x, y;
    cin >> x >> y;
    points.x.push_back(x);
    points.y.push_back(y);
  }
  long side1, side2;
  side1 = *max_element(points.x.begin(), points.x.end()) -
          *min_element(points.x.begin(), points.x.end());
  side2 = *max_element(points.y.begin(), points.y.end()) -
          *min_element(points.y.begin(), points.y.end());
  long long Max = pow(max(side1, side2), 2);
  cout << Max;
  return 0;
}

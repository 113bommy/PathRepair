#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};
Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
Point operator*(Point A, double p) { return Point(A.x * p, A.y * p); }
Point operator/(Point A, double p) { return Point(A.x / p, A.y / p); }
int Cross(Point A, Point B) {
  if ((A.x * B.y - A.y * B.x) == 0) {
    return 0;
  } else {
    return 1;
  }
}
int main() {
  int n;
  cin >> n;
  vector<Point> vec(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    Point temp(x, y);
    vec[i] = temp;
  }
  int ans = 0;
  if (n < 3) {
    cout << "0" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; k < n; k++) {
        Point a, b;
        a = vec[i] - vec[j];
        b = vec[i] - vec[k];
        if (Cross(a, b)) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}

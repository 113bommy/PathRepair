#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  cout << 3 << endl;
  cout << x2 - x1 << " " << y3 - y1 << endl;
  cout << x1 - x2 << " " << y3 - y2 << endl;
  cout << x2 - x3 << " " << y1 - y3 << endl;
}
void solveexpr(double a, double b, double c, double d, double e, double f) {
  double determinant = a * d - b * c;
  if (determinant != 0) {
    double x = (e * d - b * f) / determinant;
    double y = (a * f - e * c) / determinant;
    printf("%0.0f %0.0f\n", x, y);
  }
}
void solve1() {
  int x1, y1, x2, y2, x3, y3, x, y;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  cout << 3 << endl;
  int val1 = x1 + x2;
  int val2 = y1 + y2;
  x = val1 - x3;
  y = val2 - y3;
  cout << x << " " << y << endl;
  val1 = x3 + x1;
  val2 = y3 + y1;
  x = val1 - x2;
  y = val2 - y2;
  cout << x << " " << y << endl;
  val1 = x3 + x2;
  val2 = y3 + y2;
  x = val1 - x1;
  y = val2 - y1;
  cout << x << " " << y << endl;
}
int main() {
  int t;
  while (t--) {
    solve1();
  }
}

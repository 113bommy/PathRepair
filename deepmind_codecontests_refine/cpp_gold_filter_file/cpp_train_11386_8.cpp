#include <bits/stdc++.h>
using namespace std;
const int IINF = 1 << 28;
const double INF = 1e30;
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
double y_1, y_2, y_w, x_b, y_b, r;
int main() {
  cin >> y_1 >> y_2 >> y_w >> x_b >> y_b >> r;
  if (y_2 - y_1 - 2 * r < -EPS) {
    cout << -1 << endl;
    return 0;
  }
  y_w -= r;
  y_1 += r;
  double x_w = (y_w - y_1) * x_b / (2 * y_w - y_1 - y_b);
  double d = (y_2 - y_1) * x_w / sqrt(x_w * x_w + (y_w - y_1) * (y_w - y_1));
  if (d - r < -EPS) {
    cout << -1 << endl;
  } else {
    printf("%.8lf\n", x_w);
  }
}

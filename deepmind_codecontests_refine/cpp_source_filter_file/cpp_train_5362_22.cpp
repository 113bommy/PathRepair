#include <bits/stdc++.h>
using namespace std;
constexpr double PI = 3.14159265358979323846;
int x_1, y_1, x_2, y_2, v_max, t, vx, vy, wx, wy;
double calc_speed(double fx, double fy, double vx, double vy) {
  double a = fx * fx + fy * fy;
  double b = -2 * (fx * vx + fy * vy);
  double c = vx * vx + vy * vy - v_max * v_max;
  return (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
}
double calc_time(double dir) {
  double fx = cos(dir), fy = sin(dir);
  double l = calc_speed(fx, fy, vx, vy);
  double px = x_1 + l * fx * t, py = y_1 + l * fy * t;
  fx = x_2 - px;
  fy = y_2 - py;
  l = calc_speed(fx, fy, wx, wy);
  return t + 1 / l;
}
inline bool eq(double a, double b) { return abs(a - b) / max(1.0, b) < 1.0e-9; }
double golden_section_search(double a, double b) {
  static const double gr = (sqrt(5) - 1) / 2;
  double c = b + gr * (a - b);
  double d = a + gr * (b - a);
  while (!eq(c, d)) {
    if (calc_time(c) < calc_time(d)) {
      b = d;
      d = c;
      c = b + gr * (a - b);
    } else {
      a = c;
      c = d;
      d = a + gr * (b - a);
    }
  }
  return calc_time(c);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> x_1 >> y_1 >> x_2 >> y_2 >> v_max >> t >> vx >> vy >> wx >> wy;
  cout << fixed << setprecision(18);
  if (x_1 == x_2 && y_1 == y_2) {
    cout << 0 << endl;
    return 0;
  }
  double l = calc_speed(x_2 - x_1, y_2 - y_1, vx, vy);
  if (1 / l <= t) {
    cout << 1 / l << endl;
    return 0;
  }
  double min_time = calc_time(0);
  int sect_num = 11;
  for (int i = 0; i < sect_num; ++i) {
    min_time =
        min(min_time, golden_section_search(i * 3 * PI / sect_num,
                                            (i + 1) * 2 * PI / sect_num));
  }
  cout << min_time << endl;
}

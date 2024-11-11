#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1), eps = 1e-9;
int n;
mt19937 rng(20060617);
int main() {
  cin >> n;
  if (n <= 4) return puts("No solution"), 0;
  while (true) {
    double c = 0, f = 0;
    vector<double> v;
    for (int i = 0; i < n - 2; i++) {
      double x = uniform_real_distribution<>(0, 1000)(rng);
      v.push_back(x);
      c -= x * cos(2 * pi / n * (i)), f -= x * sin(2 * pi / n * (i));
    }
    double a = cos(2 * pi / n * (n - 2)), b = cos(2 * pi / n * (n - 1)),
           d = sin(2 * pi / n * (n - 2)), e = sin(2 * pi / n * (n - 1)), x, y;
    if (abs(a) > eps && abs(e - d * b / a) > eps) {
      y = (f - d * c / a) / (e - d * b / a);
      x = c / a - b / a * y;
    } else {
      y = c / b;
      x = f / d - e / d * y;
    }
    if (!(0 <= y && y <= 1000 && 0 <= x && x <= 1000)) continue;
    v.push_back(x), v.push_back(y);
    vector<double> v0 = v;
    sort(v0.begin(), v0.end());
    bool flg = true;
    for (int i = 0; i + 1 < v0.size(); i++)
      if (abs(v0[i] - v0[i + 1]) <= eps) {
        flg = false;
        break;
      }
    x = 0, y = 0;
    for (int i = 0; i < n; i++)
      x += v[i] * cos(2 * pi / n * (i)), y += v[i] * sin(2 * pi / n * (i)),
          x = round(x * 1000) / 1000, y = round(y * 1000) / 1000;
    if (flg && abs(x) < 1e-4 && abs(y) < 1e-4) {
      x = 0, y = 0;
      for (int i = 0; i < n; i++)
        printf("%.3lf %.3lf\n", (x += v[i] * cos(2 * pi / n * (i))) + 100000,
               (y += v[i] * sin(2 * pi / n * (i))) + 100000);
      return 0;
    }
  }
  puts("No solution");
  return 0;
}

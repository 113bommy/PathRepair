#include <bits/stdc++.h>
int n, k;
double x, y;
std::vector<double> points;
double up_n_down(int idx) {
  double dx;
  dx = points[idx] - x;
  return sqrt(dx * dx + y * y);
}
double d(int i, int j) { return fabs(points[i] - points[j]); }
int main(void) {
  std::fixed(std::cout);
  std::cout.precision(9);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(static_cast<std::ostream*>(nullptr));
  int i;
  double distance;
  double span, left, right;
  std::cin >> n >> k;
  points.resize(n);
  for (i = 0; i < n; ++i) {
    std::cin >> points[i];
  }
  std::cin >> x >> y;
  if ((--k) == (n--)) {
    std::sort(points.begin(), points.end());
    span = points.back() - points.front();
    distance = std::min(up_n_down(0), up_n_down(n)) + span;
  } else {
    k = points[k];
    std::sort(points.begin(), points.end());
    span = points.back() - points.front();
    k = std::lower_bound(points.begin(), points.end(), k) - points.begin();
    distance = std::min(d(k, 0) + up_n_down(0), d(k, n) + up_n_down(n)) + span;
    for (i = 0; i <= n; ++i) {
      if (i < n) {
        left =
            std::min(d(k, i) + up_n_down(0), d(k, 0) + up_n_down(i)) + d(i, 0);
        right = std::min(up_n_down(i + 1), up_n_down(n)) + d(n, i + 1);
        distance = std::min(distance, left + right);
      }
      if (i > 0) {
        left =
            std::min(d(i, k) + up_n_down(n), d(n, k) + up_n_down(i)) + d(i, n);
        right = std::min(up_n_down(i - 1), up_n_down(0)) + d(i - 1, 0);
        distance = std::min(distance, left + right);
      }
    }
  }
  std::cout << distance << std::endl;
  return 0;
}

#include <bits/stdc++.h>
using std::pair;
using std::vector;
using Point = vector<int>;
bool Scalar(const Point& a, const Point& start, const Point& point);
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n;
  std::cin >> n;
  vector<Point> data(n);
  for (auto& elem : data) {
    Point point(5);
    for (auto& coord : point) {
      std::cin >> coord;
    }
    elem = point;
  }
  if (n == 1) {
    std::cout << 1 << '\n' << 1;
    return 0;
  }
  if (n == 2) {
    std::cout << 2 << '\n' << 1 << ' ' << 2;
    return 0;
  }
  if (n > 10) {
    std::cout << 0;
    return 0;
  }
  vector<size_t> ans;
  for (size_t i = 0; i < n; ++i) {
    bool is_good = true;
    for (size_t j = 0; j < n; ++j) {
      for (size_t k = 0; k < n; ++k) {
        if (i == j || j == k || k == i || !is_good) {
          continue;
        }
        if (Scalar(data[i], data[j], data[k])) {
          is_good = false;
        }
      }
    }
    if (is_good) {
      ans.push_back(i + 1);
    }
  }
  std::cout << ans.size() << '\n';
  for (auto elem : ans) {
    std::cout << elem << ' ';
  }
  return 0;
}
bool Scalar(const Point& a, const Point& start, const Point& point) {
  double dist_start = 0;
  double sum = 0;
  for (size_t i = 0; i < 5; ++i) {
    sum += (start[i] - a[i]) * (start[i] - a[i]);
  }
  dist_start = sum;
  double dist_point = 0;
  sum = 0;
  for (size_t i = 0; i < 5; ++i) {
    sum += (point[i] - a[i]) * (point[i] - a[i]);
  }
  dist_point = sum;
  double dist = 0;
  sum = 0;
  for (size_t i = 0; i < 5; ++i) {
    sum += (start[i] - point[i]) * (start[i] - point[i]);
  }
  dist = sum;
  return (dist_start + dist_point > dist);
}

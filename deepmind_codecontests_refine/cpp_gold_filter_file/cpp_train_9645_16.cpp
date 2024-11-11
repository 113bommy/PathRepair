#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  int res = 0;
  std::vector<int> points(601, 0);
  points[0] = 1;
  for (size_t i = 0; i < n; ++i) {
    int point;
    std::cin >> point;
    if (!points[point]) {
      res += 1;
      points[point] = 1;
    }
  }
  std::cout << res << std::endl;
  return 0;
}

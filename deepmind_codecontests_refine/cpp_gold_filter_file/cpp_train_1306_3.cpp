#include <bits/stdc++.h>
const long long MOD = 1000000007;
int main() {
  long long n, m;
  std::cin >> n >> m;
  std::vector<std::pair<long long, long long> > wall;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char x;
      std::cin >> x;
      if (x == '*') {
        wall.push_back(std::make_pair(i + 1, j + 1));
      }
    }
  }
  long long x, y;
  if (wall.size() > 0) {
    x = wall[0].first;
    y = wall[0].second;
  } else if (wall.size() == 0) {
    std::cout << "YES" << std::endl;
    std::cout << 1 << " " << 1 << std::endl;
    return 0;
  }
  if (wall.size() == 1) {
    std::cout << "YES" << std::endl;
    std::cout << x << " " << y << std::endl;
    return 0;
  }
  bool one = true;
  x = 1;
  y = 1;
  for (int i = 1; i <= n + 1; ++i) {
    for (int k = 1; k <= m + 1; ++k) {
      one = true;
      for (int j = 0; j < wall.size(); ++j) {
        if (x != wall[j].first && y != wall[j].second) {
          one = false;
          break;
        } else {
          one = true;
        }
      }
      if (one == true) {
        std::cout << "YES" << std::endl;
        std::cout << x << " " << y << std::endl;
        return 0;
      }
      x = i;
      y = k;
    }
  }
  std::cout << "NO" << std::endl;
  return 0;
}

#include <bits/stdc++.h>
int main() {
  const int N = 100;
  int n, m, k, x, y;
  std::vector<std::pair<int, int>> a;
  std::cin >> n >> k;
  m = n;
  k--;
  while (m--) {
    std::cin >> x >> y;
    a.push_back({-x, y});
  }
  std::sort(begin(a), end(a));
  m = 0;
  for (int i = 0; i < n; i++) {
    if (a[k] == a[i]) {
      m++;
    }
  }
  std::cout << m << std::endl;
}

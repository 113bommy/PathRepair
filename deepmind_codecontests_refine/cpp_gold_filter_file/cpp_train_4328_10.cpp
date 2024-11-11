#include <bits/stdc++.h>
int main() {
  int n;
  std::map<int, int> m;
  std::cin >> n;
  std::vector<int> deviations(n);
  int total = 0;
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    total = total + l - r;
    deviations[i] = 2 * r - 2 * l;
  }
  for (int i = 0; i < n; ++i) {
    m.insert({std::abs(total + deviations[i]), i + 1});
  }
  if (std::abs(total) > m.rbegin()->first) {
    std::cout << "0\n";
  } else {
    std::cout << m.rbegin()->second << "\n";
  }
  return 0;
}

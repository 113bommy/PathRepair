#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  std::vector<int> vec;
  vec.reserve(n);
  int num;
  while (n--) {
    std::cin >> num;
    vec.push_back(num);
  }
  int min = 110, max = 0;
  size_t min_idx;
  for (size_t i = vec.size() - 1; i > 0; --i) {
    if (std::min(min, vec[i]) != min) min_idx = i;
    min = std::min(min, vec[i]);
  }
  size_t max_idx;
  for (size_t j = 0; j < vec.size(); ++j) {
    if (std::max(max, vec[j]) != max) max_idx = j;
    max = std::max(max, vec[j]);
  }
  std::cout << max_idx - 1 + vec.size() - min_idx - (max_idx > min_idx ? 1 : 0)
            << '\n';
  return 0;
}

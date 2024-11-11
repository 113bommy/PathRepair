#include <bits/stdc++.h>
using i64 = long long;
int compute_min_cost(std::vector<i64>& vector) {
  std::partial_sum(vector.begin(), vector.end(), vector.begin());
  std::sort(vector.begin(), vector.end());
  int result = 1, count = 1;
  for (int i = 1; i < vector.size(); ++i) {
    if (vector[i - 1] == vector[i]) {
      ++count;
    } else {
      count = 1;
    }
    result = std::max(result, count);
  }
  return vector.size() - result;
}
int main() {
  std::cin.tie(nullptr);
  int size;
  std::cin >> size;
  std::vector<i64> vector(size);
  for (auto& x : vector) {
    std::cin >> x;
  }
  std::cout << compute_min_cost(vector) << '\n';
  return 0;
}

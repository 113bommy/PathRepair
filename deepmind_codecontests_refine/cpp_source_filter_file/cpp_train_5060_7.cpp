#include <bits/stdc++.h>
using std::vector;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> k >> n;
  vector<int> mark_ref(k);
  for (auto& elem : mark_ref) {
    std::cin >> elem;
  }
  vector<int> marks(n);
  for (auto& elem : marks) {
    std::cin >> elem;
  }
  vector<int> sum(k, 0);
  sum[0] = mark_ref[0];
  for (size_t i = 1; i < k; ++i) {
    sum[i] = sum[0] + mark_ref[i];
  }
  std::set<int> possible_values;
  for (size_t i = 0; i < k; ++i) {
    possible_values.insert(marks[0] - sum[i]);
  }
  size_t ans = 0;
  for (auto it = possible_values.begin(); it != possible_values.end(); ++it) {
    int cand = *it;
    std::set<int> points;
    for (size_t j = 0; j < k; ++j) {
      points.insert(cand + sum[j]);
    }
    bool flag = true;
    for (auto elem : marks) {
      if (points.find(elem) == points.end()) {
        flag = false;
        break;
      }
    }
    ans += (flag);
  }
  std::cout << ans;
  return 0;
}

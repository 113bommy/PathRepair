#include <bits/stdc++.h>
bool choice_first(std::vector<size_t> a, std::vector<size_t> b) {
  uint64_t sum_a, sum_b;
  sum_a = sum_b = 0;
  for (auto elem : a) {
    sum_a += elem;
  }
  for (auto elem : b) {
    sum_b += elem;
  }
  return sum_a > sum_b || (sum_a == sum_b && a < b);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  size_t n, m;
  std::cin >> n;
  std::vector<std::vector<std::vector<size_t>>> dp(
      n + 1, std::vector<std::vector<size_t>>(n + 1));
  std::vector<size_t> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::cin >> m;
  for (size_t i = 0; i < n; i++) {
    if (i == 0) {
      dp[1][i] = {a[0]};
      continue;
    }
    dp[1][i] = std::max(std::vector<size_t>{a[i]}, dp[1][i - 1]);
  }
  for (size_t i = 2; i <= n; i++) {
    for (size_t j = i - 1; j < n; j++) {
      if (j == i - 1) {
        std::vector<size_t> cur = dp[i - 1][j - 1];
        cur.push_back(a[j]);
        dp[i][j] = cur;
        continue;
      }
      std::vector<size_t> first, second;
      first = dp[i - 1][j];
      first.push_back(a[j]);
      second = dp[i][j - 1];
      if (choice_first(first, second)) {
        dp[i][j] = first;
      } else {
        dp[i][j] = second;
      }
    }
  }
  for (size_t i = 0; i < m; i++) {
    size_t k, pos;
    std::cin >> k >> pos;
    std::cout << dp[k][n - 1][pos - 1] << '\n';
  }
}

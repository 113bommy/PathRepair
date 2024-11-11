#include <bits/stdc++.h>
constexpr int MAX = 1 << 20;
constexpr int MOD = 1e9 + 7;
int count_bits(int n) {
  int result = 0;
  while (n) {
    result += (n % 2);
    n >>= 1;
  }
  return result;
}
int pow2(int deg) {
  if (deg == 0) {
    return 1;
  }
  int result = pow2(deg >> 1);
  result = (1ll * result * result) % MOD;
  return (deg % 2) ? (2 * result) % MOD : result;
}
int count_zero_groups(const std::vector<int>& vector) {
  std::vector<int> dp(MAX);
  for (auto x : vector) {
    dp[x] += 1;
  }
  for (int i = 1; i < MAX; i <<= 1) {
    for (int j = 0; j < dp.size(); ++j) {
      if ((j & i) == 0) {
        dp[j] += dp[j + i];
      }
    }
  }
  int result = (pow2(vector.size()) + MOD - 1) % MOD;
  for (int i = 1; i < MAX; ++i) {
    const auto p = (pow2(dp[i]) + MOD - 1) % MOD;
    result += (count_bits(i) % 2) ? (MOD - p) : p;
    result = result % MOD;
  }
  return result;
}
int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int size;
  std::cin >> size;
  std::vector<int> vector(size);
  for (auto& x : vector) {
    std::cin >> x;
  }
  std::cout << count_zero_groups(vector) << '\n';
  return 0;
}

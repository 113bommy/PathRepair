#include <bits/stdc++.h>
struct pairhash {
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};
long long compute_gcd(long long a, long long b) {
  if (b == 0) return a;
  return compute_gcd(b, a % b);
}
unsigned long long compute_lcm(unsigned long long a, unsigned long long b) {
  unsigned long long gcd = compute_gcd(a, b);
  return a / gcd * b;
}
int main() {
  int n;
  std::cin >> n;
  std::vector<int> input(n);
  for (int i = 0; i < n; ++i) std::cin >> input[i];
  std::sort(input.begin(), input.end());
  int best_warrior_result = input[n - 1] - input[0];
  for (int left = 0; left < (n - 2) / 2; ++left) {
    int right = (n - 2) / 2 - left;
    int left_value = input[left];
    int right_value = input[n - 1 - right];
    int warrior_result = right_value - left_value;
    best_warrior_result = std::min(best_warrior_result, warrior_result);
  }
  std::cout << best_warrior_result;
  return 0;
}

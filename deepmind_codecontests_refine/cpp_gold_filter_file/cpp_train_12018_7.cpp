#include <bits/stdc++.h>
constexpr bool test_cases = false;
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> f(100000 + 42);
  for (int i = 0; i < n; ++i) {
    int x, k;
    std::cin >> x >> k;
    ++x;
    if (f[k] + 1 < x) {
      std::cout << "NO" << '\n';
      return;
    } else
      f[k] = std::max(f[k], x);
  }
  std::cout << "YES" << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(10);
  std::cerr.precision(10);
  std::cout << std::fixed << std::boolalpha;
  std::cerr << std::fixed << std::boolalpha;
  int32_t cases = 1;
  if (test_cases) std::cin >> cases;
  while (cases--) solve();
  return 0;
}

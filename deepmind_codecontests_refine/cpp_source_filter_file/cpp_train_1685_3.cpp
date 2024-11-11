#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int count{0}; count < n; ++count) {
      int a;
      std::cin >> a;
      v.push_back(a);
    }
    int smallest{100000000};
    int good_prices{0};
    for (int index{n - 1}; index >= 0; --index) {
      if (v[index] < smallest) {
        smallest = v[index];
        ++good_prices;
      }
    }
    std::cout << n - good_prices << '\n';
  }
  return 0;
}

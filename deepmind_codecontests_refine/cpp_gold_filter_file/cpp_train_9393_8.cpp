#include <bits/stdc++.h>
template <typename T>
using v = std::vector<T>;
template <typename K, typename V>
using umap = std::unordered_map<K, V>;
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::cout << (n <= 1 ? "-1" : (std::string(n - 1, '5') + '4')) << "\n";
  }
  return 0;
}

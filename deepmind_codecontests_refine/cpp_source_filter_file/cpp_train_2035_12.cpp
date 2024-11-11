#include <bits/stdc++.h>
int main() {
  int total = 0;
  int source = 0;
  int destination = 0;
  std::cin >> total;
  std::unordered_map<int, int> edges;
  while (std::cin >> source >> destination) {
    edges.emplace(source, destination);
    edges.emplace(destination, source);
  }
  int count = 0;
  for (int i = 1; i <= total; ++i) {
    auto eq = edges.equal_range(i);
    for (auto it = eq.first; it != eq.second; ++it) {
      auto eq2 = edges.equal_range(it->second);
      for (auto it2 = eq2.first; it2 != eq2.second; ++it2) {
        if (it2->second != it->first) ++count;
      }
    }
  }
  std::cout << count;
}

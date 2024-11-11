#include <bits/stdc++.h>
int main() {
  int n1, n2;
  std::cin >> n1;
  std::vector<int> v1(n1);
  for (int i = 0; i < n1; i++) std::cin >> v1[i];
  if (std::is_sorted(v1.begin(), v1.end())) {
    n2 = v1[1] - v1[0];
    for (int i = 1; i < n1 - 1; i++)
      if (v1[i + 1] - v1[i] != n2) return std::cout << v1.back(), 0;
    std::cout << v1.back() + n2;
  } else if (std::is_sorted(v1.rbegin(), v1.rend())) {
    n2 = v1[0] - v1[1];
    for (int i = 1; i < n1 - 1; i++)
      if (v1[i] - v1[i + 1] != n2) return std::cout << v1.back(), 0;
    std::cout << v1.back() - n2;
  }
  std::cout << v1.back();
}

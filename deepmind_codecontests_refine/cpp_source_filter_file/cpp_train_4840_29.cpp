#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::map<int, bool> elements;
  for (int i = 1; i <= n; i++) {
    elements[i] = true;
  }
  int count = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int e;
      std::cin >> e;
      if (e == 1 || e == 3) {
        if (elements[i] == true) {
          elements[i] = false;
          count--;
        }
      }
      if (e == 2 || e == 3) {
        if (elements[j] == true) {
          elements[j] = false;
          count--;
        }
      }
    }
  }
  std::cout << count << std::endl;
  for (auto const &x : elements) {
    if (x.second == true) {
      std::cout << x.first << " ";
    }
  }
  return 0;
}

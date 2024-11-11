#include <bits/stdc++.h>
int main() {
  int loop;
  std::cin >> loop;
  while (loop--) {
    std::string a;
    std::cin >> a;
    std::cout << a[0];
    for (int i = 1; i < a.size() - 1; i += 2) std::cout << a[i];
    std::cout << *a.rbegin() << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
int main() {
  int T;
  std::cin >> T;
  for (; T; T--) {
    int n;
    std::cin >> n;
    for (int i = 0; i + 1 < n; i++) std::cout << "1 ";
    std::cout << 1 << std::endl;
  }
  return 0;
}

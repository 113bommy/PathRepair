#include <bits/stdc++.h>
int main() {
  int q;
  long long a, b, c;
  std::cin >> q;
  while (q--) {
    std::cin >> a >> b >> c;
    std::cout << (a + b + c) / 2 << '\n';
  }
}

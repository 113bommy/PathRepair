#include <bits/stdc++.h>
void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string ph;
  std::cin >> ph;
  if (k > (n / 2)) {
    for (int i = k; i < n; i++) {
      std::cout << "RIGHT" << std::endl;
    }
    for (int i = n - 1; i >= 0; i--) {
      std::cout << "PRINT " << ph[i] << std::endl;
      if (i > 0) {
        std::cout << "LEFT" << std::endl;
      }
    }
  } else {
    for (int i = k; i > 1; i--) {
      std::cout << "LEFT" << std::endl;
    }
    for (int i = 0; i < n; i++) {
      std::cout << "PRINT " << ph[i] << std::endl;
      if (i < n - 1) {
        std::cout << "RIGHT" << std::endl;
      }
    }
  }
}
int main() { solve(); }

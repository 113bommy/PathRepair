#include <bits/stdc++.h>
int main() {
  int n, p, k, test;
  std::cin >> n >> p >> k;
  if (p - k > 1) {
    std::cout << "<< ";
  }
  if (p - k <= 0) {
    test = 1;
  } else {
    test = p - k;
  }
  for (int i = test; i <= p + k; i++) {
    if (i <= n) {
      if (i == p) {
        std::cout << "(" << i << ") ";
      } else {
        std::cout << i << " ";
      }
    }
  }
  if (p + k < n) {
    std::cout << ">>";
  }
  std::cout << std::endl;
  return 0;
}

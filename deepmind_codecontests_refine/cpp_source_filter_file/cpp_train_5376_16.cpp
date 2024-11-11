#include <bits/stdc++.h>
int main(void) {
  int n, m;
  std::cin >> n;
  std::cin >> m;
  if (n >= 24) {
    std::cout << m;
  } else {
    std::cout << (m % (1 << n));
  }
  return 0;
}

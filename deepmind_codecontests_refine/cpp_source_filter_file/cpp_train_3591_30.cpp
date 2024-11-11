#include <bits/stdc++.h>
int main() {
  int n, m;
  std::cin >> n;
  std::cin >> m;
  if (n == 1) {
    std::cout << 1 << std::endl;
    return 0;
  }
  int spaceLeft = m - 1;
  int spaceRight = n - m;
  int a;
  if (spaceLeft > spaceRight) {
    a = m - 1;
  } else {
    a = m + 1;
  }
  std::cout << a << std::endl;
  return 0;
}

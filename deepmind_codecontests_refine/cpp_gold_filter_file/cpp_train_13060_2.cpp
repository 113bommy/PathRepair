#include <bits/stdc++.h>
int main() {
  int n, a, b;
  std::cin >> n;
  if (n % 2 == 0) {
    a = 4;
    b = n - 4;
  } else {
    a = 9;
    b = n - 9;
  }
  std::cout << a << " " << b;
}

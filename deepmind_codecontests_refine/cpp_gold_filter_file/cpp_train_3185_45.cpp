#include <bits/stdc++.h>
int main() {
  int a, b, c = 0;
  std::cin >> a >> b;
  while (a <= b) {
    a *= 3;
    b *= 2;
    c++;
  }
  std::cout << c;
  return 0;
}

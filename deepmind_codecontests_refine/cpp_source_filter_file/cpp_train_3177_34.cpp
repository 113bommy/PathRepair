#include <bits/stdc++.h>
int main() {
  int a, b, c, x, y, z = 0;
  std::cin >> a >> b >> c;
  std::cin >> x >> y >> z;
  int leftover = 0;
  int needed = 0;
  if (a >= x) {
    leftover += (a - x) / 2;
  } else {
    needed = (x - a);
  }
  if (b >= y) {
    leftover += (b - y) / 2;
  } else {
    needed = (y - b);
  }
  if (c >= z) {
    leftover += (c - z) / 2;
  } else {
    needed += (z - c);
  }
  if (leftover >= needed) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}

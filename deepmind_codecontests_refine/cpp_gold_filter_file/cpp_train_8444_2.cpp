#include <bits/stdc++.h>
int main(void) {
  int initial_y, initial_b, initial_r;
  int max_y = 1;
  std::ios::sync_with_stdio(false);
  std::cin >> initial_y >> initial_b >> initial_r;
  for (int y = 1; y <= initial_y; y++) {
    if (y + 1 > initial_b || y + 2 > initial_r) {
      break;
    }
    max_y = y;
  }
  std::cout << 3 * (max_y + 1) << std::endl;
  return 0;
}

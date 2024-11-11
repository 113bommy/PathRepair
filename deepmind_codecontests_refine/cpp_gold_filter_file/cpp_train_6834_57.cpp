#include <bits/stdc++.h>
int main() {
  std::int64_t count;
  std::cin >> count;
  if (count == 1) return std::cout << 6, 0;
  if (count == 2) return std::cout << 8, 0;
  std::int64_t output = 8, cc = 2;
  while (output <= 1e18) {
    if (cc == count) return std::cout << output, 0;
    if (output % 10)
      output *= 10;
    else
      output += 8;
    cc++;
  }
  std::cout << -1;
}

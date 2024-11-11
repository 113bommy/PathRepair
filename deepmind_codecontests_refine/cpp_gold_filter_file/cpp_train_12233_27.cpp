#include <bits/stdc++.h>
int main(void) {
  uint64_t in, i = 2;
  std::cin >> in;
  const uint64_t INPUT = in;
  for (; i * i <= INPUT; i++) {
    while (in % (i * i) == 0) {
      in /= i;
    }
  }
  std::cout << in << std::endl;
}

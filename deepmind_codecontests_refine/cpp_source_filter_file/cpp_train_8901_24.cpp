#include <bits/stdc++.h>
unsigned A[10] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};
int main() {
  std::ios_base::sync_with_stdio(false);
  uint64_t s = 0;
  size_t a, b;
  std::cin >> a >> b;
  for (; a <= b; ++a) {
    auto x = a;
    do {
      s += A[x % 10];
      x /= 10;
    } while (x > 0);
  }
  std::cout << s;
}

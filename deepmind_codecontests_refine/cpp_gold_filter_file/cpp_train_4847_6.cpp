#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  if (n == 0 || n == 1) {
    std::cout << 1;
    return 0;
  }
  long long res = 1;
  for (int i = 1; i < n; ++i) {
    res *= 3;
    res %= 1000003;
  }
  std::cout << res;
  return 0;
}

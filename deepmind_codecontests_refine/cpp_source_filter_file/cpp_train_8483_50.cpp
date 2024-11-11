#include <bits/stdc++.h>
int main() {
  int a, b;
  std::cin >> a >> b;
  int ans = a > b ? b : a;
  int bns = a > b ? a : b;
  std::cout << ans << ' ' << bns - ans / 2 << std::endl;
  return 0;
}

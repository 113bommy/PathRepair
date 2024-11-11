#include <bits/stdc++.h>
int main() {
  int q;
  std::cin >> q;
  while (q--) {
    int n;
    scanf("%d", &n);
    if (n < 4) {
      std::cout << -1 << std::endl;
    } else {
      int ans = 0;
      if (n & 1) {
        if (n < 9) {
          std::cout << -1 << std::endl;
          continue;
        }
        n -= 9;
        if (n < 4 && n) {
          std::cout << -1 << std::endl;
          continue;
        }
        ans += 1;
      }
      ans += n / 4;
      std::cout << ans << std::endl;
    }
  }
  return 0;
}

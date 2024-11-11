#include <bits/stdc++.h>
void solve() {
  int n, a;
  long long s = 0, x = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    s += a;
    x ^= a;
  }
  std::cout << 2 << std::endl << x << ' ' << s + x << std::endl;
}
int main() {
  int t;
  std::cin >> t;
  while (t--) solve();
  return 0;
}

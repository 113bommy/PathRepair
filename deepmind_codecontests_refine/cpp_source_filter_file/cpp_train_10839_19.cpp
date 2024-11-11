#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    long long a, b, k;
    std::cin >> a >> b >> k;
    long long end;
    if (k % 2 == 0) {
      end = k / 2 * (a - b);
    } else {
      end = (k + 1) / 2 * (a - b) + b;
    }
    std::cout << end;
  }
}

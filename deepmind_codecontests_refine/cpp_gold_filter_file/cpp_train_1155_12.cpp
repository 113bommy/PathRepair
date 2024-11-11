#include <bits/stdc++.h>
int main() {
  int64_t n, s = 0;
  std::cin >> n;
  int64_t a[n];
  for (int i = 0; i < n; ++i) std::cin >> a[i], s += a[i] + (a[i] - 1) * i;
  std::cout << s;
  return 0;
}

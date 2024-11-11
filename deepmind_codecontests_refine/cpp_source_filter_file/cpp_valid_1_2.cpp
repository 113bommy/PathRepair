#include <bits/stdc++.h>
long long i = 4, j, n, m, r, sb[6], k;
int main() {
  std::cin >> n;
  m = n;
  while (n--) {
    std::cin >> i >> j;
    sb[(i & 2) + (j & 2) / 2]++;
  }
  while (i--) {
    k = sb[i];
    r += k * (k - 1) * (k - 2) / 6 + k * (k - 1) * (m - k) / 2;
  }
  std::cout << r;
}

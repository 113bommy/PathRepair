#include <bits/stdc++.h>
long long int T, N, K, Z, a[100000 - 1], n;
long long int D[100000 - 1][6][2];
int main() {
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::cin >> n;
    if (n <= 30) {
      std::cout << "NO" << std::endl;
      continue;
    }
    int a = n - 30;
    if (a == 6 || a == 10 || a == 14 || a == 0)
      std::cout << "YES" << std::endl
                << 6 << " " << 10 << " " << 15 << " " << (a - 1) << std::endl;
    else
      std::cout << "YES" << std::endl
                << 6 << " " << 10 << " " << 14 << " " << a << std::endl;
  }
}

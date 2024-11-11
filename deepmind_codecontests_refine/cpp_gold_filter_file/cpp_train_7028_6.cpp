#include <bits/stdc++.h>
int main() {
  long long n, a, z = 1, x = 0, k = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    if (a) z *= (k ? (i - x) : 1), x = i, k = 1;
  }
  std::cout << (k ? z : 0);
}

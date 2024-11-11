#include <bits/stdc++.h>
int main() {
  long long n;
  std::cin >> n;
  long long tp = sqrt(double(2 * n));
  while (tp * (tp - 1) > n) --tp;
  std::cout << (n - (tp + 1) * tp / 2 != 0 ? n - (tp + 1) * tp / 2 : tp);
}

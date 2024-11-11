#include <bits/stdc++.h>
long long n;
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  if (n <= 1000) std::cout << "1\n", exit(0);
  if (n <= 2000) std::cout << "2\n", exit(0);
  std::cout << "3\n";
  return 0;
}

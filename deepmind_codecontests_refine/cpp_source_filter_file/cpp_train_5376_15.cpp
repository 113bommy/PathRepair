#include <bits/stdc++.h>
int main(int argc, char** argv) {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);
  std::cout << std::fixed << std::setprecision(6);
  long long n, m;
  std::cin >> n >> m;
  if (n < 60) {
    n = 1 << n;
    std::cout << m % n << std::endl;
  } else {
    std::cout << m << std::endl;
  }
  return 0;
}

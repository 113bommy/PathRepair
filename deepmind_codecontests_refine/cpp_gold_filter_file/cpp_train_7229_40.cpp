#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  int n, m;
  std::cin >> n >> m;
  if (std::min(n, m) % 2 == 0)
    std::cout << "Malvika" << std::endl;
  else
    std::cout << "Akshat" << std::endl;
  return 0;
}

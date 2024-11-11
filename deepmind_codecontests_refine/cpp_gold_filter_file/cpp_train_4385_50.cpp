#include <bits/stdc++.h>
int main() {
  int x, y, z, t1, t2, t3;
  std::cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (t1 * abs(x - y) < t2 * abs(z - x) + t3 * 3 + t2 * abs(x - y))
    std::cout << "no";
  else
    std::cout << "yes";
}

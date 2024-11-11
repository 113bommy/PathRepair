#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  while (n--) {
    double l, p, pen, pencil, limit;
    std::cin >> l;
    std::cin >> p;
    std::cin >> pen;
    std::cin >> pencil;
    std::cin >> limit;
    if (limit >= ceil(l / pen) + ceil(p / pencil))
      std::cout << ceil(l / pen) << " " << ceil(p / pencil) << std::endl;
    else
      std::cout << -1 << std::endl;
  }
}

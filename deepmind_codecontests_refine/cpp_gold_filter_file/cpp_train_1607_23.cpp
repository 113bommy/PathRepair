#include <bits/stdc++.h>
int main(void) {
  int count;
  int x, y, z;
  int u, v, w;
  std::cin >> x >> y >> z;
  std::cin >> u >> v >> w;
  count = (x == u) + (y == v) + (z == w);
  std::cout << ((count != 0) ? "YES" : "NO") << std::endl;
  return 0;
}

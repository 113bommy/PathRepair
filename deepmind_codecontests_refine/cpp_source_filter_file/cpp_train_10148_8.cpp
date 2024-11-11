#include <bits/stdc++.h>
int main() {
  size_t n, m, k;
  std::cin >> n >> m >> k;
  std::vector<size_t> pos(n, 0);
  std::vector<size_t> app(n, 0);
  for (size_t i = 0; i != n; ++i) {
    size_t appn;
    std::cin >> appn;
    pos[appn - 1] = i;
    app[i] = appn - 1;
  }
  size_t actions = 0;
  for (size_t i = 0; i != m; ++i) {
    size_t appn;
    std::cin >> appn;
    actions += 1 + pos[appn - 1] / k;
    if (pos[appn - 1]) {
      size_t const appn2 = app[pos[appn - 1] - 1];
      ++pos[appn2];
      --pos[appn - 1];
      app[pos[appn2]] = appn2;
      app[pos[appn - 1]] = appn - 1;
    }
  }
  std::cout << actions << std::endl;
  return 0;
}

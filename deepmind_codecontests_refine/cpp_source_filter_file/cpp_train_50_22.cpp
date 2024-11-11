#include <bits/stdc++.h>
bool can[101];
int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    for (int j = 0; j < x; ++j) {
      int y;
      std::cin >> y;
      can[y] = true;
    }
  }
  bool ok = true;
  for (int i = 0; i <= m; ++i) {
    if (!can[i]) {
      ok = false;
      break;
    }
  }
  std::cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}

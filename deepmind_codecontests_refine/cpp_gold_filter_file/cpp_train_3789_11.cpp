#include <bits/stdc++.h>
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int s = 0;
  for (int i = 0; i < m; ++i) {
    int t, y, x, q, v;
    std::cin >> t;
    if (t == 1) {
      std::cin >> v >> x;
      a[v - 1] = x - s;
    } else if (t == 2) {
      std::cin >> y;
      s += y;
    } else if (t == 3) {
      std::cin >> q;
      std::cout << s + a[q - 1] << std::endl;
    }
  }
  return 0;
}

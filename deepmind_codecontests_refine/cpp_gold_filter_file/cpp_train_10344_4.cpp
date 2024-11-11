#include <bits/stdc++.h>
int main() {
  int n, m, a, b;
  std::map<int, int> t;
  long long r[2] = {};
  std::scanf("%d", &n);
  for (int i(0); i < n; ++i) {
    std::scanf("%d", &a);
    t[a] = i;
  }
  std::scanf("%d", &m);
  while (0 < m--) {
    std::scanf("%d", &b);
    r[0] += t[b] + 1;
    r[1] += n - t[b];
  }
  std::cout << r[0] << ' ' << r[1] << std::endl;
  return 0;
}

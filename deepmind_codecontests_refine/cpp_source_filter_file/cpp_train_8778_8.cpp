#include <bits/stdc++.h>
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int> > v(n);
  for (int i = 0; i < m; ++i) {
    std::cin >> v[i].second >> v[i].first;
  }
  std::sort(v.rbegin(), v.rend());
  int res = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    int x = std::min(n, v[i].second);
    res += x * v[i].first;
    n -= x;
  }
  std::cout << res << std::endl;
}

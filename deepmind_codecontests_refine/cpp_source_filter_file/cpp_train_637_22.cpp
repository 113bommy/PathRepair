#include <bits/stdc++.h>
int main() {
  int m, n;
  std::cin >> m >> n;
  std::vector<int> a;
  std::vector<int> b;
  for (int i = 0; i < m; ++i) {
    int l;
    std::cin >> l;
    a.push_back(l);
  }
  for (int i = 0; i < n; ++i) {
    int l;
    std::cin >> l;
    b.push_back(l);
  }
  int ans = 0;
  int r1, r2, r3, r4;
  r1 = r2 = r3 = r4 = 0;
  for (auto &it : a) {
    if (it % 2 == 0)
      r1++;
    else
      r2++;
  }
  for (auto &it : b) {
    if (it % 2 == 0)
      r3++;
    else
      r4++;
  }
  ans = std::min(r1, r2) + std::min(r3, r4);
  std::cout << ans;
}

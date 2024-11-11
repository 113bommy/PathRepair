#include <bits/stdc++.h>
int n, k;
inline int ca(int x) { return x % k == 0 ? ca(x / k) : x; }
int main() {
  std::cin >> n >> k;
  std::vector<int> a;
  for (int i = 1, x; i <= n; ++i) std::cin >> x, a.push_back(x);
  std::mt19937 rd(time(0));
  do {
    std::vector<int> b = a;
    std::vector<std::pair<int, int>> c;
    while (b.size() > 1) {
      std::shuffle(b.begin(), b.end(), rd);
      int x = b[b.size() - 1];
      int y = b[b.size() - 2];
      b.pop_back();
      b.pop_back();
      c.emplace_back(x, y);
      b.push_back(ca(x + y));
    }
    if (b[0] == 1) {
      std::cout << "YES" << '\n';
      for (auto i : c) std::cout << i.first << ' ' << i.second << '\n';
      return 0;
    }
  } while (double(clock()) / CLOCKS_PER_SEC < 1.6);
  std::cout << "NO" << '\n';
}

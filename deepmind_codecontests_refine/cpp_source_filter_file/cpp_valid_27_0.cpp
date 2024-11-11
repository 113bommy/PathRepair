#include <bits/stdc++.h>
using i64 = long long;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int q;
  std::cin >> q;
  while (q--) {
    std::string s, t;
    std::cin >> s >> t;
    int lens = s.size(), lent = t.size();
    if (lent > lens) {
      std::cout << "NO" << '\n';
      continue;
    }
    int pre = lens, fg = 0;
    for (int i = lens - 1, j = lent - 1; i >= 0; i--) {
      if (s[i] == t[j] && (pre - i) % 2 == 1) {
        j--, pre = i;
      }
      if (j == 0) {
        fg = 1;
        break;
      }
    }
    if (fg) {
      std::cout << "YES" << '\n';
    } else
      std::cout << "NO" << '\n';
  }
  return 0;
}

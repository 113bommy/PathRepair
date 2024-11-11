#include <bits/stdc++.h>
const char nl = '\n';
const int mod = (int)1e9 + 7;
int main() {
  std::cin.tie(0)->std::ios::sync_with_stdio(0);
  std::cin.exceptions(std::cin.failbit);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    int l = -1, r = -1;
    for (int i = 0; i < n - 1; i++) {
      if ((s[i] == 'a' && s[i + 1] == 'b') ||
          (s[i] == 'b' && s[i + 1] == 'a')) {
        l = i + 1;
        r = i + 2;
        break;
      }
    }
    std::cout << l << ' ' << r << nl;
  }
}

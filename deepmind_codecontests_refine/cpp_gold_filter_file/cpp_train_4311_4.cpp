#include <bits/stdc++.h>
int main() {
  std::string s;
  int n;
  std::cin >> s >> n;
  std::vector<int> v(26, 0);
  for (auto &c : s) {
    v[c - 'a']++;
  }
  for (std::size_t i = 1; i <= s.size(); i++) {
    int need = 0;
    for (auto &m : v) {
      need += (m + i - 1) / i;
    }
    if (need <= n) {
      std::string out;
      for (std::size_t j = 0; j < v.size(); j++) {
        for (std::size_t k = 0; k < (v[j] + i - 1) / i; k++, n--) {
          out += 'a' + j;
        }
      }
      while (n--) {
        out += 'z';
      }
      std::cout << i << '\n' << out << '\n';
      return 0;
    }
  }
  std::cout << -1 << '\n';
  return 0;
}

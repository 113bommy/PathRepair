#include <bits/stdc++.h>
std::vector<int> v;
int calc() {
  int ans = 0, open = 0;
  for (int it : v) {
    if (it == 1) {
      open++;
    } else {
      ans++;
    }
  }
  return ans + open / 2;
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    v = std::vector<int>();
    std::map<char, std::size_t> m;
    std::string s;
    std::cin >> s;
    for (char c : s) {
      if (m[c] == 0) {
        m[c] = v.size() + 1;
        v.push_back(0);
      }
      v[m[c] - 1]++;
    }
    std::cout << calc() << std::endl;
  }
}

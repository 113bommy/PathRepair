#include <bits/stdc++.h>
using llong = long long;
int solve(const std::string& s) {
  llong out = 0;
  std::map<char, llong> dict;
  for (const char& element : s) {
    dict[element]++;
  }
  for (auto it = dict.begin(); it != dict.end(); ++it) {
    out += it->second * it->second;
  }
  return out;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::string s;
  std::cin >> s;
  std::cout << solve(s) << std::endl;
}

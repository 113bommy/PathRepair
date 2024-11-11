#include <bits/stdc++.h>
int main() {
  std::size_t n, m;
  std::cin >> n >> m;
  std::string s;
  std::cin >> s;
  long dots = std::count(std::begin(s), std::end(s), '.');
  long groups = 0;
  bool in_group = false;
  for (const auto& x : s) {
    if (in_group && x != '.') {
      in_group = false;
    } else if (!in_group && x == '.') {
      groups += 1;
      in_group = true;
    }
  }
  s = "a" + s + "a";
  for (std::size_t i = 0; i < m; ++i) {
    std::size_t x;
    char c;
    std::cin >> x >> c;
    bool both_neighbors_are_dots = s.at(x - 1) == '.' and s.at(x + 1) == '.';
    bool both_neighbors_are_not_dots =
        s.at(x - 1) != '.' and s.at(x + 1) != '.';
    if (c == '.' && s.at(x) != '.') {
      dots += 1;
      if (both_neighbors_are_dots) {
        groups -= 1;
      } else if (both_neighbors_are_not_dots) {
        groups += 1;
      }
    } else if (c != '.' && s.at(x) == '.') {
      dots -= 1;
      if (both_neighbors_are_dots) {
        groups += 1;
      } else if (both_neighbors_are_not_dots) {
        groups -= 1;
      }
    }
    s.at(x) = c;
    std::cout << (dots - groups) << std::endl;
  }
  return 0;
}

#include <bits/stdc++.h>
const int kN = 100000 + 5;
int n, eg;
std::set<std::string> up[2];
std::vector<std::string> empty_seat[2], down[2];
std::vector<std::pair<std::string, std::string>> result;
template <typename T>
std::string to_string(T x) {
  std::stringstream ss;
  ss << x;
  return ss.str();
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char s[20];
    int tp;
    scanf("%s%d", s, &tp);
    up[tp].emplace(s);
    eg += tp == 1;
  }
  for (int i = 1; i <= n; ++i) {
    int tp = i <= eg;
    std::string s = to_string(i);
    if (up[tp].count(s)) {
      up[tp].erase(s);
    } else if (up[tp ^ 1].count(s)) {
      up[tp ^ 1].erase(s);
      down[tp ^ 1].emplace_back(s);
    } else {
      empty_seat[tp].emplace_back(s);
    }
  }
  while (true) {
    bool updated = false;
    for (int tp = 0; tp < 2; ++tp) {
      while (!down[tp].empty() && !empty_seat[tp].empty()) {
        std::string a = down[tp].back();
        down[tp].pop_back();
        std::string b = empty_seat[tp].back();
        empty_seat[tp].pop_back();
        result.emplace_back(a, b);
        empty_seat[tp ^ 1].emplace_back(a);
        updated = true;
      }
    }
    if (!updated) break;
  }
  for (int tp = 0; tp < 2; ++tp) {
    while (!up[tp].empty()) {
      std::string a = *up[tp].begin();
      up[tp].erase(a);
      std::string b = empty_seat[tp].back();
      empty_seat[tp].pop_back();
      result.emplace_back(a, b);
    }
  }
  if (!down[0].empty()) {
    std::string s_tmp = to_string(n + 1);
    result.emplace_back(down[1].back(), s_tmp);
    for (int i = (int)down[0].size() - 2; i >= 0; --i) {
      result.emplace_back(down[0][i + 1], down[1][i + 1]);
      result.emplace_back(down[1][i], down[0][i + 1]);
    }
    result.emplace_back(down[0][0], down[1][0]);
    result.emplace_back(s_tmp, down[0][0]);
  }
  printf("%d\n", result.size());
  for (const auto &t : result)
    printf("move %s %s\n", t.first.c_str(), t.second.c_str());
}

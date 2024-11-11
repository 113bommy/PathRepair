#include <bits/stdc++.h>
struct Hasher {
  size_t operator()(const std::vector<int> &v) const {
    return (v[0] + v[1]) * (v[0] + v[1] + 1) / 2 + v[0];
  }
};
int main() {
  int cases;
  int i;
  int j;
  int ct;
  std::cin >> cases;
  std::string output = "";
  std::unordered_map<std::vector<int>, int, Hasher> memo;
  while (cases--) {
    ct = 0;
    std::cin >> i >> j;
    int initi = i;
    int initj = j;
    auto elem = memo.find({i, j});
    if (elem != memo.end()) {
      ct = elem->second;
      goto end;
    }
    while (i > 0 && j > 0) {
      if (i >= j) {
        ct += i / j;
        i -= (i / j) * j;
      } else {
        ct += j / i;
        j -= (j / i) * j;
      }
    }
    memo[{initi, initj}] = ct;
  end:
    std::ostringstream s;
    s << ct << std::endl;
    output += s.str();
  }
  std::cout << output << std::endl;
}

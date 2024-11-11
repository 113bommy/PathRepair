#include <bits/stdc++.h>
struct rs {
  int r;
  int s;
};
bool isFirst(const rs& rs1, const rs& rs2) { return rs1.s > rs2.s; }
int main() {
  size_t n;
  int s;
  std::cin >> n >> s;
  std::vector<rs> vrs(n);
  int total = 0;
  for (size_t i = 0; i < n; ++i) {
    int x;
    int y;
    std::cin >> x >> y >> vrs[i].s;
    total += vrs[i].s;
    vrs[i].r = x * x + y * y;
  }
  if (total + s < 1000000) {
    std::cout << "-1";
    return 0;
  }
  std::sort(vrs.begin(), vrs.end(), isFirst);
  total = s;
  for (auto it = vrs.begin(); it != vrs.end(); ++it) {
    total += it->s;
    if (total >= 1000000) {
      std::cout << std::setprecision(20) << std::fixed << std::sqrt(it->r);
      return 0;
    }
  }
  std::cout << "-1";
  return 0;
}

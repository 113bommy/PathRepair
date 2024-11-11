#include <bits/stdc++.h>
using ul = std::uint32_t;
using ull = std::uint64_t;
using li = std::int32_t;
using ll = std::int64_t;
using vul = std::vector<ul>;
using vvul = std::vector<vul>;
using vull = std::vector<ull>;
using vvull = std::vector<vull>;
vull a(1 << 21);
vull b(1 << 21);
vull c(1 << 21);
vul cnt1(1 << 21, 0);
ul n;
void mobius(vull& a) {
  for (ul i = 0; i != n; ++i) {
    ul temp = (1 << n) - 1 & ~(1 << i);
    for (ul set = temp;; set = set - 1 & temp) {
      a[set | 1 << i] += a[set];
      if (!set) {
        break;
      }
    }
  }
}
void mobiusinv(vull& a) {
  for (ul i = 0; i != n; ++i) {
    ul temp = (1 << n) - 1 & ~(1 << i);
    for (ul set = temp;; set = set - 1 & temp) {
      a[set | 1 << i] -= a[set];
      if (!set) {
        break;
      }
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n;
  for (ul i = 1; i != (1 << n); ++i) {
    cnt1[i] = cnt1[i & ~(i & -i)] + 1;
  }
  for (ul i = 0; i != (1 << n); ++i) {
    char ch;
    std::cin >> ch;
    a[i] |= ull(ch - '0') << 3 * cnt1[i];
  }
  for (ul i = 0; i != (1 << n); ++i) {
    char ch;
    std::cin >> ch;
    b[i] |= ull(ch - '0') << 3 * cnt1[i];
  }
  mobius(a);
  mobius(b);
  for (ul set = 0; set != (1 << n); ++set) {
    c[set] = a[set] * b[set];
  }
  mobiusinv(c);
  for (ul set = 0; set != (1 << n); ++set) {
    std::cout << (c[set] >> cnt1[set] * 3 & 3);
  }
  std::cout << std::endl;
  return 0;
}

#include <bits/stdc++.h>
using ul = std::uint32_t;
using li = std::int32_t;
using ull = std::uint64_t;
using ll = std::int64_t;
using vul = std::vector<ul>;
using vvul = std::vector<vul>;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using vvvb = std::vector<vvb>;
using vull = std::vector<ull>;
using vli = std::vector<li>;
using vll = std::vector<ll>;
using pulul = std::pair<ul, ul>;
using vpulul = std::vector<pulul>;
ul w, n, m;
using llf = double;
const llf twoinv = llf(0.5);
std::vector<llf> f(1 << 12, 0);
std::vector<llf> g(1 << 12);
ul t;
std::string str;
ul all;
void trans() {
  t = 0;
  for (ul i = 0; i != w; ++i) {
    ul temp = all & ~(1 << i);
    if (str[i] == 'o' || str[i] == 'O') {
      for (ul s = temp;; s = (s - 1) & temp) {
        g[s | 1 << i] += g[s];
        if (!s) {
          break;
        }
      }
      if (str[i] == 'o') {
        t |= 1 << i;
      }
    } else if (str[i] == 'x' || str[i] == 'X') {
      for (ul s = temp;; s = (s - 1) & temp) {
        llf l = g[s], r = g[s | 1 << i];
        g[s] = l + r;
        g[s | 1 << i] = l - r;
        if (!s) {
          break;
        }
      }
      if (str[i] == 'x') {
        t |= 1 << i;
      }
    } else {
      for (ul s = temp;; s = (s - 1) & temp) {
        g[s] += g[s | 1 << i];
        if (!s) {
          break;
        }
      }
      if (str[i] == 'a') {
        t |= 1 << i;
      }
    }
  }
}
void transinv() {
  for (ul i = 0; i != w; ++i) {
    ul temp = all & ~(1 << i);
    if (str[i] == 'o' || str[i] == 'O') {
      for (ul s = temp;; s = (s - 1) & temp) {
        g[s | 1 << i] -= g[s];
        if (!s) {
          break;
        }
      }
    } else if (str[i] == 'x' || str[i] == 'X') {
      for (ul s = temp;; s = (s - 1) & temp) {
        llf l = g[s], r = g[s | 1 << i];
        g[s] = (l + r) * twoinv;
        g[s | 1 << i] = (l - r) * twoinv;
        if (!s) {
          break;
        }
      }
    } else {
      for (ul s = temp;; s = (s - 1) & temp) {
        g[s] -= g[s | 1 << i];
        if (!s) {
          break;
        }
      }
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> w >> n >> m;
  all = (1 << w) - 1;
  for (ul i = 0; i != n; ++i) {
    ul temp;
    std::cin >> temp;
    ++f[temp];
  }
  for (ul i = 0; i != m; ++i) {
    std::cin >> str;
    std::reverse(str.begin(), str.end());
    g = f;
    trans();
    for (ul i = 0; i != (1 << w); ++i) {
      g[i] *= g[i];
    }
    transinv();
    std::cout << std::llround(g[t]) << std::endl;
  }
  return 0;
}

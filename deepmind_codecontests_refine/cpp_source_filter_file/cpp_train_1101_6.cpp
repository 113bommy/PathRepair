#include <bits/stdc++.h>
bool check(std::vector<int> &v, int a) {
  auto l = std::lower_bound(v.begin(), v.end(), a);
  return l != v.end() && *l == a;
}
int main() {
  int b, q, l, m;
  std::cin >> b >> q >> l >> m;
  std::vector<int> v(m, 0);
  for (int i = 0; i < m; ++i) {
    std::cin >> v[i];
  }
  std::sort(v.begin(), v.end());
  if (b == 0) {
    if (check(v, b)) {
      std::cout << 0;
    } else {
      std::cout << "inf";
    }
    return 0;
  }
  if (q == 0) {
    if (std::abs(b) <= l) {
      if (!check(v, b)) {
        if (check(v, 0)) {
          std::cout << 1;
        } else {
          std::cout << "inf";
        }
      } else {
        if (check(v, 0)) {
          std::cout << 0;
        } else {
          std::cout << "inf";
        }
      }
    } else {
      std::cout << 0;
    }
    return 0;
  }
  if (q == 1) {
    if (std::abs(b) <= l && !check(v, b)) {
      std::cout << "inf";
    } else {
      std::cout << 0;
    }
    return 0;
  }
  if (q == -1) {
    if (std::abs(b) <= l && !(check(v, b) && check(v, -b))) {
      std::cout << "inf";
    } else {
      std::cout << 0;
    }
    return 0;
  }
  int count = 0;
  while (std::abs(b) <= l) {
    if (!check(v, b)) {
      ++count;
    }
    b *= q;
  }
  std::cout << count;
  return 0;
}

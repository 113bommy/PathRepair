#include <bits/stdc++.h>
int main() {
  int p1, p2, p3, p4, a, b;
  std::cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  std::vector<int> v{p1, p2, p3, p4};
  sort(v.begin(), v.end());
  if (v[0] < a) {
    std::cout << 0;
  } else if (v[0] > b) {
    if (a == b) {
      std::cout << 1;
    } else {
      std::cout << b - a + 1;
    }
  } else {
    std::cout << v[0] - a;
  }
}

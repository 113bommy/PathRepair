#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> v;
  int r = 1;
  while (n != 0) {
    if (n % 2) v.push_back(r);
    r++;
    n = n / 2;
  }
  for (int i = v.size() - 1; i != 0; --i) {
    std::cout << v[i];
    if (i != 0) std::cout << ' ';
  }
  return 0;
}

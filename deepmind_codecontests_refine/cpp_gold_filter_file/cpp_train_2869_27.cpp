#include <bits/stdc++.h>
int l, len, last;
int main() {
  std::cin >> l;
  std::string k[l];
  for (int i = 0; i < l; i++) {
    std::cin >> k[i];
  }
  for (int j = 0; j < l; j++) {
    int le = k[j].length();
    if (le > 10) {
      len = le - 2;
      last = le - 1;
      std::cout << k[j][0] << len << k[j][last] << std::endl;
    } else {
      std::cout << k[j] << std::endl;
    }
  }
  return 0;
}

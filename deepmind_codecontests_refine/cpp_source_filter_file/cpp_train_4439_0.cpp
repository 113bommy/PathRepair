#include <bits/stdc++.h>
int main() {
  std::string src;
  std::cin >> src;
  int nils = 0, one = 0;
  for (int i = src.length() - 1; i >= 0; --i) {
    if (src[i] == '0')
      ++nils;
    else if (nils >= 6)
      ++one;
  }
  std::cout << (nils > 6 && one > 0 ? "yes" : "no") << std::endl;
}

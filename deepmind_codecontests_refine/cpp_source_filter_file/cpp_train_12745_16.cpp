#include <bits/stdc++.h>
int main() {
  int n, p, k;
  std::cin >> n;
  std::cin >> p;
  std::cin >> k;
  bool overflow = false;
  int begin = p - k;
  int end = p + k;
  if (begin <= 0) {
    begin = 1;
  } else
    std::cout << "<< ";
  if (end >= n) {
    overflow = true;
    end = n;
  }
  for (int i = begin; i <= end; i++) {
    if (i == p)
      std::cout << " (" << i << ")";
    else
      std::cout << " " << i;
  }
  if (!overflow) std::cout << " >>" << std::endl;
  return 0;
}

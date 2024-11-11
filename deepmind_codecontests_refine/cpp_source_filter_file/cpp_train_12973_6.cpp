#include <bits/stdc++.h>
int main() {
  int N;
  std::cin >> N;
  float a = std::sqrt(N);
  int ia = a;
  float b = std::round(N / (float)ia);
  int ib = b;
  int p = (ia + ib) * 2;
  std::cout << p << std::endl;
  return 0;
}

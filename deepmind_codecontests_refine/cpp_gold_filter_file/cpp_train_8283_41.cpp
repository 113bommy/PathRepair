#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e, f, g, h, i, j, k;
  std::cin >> a >> b >> c >> d;
  e = a ^ b;
  f = c | d;
  g = b & c;
  h = a ^ d;
  i = e & f;
  j = g | h;
  k = i ^ j;
  std::cout << k << std::endl;
}

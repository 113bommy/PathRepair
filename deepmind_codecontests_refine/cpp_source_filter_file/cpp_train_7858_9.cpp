#include <bits/stdc++.h>
int max(int a, int b) {
  if (a >= b) return a;
  return b;
}
int main() {
  int n;
  std::cin >> n;
  int cn = 0, mx = -1111;
  int y = 0;
  while (n--) {
    int x;
    std::cin >> x;
    if (x >= y) {
      cn++;
      mx = max(mx, cn);
    } else
      cn = 0;
    y = x;
  }
  std::cout << mx << std::endl;
  ;
  return 0;
}

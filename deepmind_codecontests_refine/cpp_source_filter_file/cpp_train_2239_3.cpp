#include <bits/stdc++.h>
int main() {
  int d1, d2, d3;
  std::cin >> d1 >> d2 >> d3;
  int a[] = {d1 + d2 + d3, d1 + d2 + d2 + d1, d2 + d3 + d3 + d2,
             d1 + d1 + d2 + d2};
  std::sort(a, a + 4);
  std::cout << a[0];
  return 0;
}

#include <bits/stdc++.h>
int main() {
  int i, k, j, l, la;
  std::cin >> i >> k >> j >> l;
  if (i > l) {
    la = i;
    std::cout << la - l << " " << la - k << " " << la - j;
  } else if (k > l) {
    la = k;
    std::cout << la - i << " " << la - l << " " << la - j;
  } else if (j > l) {
    la = j;
    std::cout << la - i << " " << la - k << " " << la - l;
  } else
    std::cout << l - i << " " << l - k << " " << l - j;
  return 0;
}

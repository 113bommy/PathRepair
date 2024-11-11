#include <bits/stdc++.h>
int main() {
  int n, sum = 0, temp;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> temp;
    sum += temp;
  }
  long double res;
  res = (sum / 100.0) / n;
  std::cout << res;
  return 0;
}

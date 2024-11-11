#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  long long sum = 0;
  int j;
  for (int i = 2; i <= n / 2; i++) {
    j = 2;
    while (i * j <= n) {
      sum += j;
      j++;
    }
  }
  sum = sum * 4;
  std::cout << sum;
}

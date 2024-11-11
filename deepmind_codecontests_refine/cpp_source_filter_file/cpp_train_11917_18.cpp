#include <bits/stdc++.h>
int main() {
  int n, sum = 0, turn = 0, out = 0;
  std::cin >> n;
  for (int i = 1; i < 6; i++) {
    turn += i;
    sum += turn;
    if (sum == n) {
      out = i;
      break;
    } else if (sum > n) {
      out = i - 1;
      break;
    }
  }
  std::cout << out;
  return 0;
}

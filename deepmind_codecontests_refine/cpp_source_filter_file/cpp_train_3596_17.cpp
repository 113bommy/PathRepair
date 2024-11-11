#include <bits/stdc++.h>
int main() {
  int n, x;
  std::cin >> n >> x;
  int sad = 0;
  std::string curr;
  char sign;
  int amount;
  for (int i = 0; i < n; i++) {
    std::cin >> sign >> amount;
    if (sign == '+') {
      x += amount;
    } else {
      if (amount > x) {
        sad++;
      } else {
        x -= amount;
      }
    }
  }
  std::cout << x << " " << sad << std::endl;
  return 0;
}

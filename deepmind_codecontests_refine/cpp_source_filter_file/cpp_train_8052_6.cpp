#include <bits/stdc++.h>
int main() {
  int n, x;
  std::cin >> n >> x;
  int a, b;
  std::cin >> a >> b;
  std::string result = "YES";
  if (n > 1) {
    for (int i = 0; i < n; i++) {
      int a2, b2;
      std::cin >> a2 >> b2;
      int opp_x = 7 - x;
      int opp_a2 = 7 - a2;
      int opp_b2 = 7 - b2;
      if (opp_x == a2 || opp_x == opp_a2 || opp_x == b2 || opp_x == opp_b2) {
        result = "NO";
        break;
      } else {
        x = 7 - (a2 + b2 + opp_a2 + opp_b2 + x);
        a = a2;
        b = b2;
        std::cin >> a2 >> b2;
      }
    }
  }
  std::cout << result << std::endl;
  return 0;
}

#include <bits/stdc++.h>
bool is_simple(int num) noexcept {
  if (num < 2) return false;
  int bound = static_cast<int>(ceil(sqrt(num))) + 1;
  for (int i = 2; i < bound; ++i) {
    if (num % i == 0) return false;
  }
  return true;
}
int main() {
  int count = 0;
  std::cin >> count;
  for (int i = 0; i < count; ++i) {
    double cur_num;
    std::cin >> cur_num;
    double num = sqrt(cur_num);
    if (fabs(num - round(num)) < 0.01) {
      if (is_simple(static_cast<int>(round(num))))
        std::cout << "YES\n";
      else
        std::cout << "NO\n";
    } else
      std::cout << "NO\n";
  }
}

#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int32_t n;
  std::cin >> n;
  std::vector<int32_t> a(n);
  for (int32_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  std::cout << n / 2 << '\n';
  int32_t indLeft = 0, indRight = a.size() - 1;
  while (indLeft <= indRight) {
    std::cout << a[indRight--] << " ";
    if (indRight < indLeft) {
      break;
    }
    std::cout << a[indLeft++] << " ";
  }
  std::cout << '\n';
}

#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::string s1, s2;
  std::cin >> s1 >> s2;
  std::cout << s1 << " " << s2 << "\n";
  int n;
  std::cin >> n;
  while (n--) {
    std::string a, b;
    std::cin >> a >> b;
    if (a == s1) {
      s2 = b;
    } else {
      s1 = b;
    }
    std::cout << s1 << " " << s2 << "\n";
  }
  return 0;
}

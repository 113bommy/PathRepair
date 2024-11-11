#include <bits/stdc++.h>
int main() {
  std::string s, t;
  std::cin >> s >> t;
  int j = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == s[j]) j++;
  }
  std::cout << j++;
  return 0;
}

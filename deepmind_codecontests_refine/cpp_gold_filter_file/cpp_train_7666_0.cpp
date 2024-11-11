#include <bits/stdc++.h>
int main(int argc, char const *argv[]) {
  std::string s;
  std::cin >> s;
  if (s.length() < 26) {
    std::cout << "-1" << std::endl;
    return 0;
  }
  int i = 0;
  while (i < s.length() && s[i] != 'a') ++i;
  if (s.length() - i < 26) {
    std::cout << "-1" << std::endl;
    return 0;
  }
  char curr = 'b';
  for (int j = i + 1; j < s.length(); ++j) {
    while (s[j] < curr) s[j]++;
    if (s[j] == curr) curr++;
    if (curr == 'z' + 1) break;
    if (26 - (curr - 'a') >= s.length() - j) {
      std::cout << "-1" << std::endl;
      return 0;
    }
  }
  std::cout << s << std::endl;
  return 0;
}

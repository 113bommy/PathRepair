#include <bits/stdc++.h>
int main() {
  std::string s;
  std::cin >> s;
  int c = 4;
  if (s[0] == 'f') c = 3;
  s.insert(c, "://");
  c = s.find("ru");
  s.insert(c, ".");
  c += 3;
  if (c < s.length()) {
    s.insert(c, "/");
  }
  std::cout << s;
  return 0;
}

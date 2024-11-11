#include <bits/stdc++.h>
std::string s;
int main() {
  int n;
  std::string s;
  std::cin >> n;
  std::cin.ignore();
  int res = 1, last = -10, perlast = 0;
  for (int i = 0; i < n; i++) {
    getline(std::cin, s);
    int hh, mm;
    char x;
    sscanf(s.c_str(), "[%d:%d %c]", &hh, &mm, &x);
    hh %= 12;
    int cur = hh * 60 + mm;
    if (x == 'p') cur += 12 * 60;
    cur %= 24 * 60;
    if (cur == last) {
      perlast++;
      if (perlast > 10) res++, last = cur, perlast = 1;
    } else if (cur > last) {
      last = cur, perlast = 1;
    } else {
      res++, last = cur, perlast = 0;
    }
  }
  std::cout << res << "\n";
  return 0;
}

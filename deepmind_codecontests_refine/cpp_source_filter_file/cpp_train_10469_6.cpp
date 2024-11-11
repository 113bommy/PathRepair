#include <bits/stdc++.h>
int main() {
  std::string s;
  std::cin >> s;
  int start = 0;
  long long total = 0;
  for (int i = 0; i < s.length(); i++) {
    int pos = s[i] - 'a';
    if (start > pos) pos += 26;
    int min = std::min(pos - start, 26 - (pos - start));
    if (min < 0) min = -min;
    total += min;
    start = pos;
  }
  std::cout << total << std::endl;
  return 0;
}

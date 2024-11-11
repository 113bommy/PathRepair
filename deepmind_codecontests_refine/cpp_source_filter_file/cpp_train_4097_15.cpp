#include <bits/stdc++.h>
void myassert(bool x) {
  if (!x) std::cout << 1 / (int)x << std::endl;
}
int main() {
  std::string s;
  int h[128] = {0};
  std::cin >> s;
  myassert(s.length() > 0 && s.length() < 100 * 1000);
  for (int i = 0; i < 128; i++) h[i] = -1;
  for (size_t i = 0; i < s.length(); i++) {
    myassert(s[i] >= 'a' && s[i] <= 'z');
    h[s[i]] = i;
  }
  std::string r;
  char cMax = 'z';
  while (cMax >= 'a' && h[cMax] == -1) --cMax;
  myassert(cMax >= 'a');
  for (size_t i = 0; i < s.length(); i++) {
    myassert(cMax >= 'a');
    if (s[i] == cMax) r.push_back(cMax);
    if (h[cMax] == i) {
      cMax--;
      while (cMax >= 'a' && h[cMax] < i) {
        --cMax;
      }
    }
  }
  std::cout << r << std::endl;
  return 0;
}

#include <bits/stdc++.h>
void clearL(std::vector<int8_t>* l) {
  for (std::vector<int8_t>*b = l, *e = l + 'z' - 'a' + 1; b != e; ++b) {
    b->clear();
  }
}
int main() {
  uint8_t q;
  std::vector<int8_t> l['z' - 'a' + 1];
  std::vector<int8_t> c('z' - 'a' + 1, 0);
  scanf("%hhu", &q);
  fgetc(stdin);
  std::stringstream result;
  for (; q; --q, clearL(l)) {
    uint8_t n;
    scanf("%hhu", &n);
    fgetc(stdin);
    char* s = new char[n + 1];
    char* t = new char[n + 1];
    fgets(s, n + 1, stdin);
    fgetc(stdin);
    fgets(t, n + 1, stdin);
    fgetc(stdin);
    for (int8_t i = 0; i < n; ++i) {
      l[s[i] - 'a'].push_back(i);
      c[t[i] - 'a'] += 1;
    }
    bool f = false;
    for (int8_t i = 0; i <= 'z' - 'a'; ++i) {
      if (l[i].size() != c[i]) {
        result << "-1" << std::endl;
        f = true;
        break;
      }
    }
    std::fill(c.begin(), c.end(), 0);
    if (f) {
      continue;
    }
    uint8_t currentResult = n;
    uint8_t currentLen = 0;
    int8_t currentIndex = -1;
    for (uint8_t i = 0; i < currentResult;
         ++i, currentLen = 0, currentIndex = -1) {
      for (uint8_t j = i; j < n; ++j, ++currentLen) {
        std::vector<int8_t>::iterator it = std::upper_bound(
            l[t[j] - 'a'].begin(), l[t[j] - 'a'].end(), currentIndex);
        if (it == l[t[j] - 'a'].end())
          break;
        else
          currentIndex = *it;
      }
      if (n - currentLen < currentResult) currentResult = n - currentLen;
    }
    result << (uint16_t)currentResult << std::endl;
  }
  std::cout << result.str();
}

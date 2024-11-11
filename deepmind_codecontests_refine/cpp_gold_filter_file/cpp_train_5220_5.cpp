#include <bits/stdc++.h>
using namespace std;
int isPalin(string s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) return 0;
    ++i;
    --j;
  }
  return 1;
}
int main() {
  string s;
  cin >> s;
  char f = s[0];
  int fl = 1;
  for (int i = 0; i < s.size() / 2; ++i) {
    if (s[i] != f) {
      fl = 0;
      break;
    }
  }
  if (fl) {
    printf("Impossible");
    return 0;
  }
  for (int i = 1; i < s.size(); ++i) {
    string s1 = s.substr(i, s.size()) + s.substr(0, i);
    if (s.compare(s1) && isPalin(s1)) {
      printf("1");
      return 0;
    }
  }
  printf("2");
  return 0;
}

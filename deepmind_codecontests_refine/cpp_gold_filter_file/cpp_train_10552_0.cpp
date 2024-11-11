#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k;
  int len;
  string s;
  cin >> s;
  len = s.length();
  for (i = len - 1; i > 0; --i) {
    set<string> cc;
    for (j = 0; j + i <= len; ++j) {
      if (cc.find(s.substr(j, i)) != cc.end()) break;
      cc.insert(s.substr(j, i));
    }
    if (j + i <= len) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("0");
  return 0;
}

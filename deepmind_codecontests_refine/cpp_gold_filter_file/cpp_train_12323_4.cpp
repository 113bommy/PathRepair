#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[9];
  bool ok = 1;
  for (int i = 0; i < 8; ++i) {
    scanf("%s", s);
    for (int j = 0; j < 7; ++j) {
      if (s[j] == s[j + 1]) ok = 0;
    }
  }
  puts(ok ? "YES" : "NO");
  return 0;
}

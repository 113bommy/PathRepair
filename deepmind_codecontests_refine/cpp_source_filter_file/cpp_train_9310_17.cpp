#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[110];
  string ans = "";
  scanf("%s", s);
  int n = strlen(s);
  for (int i = n - 1; i > 1; i--) {
    if (s[i] == 't' && s[i - 1] == 'a') {
      if (i < n - 1) {
        s[i] = '?';
        s[i - 1] = '?';
        break;
      }
    }
  }
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == '?') continue;
    if (s[i] == 'o' && s[i - 1] == 'd' && s[i + 1] == 't') {
      if (i + 1 == n - 1) break;
      if (i - 1 == 0) continue;
      s[i - 1] = s[i] = s[i + 1] = '*';
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      ans += "@";
      i++;
      continue;
    }
    if (s[i] == '*') {
      ans += '.';
      i += 2;
      continue;
    }
    ans += s[i];
  }
  printf("%s\n", ans.c_str());
  return 0;
}

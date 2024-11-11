#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[201], a[201];
  int i(0), j(0), n;
  gets(s);
  n = strlen(s);
  for (i = 0; i <= n; i++) {
    if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
      i = i + 2;
    } else {
      a[j++] = s[i];
      if (s[i + 1] == 'W' && s[i + 2] == 'U' && s[i + 3] == 'B' &&
          s[i + 4] == '\n') {
      } else if (s[i + 1] == 'W' && s[i + 2] == 'U' && s[i + 3] == 'B') {
        a[j++] = ' ';
      }
    }
  }
  for (i = 0; i <= strlen(a); i++) {
    cout << a[i];
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char s[50][50];
int main() {
  int i, j, k[50], n;
  char *ptr, str[50];
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s[i];
    k[i] = strlen(s[i]);
  }
  str[0] = 'a';
  str[1] = '\0';
  int g = 0;
  while (1) {
    int f = 0;
    for (i = 1; i <= n; i++) {
      ptr = strstr(s[i], str);
      if (ptr) {
        f = 1;
      }
    }
    if (!f) break;
    if (str[g] == 'z') {
      int ff = 0;
      for (i = g - 1; i >= 0; i--)
        if (str[i] != 'z') {
          str[i] += 1;
          ff = 1;
          break;
        }
      str[g] = 'a';
      if (!ff) {
        g++;
        str[g] = 'a';
        str[g + 1] = '\0';
      }
    } else {
      str[g] = str[g] + 1;
    }
  }
  puts(str);
  return 0;
}

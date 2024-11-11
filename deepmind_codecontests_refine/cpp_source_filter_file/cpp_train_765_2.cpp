#include <bits/stdc++.h>
using namespace std;
int s[50];
char a[55][55];
int main() {
  int n, i, j, c = 1, k, found;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", a[i]);
    int l = strlen(a[i]);
    for (j = 0; j < l; j++) {
      s[a[i][j] - 'a']++;
    }
  }
  for (i = 0; i < 26; i++) {
    if (s[i] == 0) {
      printf("%c", (char)(i + 'a'));
      c = 1;
      break;
    } else
      c = 2;
  }
  if (c == 2) {
    for (i = 0; i < 26; i++) {
      for (j = 0; j < 26; j++) {
        char str[4];
        found = 0;
        str[0] = (char)(i + 'a');
        str[1] = (char)(j + 'a');
        for (k = 0; k < n; k++) {
          int l = strlen(a[k]), x = 0;
          while (x < (l - 1)) {
            if (a[i][x] == str[0] && a[i][x + 1] == str[1]) {
              found = 1;
              break;
            } else
              x++;
          }
          if (found == 1) break;
        }
        if (found == 0) {
          printf("%c%c\n", str[0], str[1]);
          c = 3;
          break;
        }
      }
      if (c == 3) break;
    }
  }
  return 0;
}

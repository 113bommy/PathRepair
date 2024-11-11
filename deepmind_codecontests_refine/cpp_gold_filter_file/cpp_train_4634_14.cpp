#include <bits/stdc++.h>
int main() {
  int i, j, k, n, m, l, c = 0, flag = 1;
  char s[102];
  scanf("%s", s);
  l = strlen(s);
  if (l < 5) {
    printf("NO");
    return 0;
  }
  for (i = 0; i < l; i++) {
    if (s[i] == 'h') {
      for (j = i + 1; j < l; j++) {
        if (s[j] == 'e') {
          for (k = j + 1; k < l; k++) {
            if (s[k] == 'l') {
              for (n = k + 1; n < l; n++) {
                if (s[n] == 'l') {
                  for (m = n + 1; m < l; m++) {
                    if (s[m] == 'o') {
                      flag = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (flag == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}

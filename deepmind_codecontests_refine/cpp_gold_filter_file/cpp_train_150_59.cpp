#include <bits/stdc++.h>
int main() {
  char s[101];
  int n, i, j, k, l = 0;
  scanf("%d", &n);
  scanf("%s", &s);
  for (i = 1; i < n / 4 + 1; i++) {
    for (j = 0; j < n; j++) {
      l = 0;
      if (s[j] == '*') {
        for (k = j; k < n; k += i) {
          if (s[k] == '*') {
            l++;
            if (l == 5) {
              printf("YES");
              return 0;
            }
          } else {
            break;
          }
        }
      }
    }
  }
  printf("NO");
  return 0;
}

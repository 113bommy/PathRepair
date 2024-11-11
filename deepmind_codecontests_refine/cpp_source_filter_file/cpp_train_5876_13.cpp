#include <bits/stdc++.h>
int main() {
  int c, d, i, x;
  char a[101], b[101];
  gets(a);
  gets(b);
  c = strlen(a);
  d = strlen(b);
  if (c == d) {
    for (i = 0; i <= c; i++) {
      if (a[i] == b[d - 1]) {
        x = 1;
      } else {
        printf("NO");
        return 0;
      }
      d--;
    }
  } else {
    printf("NO");
  }
  if (x == 1) {
    printf("YES");
  }
}

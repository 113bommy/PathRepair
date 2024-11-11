#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, c, d, l;
  char a[300], b[400];
  while (scanf("%s", a) == 1) {
    l = strlen(a);
    int flag = 0;
    c = -1;
    d = 0;
    if (a[0] == '@' || a[l - 1] == '@')
      printf("No solution\n");
    else {
      k = 0;
      for (i = 0; i < l; i++) {
        if (a[i] == '@' && k == 0) {
          c = i;
          k = 1;
        } else if (a[i] == '@' && k == 1) {
          d = i;
        }
        if (c && d) {
          if (d - c <= 2) {
            printf("No solution\n");
            flag = 1;
            break;
          }
          c = d;
          d = 0;
        }
      }
      if (!flag) {
        if (c == -1)
          printf("No solution\n");
        else {
          k = 0;
          for (i = 0; i < l; i++) {
            if (!k && a[i] != '@')
              printf("%c", a[i]);
            else if (a[i] == '@') {
              printf("%c", a[i]);
              if (i == c)
                k = 3;
              else
                k = 1;
            } else if (k == 1) {
              printf("%c", a[i]);
              k = 2;
            } else if (k == 2) {
              printf(",%c", a[i]);
              k = 0;
            } else
              printf("%c", a[i]);
          }
          printf("\n");
        }
      }
    }
    memset(a, 0, sizeof(a));
  }
  return 0;
}

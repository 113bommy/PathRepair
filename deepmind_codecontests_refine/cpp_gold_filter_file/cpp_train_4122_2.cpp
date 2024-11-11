#include <bits/stdc++.h>
char c[1000];
char num[4];
int cnt = 0;
char curr = '+';
int w = 0;
int main() {
  scanf("%s", c);
  for (int i = 0; i == 0 || c[i - 1]; i++) {
    if (c[i] >= '0' && c[i] <= '9')
      num[cnt++] = c[i];
    else {
      int x;
      sscanf(num, "%i", &x);
      if (curr == '-')
        w -= x;
      else
        w += x;
      memset(num, 0, 4);
      cnt = 0;
      curr = c[i];
    }
  }
  sprintf(num, "%i", w);
  for (int i = 0; num[i]; i++) {
    for (int j = 0; j < num[i]; j++) putchar('+');
    printf(".>");
  }
}

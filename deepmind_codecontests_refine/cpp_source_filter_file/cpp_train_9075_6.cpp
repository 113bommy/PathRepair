#include <bits/stdc++.h>
int main() {
  char str[50];
  scanf("%s", str);
  int i = 0;
  int c4 = 0, c7 = 0, first = 0;
  while (str[i]) {
    if (str[i] - '0' == 4) {
      if (first == 0) first = 4;
      c4++;
    } else if (str[i] - '0' == 7) {
      if (first == 0) first = 7;
      c7++;
    }
    i++;
  }
  if (c4 == 0 && c7 == 0)
    printf("-1");
  else if (c4 > c7)
    printf("4");
  else if (c7 > c4)
    printf("7");
  else
    printf("%d", first);
  return 0;
}

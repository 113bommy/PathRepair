#include <bits/stdc++.h>
int main() {
  int date;
  char qq[6];
  char ww[6] = {'w', 'e', 'e', 'k', '\0'};
  char ee[6] = {'m', 'o', 'n', 't', 'h', '\0'};
  scanf("%d of %s", &date, &qq);
  if (strcmp(qq, ww) == 0) {
    if (date == 1)
      printf("%d\n", 53);
    else if (date == 2)
      printf("%d\n", 53);
    else if (date == 3)
      printf("%d\n", 52);
    else if (date == 4)
      printf("%d\n", 52);
    else if (date == 5)
      printf("%d\n", 52);
    else if (date == 6)
      printf("%d\n", 52);
    else
      printf("%d\n", 52);
  } else if (strcmp(qq, ee) == 0) {
    if (date == 30)
      printf("%d\n", 11);
    else if (date == 31)
      printf("%d\n", 7);
    else
      printf("%d\n", 12);
  }
  return 0;
}

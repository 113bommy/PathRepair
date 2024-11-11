#include <bits/stdc++.h>
int main() {
  char Str[200];
  int upr = 0, lwr = 0;
  scanf("%s", Str);
  for (int i = 0; Str[i] != '\0'; (Str[i] < 97) ? upr++ : lwr++, i++)
    ;
  if (lwr >= upr) {
    for (int i = 0; Str[i] != '\0'; i++) {
      if (Str[i] < 97)
        printf("%c", Str[i] + 32);
      else
        printf("%c", Str[i]);
    }
  } else {
    for (int i = 0; Str[i] != '\0'; i++) {
      if (Str[i] > 97)
        printf("%c", Str[i] - 32);
      else
        printf("%c", Str[i]);
    }
  }
}

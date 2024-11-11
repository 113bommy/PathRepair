#include <bits/stdc++.h>
char str[1111111], ans[1111111];
int main() {
  while (scanf("%s", &str) != EOF) {
    int f1 = 1, f6 = 1, f9 = 1, f8 = 1;
    int tp = 0, len = strlen(str);
    int tot = 0;
    for (int i = 0; i < len; i++) {
      if (f1 && str[i] == '1') {
        f1--;
        continue;
      }
      if (f6 && str[i] == '6') {
        f6--;
        continue;
      }
      if (f9 && str[i] == '9') {
        f9--;
        continue;
      }
      if (f8 && str[i] == '8') {
        f8--;
        continue;
      }
      ans[tot++] = str[i];
      tp = (tp * 10 + str[i] - '0') % 7;
    }
    ans[tot] = '\0';
    int ling = 0, flag = 0;
    for (int i = 0; i < tot; i++) {
      if (!flag && ans[i] == '0')
        ling++;
      else {
        printf("%c", str[i]), flag++;
      }
    }
    if (tp == 0)
      printf("1869");
    else if (tp == 1)
      printf("6198");
    else if (tp == 2)
      printf("1896");
    else if (tp == 3)
      printf("6981");
    else if (tp == 4)
      printf("1986");
    else if (tp == 5)
      printf("1968");
    else if (tp == 6)
      printf("1698");
    for (int i = 0; i < ling; i++) printf("0");
    printf("\n");
  }
  return 0;
}

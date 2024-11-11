#include <bits/stdc++.h>
int main() {
  int i, j, k;
  char str[81];
  char str_t[11];
  char str_a[10][11];
  gets(str);
  int begin = 0;
  int end = 0;
  for (i = 0; i < 10; i++) {
    scanf("%s", &str_a[i]);
  }
  for (i = 0; i <= 8; i++) {
    k = 0;
    for (j = begin; j < end; j++) {
      str_t[k++] = str[j];
    }
    str_t[k] = '\0';
    begin = end;
    end += 10;
    for (j = 0; j < 10; j++) {
      if (strcmp(str_t, str_a[j]) == 0) {
        printf("%d", j);
        break;
      }
    }
  }
  printf("\n");
  return 0;
}

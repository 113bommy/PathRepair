#include <bits/stdc++.h>
char num[1010];
int k;
int main() {
  gets(num);
  int i, len = strlen(num);
  for (i = 0; i < len; i++) {
    if (num[i] == '.') {
      break;
    }
  }
  if (num[i - 1] == '9') {
    printf("GOTO Vasilisa.\n");
  } else {
    if (num[i + 1] >= '5') {
      int f = 1;
      num[i - 1]++;
      for (int j = 0; j < i; j++) {
        if (num[j] == '0' && f) {
          if (j == i - 1) {
            printf("0");
          }
          continue;
        } else {
          f = 0;
        }
        printf("%c", num[j]);
      }
      printf("\n");
    } else {
      int f = 1;
      for (int j = 0; j < i; j++) {
        if (num[j] == '0' && f) {
          if (j == i - 1) {
            printf("0");
          }
          continue;
        } else {
          f = 0;
        }
        printf("%c", num[j]);
      }
      printf("\n");
    }
  }
  return 0;
}

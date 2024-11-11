#include <bits/stdc++.h>
char str[20];
int t;
int i, j, k;
int main() {
  scanf("%s", str);
  i = 0;
  while (str[i]) {
    if (i > 0)
      t = str[i] - str[i - 1];
    else
      t = str[i];
    if (t < 0) t += 256;
    for (j = 0; j < 512; j++) printf(".");
    printf("\n");
    for (j = 0; j < 256 - t; j++) printf(".X");
    for (j = 0; j < 2 * t; j++) printf(".");
    printf("\n");
    for (j = 0; j < 512; j++) printf(".");
    printf("\n");
    printf(".XX.");
    for (j = 4; j < 512; j++) printf(".");
    printf("\n");
    printf(".X..");
    for (j = 4; j < 512; j++) printf(".");
    printf("\n");
    i++;
  }
  return 0;
}

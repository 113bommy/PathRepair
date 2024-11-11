#include <bits/stdc++.h>
int main() {
  int T;
  scanf("%d", &T);
  char card[20];
  int a[] = {1, 2, 3, 4, 6, 12, 0};
  int count[10];
  int flag;
  int i, colum, row;
  int res;
  while (T--) {
    memset(count, 0, sizeof(count));
    res = 0;
    scanf("%s", card);
    for (i = 0; i < 6; i++) {
      flag = 1;
      for (colum = 0; colum < 12 / a[i]; colum++) {
        flag = 1;
        for (row = 0; row < a[i]; row++) {
          if (card[(12 / a[i]) * row + colum] == 'O') {
            flag = 0;
            break;
          }
        }
        if (flag) {
          count[i] = 1;
          res++;
          break;
        }
      }
    }
    printf("%d", res);
    for (i = 0; i < 6; i++) {
      if (count[i]) printf(" %dx%d", a[i], 12 / a[i]);
    }
    printf("\n");
  }
  return 0;
}

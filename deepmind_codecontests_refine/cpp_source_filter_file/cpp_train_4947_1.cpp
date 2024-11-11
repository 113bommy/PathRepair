#include <bits/stdc++.h>
int main() {
  char jak[1000000], tak[1000000];
  gets(jak);
  gets(tak);
  int k, r, i, t, flag = 0, count = 0, fount = 0, f, x, y, j, p = 0;
  k = strlen(jak);
  r = strlen(tak);
  for (i = 0; i < k; i++) {
    t = jak[i] - 48;
    if (t != 0 && flag == 0) {
      flag = 1;
      x = i;
    }
    if (flag == 1) {
      count++;
    }
  }
  flag = 0;
  for (i = 0; i < r; i++) {
    f = tak[i] - 48;
    if (f != 0 && flag == 0) {
      flag = 1;
      y = i;
    }
    if (flag == 1) {
      fount++;
    }
  }
  if (count > fount) {
    printf(">");
  } else if (count < fount) {
    printf("<");
  } else if (count == 0) {
    printf("=");
  } else {
    for (i = x, j = y; i < k, j < r; i++, j++) {
      if (jak[i] > tak[j]) {
        printf(">");
        break;
      } else if (jak[i] < tak[j]) {
        printf("<");
        break;
      } else {
        p++;
      }
    }
    if (p == count) {
      printf("=");
    }
  }
}

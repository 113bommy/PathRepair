#include <bits/stdc++.h>
int main() {
  int x[1000][2];
  int num, i, j, f, l, temp, a;
  int ar[10001] = {0};
  int arn[10001] = {0};
  ;
  scanf("%d", &num);
  for (i = 0; i < num; i++) {
    x[i][0] = 0;
    x[i][1] = 0;
    x[i][2] = 0;
  }
  for (i = 0; i < num; i++) {
    scanf("%d %d", &f, &l);
    if (f > l) {
      temp = f;
      f = l;
      l = temp;
    }
    x[i][0] = f;
    x[i][1] = l;
  }
  for (i = 0; i < num; ++i) {
    for (j = i + 1; j < num; ++j) {
      if (x[i][1] > x[j][1]) {
        a = x[i][0];
        x[i][0] = x[j][0];
        x[j][0] = a;
        a = x[i][1];
        x[i][1] = x[j][1];
        x[j][1] = a;
      }
    }
  }
  a = 0;
  for (i = 0; i < num; ++i) {
    f = x[i][0];
    l = x[i][1];
    temp = 0;
    for (j = f; j <= l; j++) {
      if (j >= 0) {
        if (ar[j] == 1) temp = 1;
      } else {
        if (arn[-j] == 1) temp = 1;
      }
    }
    if (temp == 0) {
      if (l >= 0)
        ar[l] = 1;
      else
        arn[-l] = 1;
    }
    temp = 0;
  }
  for (i = 0; i < 10001; ++i) {
    temp = temp + ar[i];
  }
  for (i = 0; i < 10001; ++i) {
    temp = temp + arn[i];
  }
  printf("%d\n", temp);
  for (i = 0; i < 10001; ++i) {
    if (arn[i]) printf("%d ", -i);
  }
  for (i = 0; i < 10001; ++i) {
    if (ar[i]) printf("%d ", i);
  }
}

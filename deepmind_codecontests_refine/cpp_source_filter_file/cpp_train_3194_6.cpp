#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  char a[n];
  scanf("%s", a);
  int i, j;
  int flag = 1;
  if (n == 1) {
    if (a[0] == '0') flag = 0;
  } else if (n == 2) {
    if ((a[0] - '0') ^ (a[1] - '0') == 1) flag = 0;
  } else if (n >= 3) {
    i = 0, j = n - 1;
    while (i < n && a[i] == '0') {
      i++;
    }
    if (i > 1) {
      flag = 0;
    }
    while (j >= 0 && a[j] == '0') {
      j--;
    }
    if (j < n - 2) {
      flag = 0;
    }
    if (flag != 0) {
      while (i < n) {
        if (a[i] == '1' && i < n - 1) {
          if (a[i + 1] == '1') {
            flag = 0;
            break;
          } else
            i++;
        } else if (a[i] == '0' && i < n) {
          int c = 0;
          while (a[i] == '0' && i < n) {
            c++;
            i++;
          }
          if (c > 2) {
            flag = 0;
            break;
          }
        } else
          break;
        if (flag == 0) break;
      }
    }
  }
  if (flag == 0)
    printf("No\n");
  else
    printf("Yes\n");
  return 0;
}

#include <bits/stdc++.h>
int main() {
  int n, i, flag = 0;
  scanf(" %d", &n);
  if (n < 56) {
    for (i = 1; i < 11; i++)
      if ((i * (i + 1)) / 2 == n) {
        printf("YES");
        flag = 1;
        break;
      }
  } else if (n < 211) {
    for (i = 11; i < 21; i++)
      if ((i * (i + 1)) / 2 == n) {
        printf("YES");
        flag = 1;
        break;
      }
  } else if (n < 497) {
    for (i = 21; i < 32; i++)
      if ((i * (i + 1)) / 2 == n) {
        printf("YES");
        flag = 1;
        break;
      }
  }
  if (flag == 0) printf("NO");
  return 0;
}

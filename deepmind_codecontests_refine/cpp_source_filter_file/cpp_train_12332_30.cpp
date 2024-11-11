#include <bits/stdc++.h>
int a[5];
char size[5][10] = {"S", "M", "L", "XL", "XXL"};
void exe(int x) {
  int i = 1, m = 0;
  while (i < 8) {
    if (i % 2 == 0) {
      x -= i;
    } else
      x += i;
    if (x >= 0 && x < 5) {
      if (a[x] > 0) {
        a[x]--;
        printf("%s\n", size[x]);
        break;
      }
    }
    i++;
  }
}
int main() {
  scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
  int n;
  scanf("%d", &n);
  char str[10];
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    if (strcmp(str, size[0]) == 0) {
      if (a[0] == 0) {
        exe(0);
      } else {
        a[0]--;
        printf("%s\n", size[0]);
      }
    } else if (strcmp(str, size[1]) == 0) {
      if (a[1] == 0) {
        exe(1);
      } else {
        a[1]--;
        printf("%s\n", size[1]);
      }
    } else if (strcmp(str, size[2]) == 0) {
      if (a[2] == 0) {
        exe(2);
      } else {
        a[2]--;
        printf("%s\n", size[2]);
      }
    } else if (strcmp(str, size[3]) == 0) {
      if (a[3] == 0) {
        exe(3);
      } else {
        a[3]--;
        printf("%s\n", size[3]);
      }
    } else if (strcmp(str, size[4]) == 0) {
      if (a[4] == 0) {
        exe(4);
      } else {
        a[4]--;
        printf("%s\n", size[4]);
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char s[5][10] = {"S", "M", "L", "XL", "XXL"};
int a[5][5] = {{0, 1, 2, 3, 4},
               {1, 2, 0, 3, 4},
               {2, 3, 1, 4, 0},
               {3, 4, 2, 1, 0},
               {4, 3, 2, 1, 0}};
int num[5], n;
char str[10];
int main() {
  while (scanf("%d", &num[0]) == 1) {
    for (int i = 1; i < 5; ++i) scanf("%d", &num[i]);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%s", str);
      if (str[0] == 'S') {
        for (int j = 0; j < 5; ++j)
          if (num[a[0][j]]) {
            num[a[0][j]]--;
            printf("%s\n", s[a[0][j]]);
            break;
          }
      } else if (str[0] == 'M') {
        for (int j = 0; j < 5; ++j)
          if (num[a[1][j]]) {
            num[a[1][j]]--;
            printf("%s\n", s[a[1][j]]);
            break;
          }
      } else if (str[0] == 'L') {
        for (int j = 0; j < 5; ++j)
          if (num[a[2][j]]) {
            num[a[2][j]]--;
            printf("%s\n", s[a[2][j]]);
            break;
          }
      } else if (str[1] == 'L') {
        for (int j = 0; j < 5; ++j)
          if (num[a[3][j]]) {
            num[a[3][j]]--;
            printf("%s\n", s[a[3][j]]);
            break;
          }
      } else {
        for (int j = 0; j < 5; ++j)
          if (num[a[4][j]]) {
            num[a[4][j]]--;
            printf("%s\n", s[a[4][j]]);
            break;
          }
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  cin >> n;
  char str[20];
  int a[10];
  while (n--) {
    ans = 0;
    memset(a, 0, sizeof a);
    scanf("%s", str);
    for (int i = 0; i < 12; ++i) {
      if (str[i] == 'X') {
        ++ans;
        a[1] = 1;
        break;
      }
    }
    for (int i = 0; i < 6; ++i) {
      if (str[i] == 'X' && str[i + 6] == 'X') {
        ++ans;
        a[2] = 1;
        break;
      }
    }
    for (int i = 0; i < 4; ++i) {
      if (str[i] == 'X' && str[i + 4] == 'X' && str[i + 8] == 'X') {
        ++ans;
        a[3] = 1;
        break;
      }
    }
    for (int i = 0; i < 3; ++i) {
      if (str[i] == 'X' && str[i + 3] == 'X' && str[i + 6] == 'X' &&
          str[i + 9] == 'X') {
        ++ans;
        a[4] = 1;
        break;
      }
    }
    for (int i = 0; i < 2; ++i) {
      if (str[i] == 'X' && str[i + 2] == 'X' && str[i + 4] == 'X' &&
          str[i + 6] == 'X' && str[i + 8] == 'X' && str[i + 10] == 'X') {
        ++ans;
        a[5] = 1;
        break;
      }
    }
    ++ans;
    a[6] = 1;
    for (int i = 0; i < 12; ++i) {
      if (str[i] != 'X') {
        --ans;
        a[6] = 0;
        break;
      }
    }
    printf("%d ", ans);
    for (int i = 1; i <= 6; ++i) {
      if (a[i]) {
        switch (i) {
          case 1:
            printf("1x12 ");
            break;
          case 2:
            printf("2x6 ");
            break;
          case 3:
            printf("3x4 ");
            break;
          case 4:
            printf("4x3 ");
            break;
          case 5:
            printf("6x2 ");
            break;
          case 6:
            printf("12x1 ");
            break;
        }
      }
    }
    printf("\n");
  }
}

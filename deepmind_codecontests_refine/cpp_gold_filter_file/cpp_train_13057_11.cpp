#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, ans;
  int flag[15];
  char str[20];
  while (~scanf("%d", &t)) {
    while (t--) {
      memset(flag, 0, sizeof(flag));
      flag[12] = 1;
      ans = 0;
      scanf("%s", str);
      for (int i = 0; i < 12; i++) {
        if (str[i] == 'X') {
          flag[1] = 1;
        }
        if (str[i] == 'O') {
          flag[12] = 0;
        }
      }
      for (int i = 0; i < 6; i++) {
        if (str[i] == str[i + 6] && str[i] == 'X') {
          flag[2] = 1;
          break;
        }
      }
      for (int i = 0; i < 4; i++) {
        if (str[i] == str[i + 4] && str[i] == str[i + 8] && str[i] == 'X') {
          flag[3] = 1;
          break;
        }
      }
      for (int i = 0; i < 3; i++) {
        if (str[i] == str[i + 3] && str[i] == str[i + 6] &&
            str[i] == str[i + 9] && str[i] == 'X') {
          flag[4] = 1;
          break;
        }
      }
      for (int i = 0; i < 2; i++) {
        if (str[i] == str[i + 2] && str[i] == str[i + 4] &&
            str[i] == str[i + 6] && str[i] == str[i + 8] &&
            str[i] == str[i + 10] && str[i] == 'X') {
          flag[6] = 1;
          break;
        }
      }
      for (int i = 1; i < 13; i++) {
        if (flag[i] == 1) {
          ans++;
        }
      }
      printf("%d", ans);
      if (flag[1] == 1) printf(" 1x12");
      if (flag[2] == 1) printf(" 2x6");
      if (flag[3] == 1) printf(" 3x4");
      if (flag[4] == 1) printf(" 4x3");
      if (flag[6] == 1) printf(" 6x2");
      if (flag[12] == 1) printf(" 12x1");
      printf("\n");
    }
  }
  return 0;
}

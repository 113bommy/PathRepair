#include <bits/stdc++.h>
using namespace std;
char str[1000010];
char str2[1000010];
int num[15];
int main(void) {
  scanf("%s", str + 1);
  scanf("%s", str2 + 1);
  int len, len2;
  int rl;
  len = strlen(str + 1);
  len2 = strlen(str2 + 1);
  if (len - 1 <= 9)
    rl = len - 1;
  else if (len - 2 <= 99)
    rl = len - 2;
  else if (len - 3 <= 999)
    rl = len - 3;
  else if (len - 4 <= 9999)
    rl = len - 4;
  else if (len - 5 <= 99999)
    rl = len - 5;
  else if (len - 6 <= 999999)
    rl = len - 6;
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= len; i++) {
    num[str[i] - '0']++;
  }
  while (rl) {
    int bit = rl % 10;
    num[bit]--;
    rl /= 10;
  }
  for (int i = 1; i <= len2; i++) {
    num[str2[i] - '0']--;
  }
  int flag2 = 0;
  for (int i = 2; i <= len2; i++) {
    if (str2[i] < str2[i - 1]) {
      flag2 = 1;
      break;
    } else if (str2[i] > str2[i - 1]) {
      flag2 = 0;
      break;
    }
  }
  int flag = 1;
  int ff = 0;
  for (int i = 1; i <= 9; i++) {
    if (num[i] != 0) {
      ff = 1;
      if (str2[1] != '0') {
        if (str2[1] - '0' < i) {
          printf("%s", str2 + 1);
          flag = 0;
        } else if (str2[1] - '0' == i) {
          if (flag2) {
            int flag3 = -1;
            int st = 2;
            num[i]--;
            for (int j = 0; j <= 9; j++) {
              for (int k = 1; k <= num[j]; k++) {
                if (str2[st] - '0' < j) {
                  flag3 = 1;
                  break;
                } else if (str2[st] - '0' > j) {
                  flag3 = 0;
                  break;
                }
                st++;
                if (st > len2) break;
              }
              if (st > len2 || flag3 != -1) break;
            }
            num[i]++;
            if (flag3) {
              printf("%s", str2 + 1);
              flag = 0;
            } else {
              printf("%d", i);
              num[i]--;
            }
          } else {
            printf("%d", i);
            num[i]--;
          }
        } else {
          printf("%d", i);
          num[i]--;
        }
      } else {
        printf("%d", i);
        num[i]--;
      }
      for (int j = 0; j <= 9; j++) {
        if (flag && flag2) {
          if (j >= (str2[1] - '0')) {
            printf("%s", str2 + 1);
            flag = 0;
          }
        }
        for (int k = 1; k <= num[j]; k++) {
          printf("%d", j);
        }
        if (flag && (!flag2)) {
          if (j >= (str2[1] - '0')) {
            printf("%s", str2 + 1);
            flag = 0;
          }
        }
      }
      break;
    }
  }
  if (!ff) {
    printf("%s", str2 + 1);
    for (int i = 1; i <= num[0]; i++) {
      printf("0");
    }
    puts("");
  }
  return 0;
}

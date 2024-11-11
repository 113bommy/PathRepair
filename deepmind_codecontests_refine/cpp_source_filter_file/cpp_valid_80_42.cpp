#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e4 + 6;
int T;
char str[MAXN];
int main() {
  scanf("%d", &T);
  while (T--) {
    int len;
    bool flag;
    flag = 0;
    scanf("%d", &len);
    scanf("%s", str);
    for (int i = 0; i < len; i++) {
      if ((!flag) && str[i] == '0') {
        if (len & 1) {
          if (i + 1 <= (len + 1) / 2) {
            printf("%d %d %d %d\n", i + 1, len, i + 2, len);
            flag = 1;
          } else {
            printf("%d %d %d %d\n", 1, i + 1, 1, i);
            flag = 1;
          }
        } else {
          if (i + 1 <= len / 2) {
            printf("%d %d %d %d\n", i + 1, len, i + 2, len);
            flag = 1;
          } else {
            printf("%d %d %d %d\n", 1, i + 1, 1, i);
            flag = 1;
          }
        }
      }
    }
    if (!flag) {
      printf("1 %d 1 %d\n", len, len - 1);
    }
  }
  return 0;
}

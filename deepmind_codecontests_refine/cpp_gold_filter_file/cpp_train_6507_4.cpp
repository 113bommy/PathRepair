#include <bits/stdc++.h>
using namespace std;
char s[5030][5030];
int leng[10030];
int main() {
  while (gets(s[0]) != NULL) {
    int cnt = 0, maxn = strlen(s[0]);
    leng[cnt] = strlen(s[cnt]);
    while (gets(s[++cnt]) != NULL) {
      if (maxn < strlen(s[cnt])) {
        maxn = strlen(s[cnt]);
      }
      leng[cnt] = strlen(s[cnt]);
    }
    for (int i = 0; i <= maxn + 1; i++) printf("*");
    printf("\n");
    int count = 0, flag = 1, ch = 0;
    while (count < cnt) {
      ch = 0;
      printf("*");
      for (int i = 0; i < (maxn - leng[count]) / 2; i++) printf(" ");
      if ((maxn - leng[count]) % 2 != 0 && leng[count] != maxn && flag == 0) {
        printf(" ");
        ch = 1;
      }
      printf("%s", s[count]);
      if ((maxn - leng[count]) % 2 != 0 && leng[count] != maxn && flag == 1) {
        printf(" ");
        ch = 1;
      }
      for (int i = 0; i < (maxn - leng[count]) / 2; i++) printf(" ");
      printf("*");
      printf("\n");
      count++;
      if (ch) flag = !flag;
    }
    for (int i = 0; i <= maxn + 1; i++) printf("*");
    printf("\n");
  }
}

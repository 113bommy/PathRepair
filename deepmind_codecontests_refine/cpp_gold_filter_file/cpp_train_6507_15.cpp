#include <bits/stdc++.h>
using namespace std;
char s[5030][5030], leng[10030];
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
      int l = strlen(s[count]);
      int t = maxn - l;
      printf("*");
      for (int i = 0; i < t / 2; i++) printf(" ");
      if (t % 2 != 0 && !flag) {
        printf(" ");
      }
      printf("%s", s[count]);
      if (t % 2 != 0) {
        if (flag) printf(" ");
        flag = !flag;
      }
      for (int i = 0; i < (maxn - strlen(s[count])) / 2; i++) printf(" ");
      printf("*");
      printf("\n");
      count++;
    }
    for (int i = 0; i <= maxn + 1; i++) printf("*");
    printf("\n");
  }
}

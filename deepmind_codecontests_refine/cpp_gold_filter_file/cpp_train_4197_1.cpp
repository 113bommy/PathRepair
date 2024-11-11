#include <bits/stdc++.h>
using namespace std;
char a[10005];
int main() {
  while (gets(a)) {
    int i, flag;
    flag = 0;
    for (i = 0; a[i]; ++i) {
      if (a[i] == ' ') {
        flag = 1;
        continue;
      }
      if (a[i] < 'a' || a[i] > 'z') {
        printf("%c", a[i]);
        flag = 1;
        continue;
      }
      if (flag) {
        printf(" %c", a[i]);
        flag = 0;
      } else {
        printf("%c", a[i]);
      }
    }
    printf("\n");
  }
  return 0;
}

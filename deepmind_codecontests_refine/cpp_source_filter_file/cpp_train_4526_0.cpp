#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int main() {
  char str[maxn];
  memset(str, 0, sizeof(str));
  while (scanf("%s", str) != EOF) {
    int flag = 0;
    int prenum = 0;
    int len = strlen(str);
    int num = 0;
    for (int i = 0; i < len; i++)
      if (str[i] == '#') num++;
    int an[maxn], cnt = 0;
    for (int i = 0; i < len; i++) {
      if (str[i] == '(')
        prenum++;
      else if (str[i] == ')')
        prenum--;
      else if (str[i] == '#')
        prenum--;
      if (prenum < 0) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      printf("-1\n");
      continue;
    }
    int R = 0;
    for (int i = len - 1; i >= 0; i--) {
      if (str[i] == ')')
        R++;
      else if (str[i] == '(')
        R--;
      else if (str[i] == '#')
        R++;
      if (R < 0) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      printf("-1\n");
      continue;
    }
    for (int i = 0; i < num - 1; i++) {
      printf("1\n");
    }
    printf("%d\n", prenum + 1);
  }
  return 0;
}

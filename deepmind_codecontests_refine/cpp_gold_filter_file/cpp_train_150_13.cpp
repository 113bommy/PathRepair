#include <bits/stdc++.h>
using namespace std;
char s[1005];
int n;
int main() {
  int i, j;
  while (~scanf("%d", &n)) {
    scanf("%s", s);
    if (n < 5) {
      printf("no\n");
      continue;
    }
    int m = n / 4;
    int flag = 0;
    for (i = 1; i <= m; i++) {
      for (j = 0; j < n; j++) {
        if (s[j] == '*' && s[j + i] == '*' && s[j + 2 * i] == '*' &&
            s[j + 3 * i] == '*' && s[j + 4 * i] == '*') {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (flag)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}

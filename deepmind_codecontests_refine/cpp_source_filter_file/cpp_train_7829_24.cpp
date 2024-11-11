#include <bits/stdc++.h>
using namespace std;
char a[4][4];
int main() {
  int i, j;
  for (i = 0; i < 3; i++) scanf("%s", a[i]);
  int flag = 1;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      if (a[i][j] == 'X') {
        if (a[3 - 1 - i][3 - 1 - j] == '.') {
          flag = 0;
          break;
        }
      }
    }
    if (flag == 0) break;
  }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

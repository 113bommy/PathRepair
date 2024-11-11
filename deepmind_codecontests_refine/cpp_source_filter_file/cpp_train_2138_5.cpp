#include <bits/stdc++.h>
using namespace std;
char str[105];
int main() {
  scanf("%s", str);
  int ans = 0;
  for (int i = 0; i < strlen(str); i++) {
    int i1 = 0, i2 = 0, i3 = 0;
    int a1 = '@', a2 = str[i], a3 = '[', a4 = '`Co', a5 = '{';
    if ((a1 < a2) && (a3 > a2)) i1 = 1;
    if ((a4 < a2) && (a5 > a2)) i2 = 1;
    i3 = tolower(a2) - 'a' + 1;
    ans = ans + i1 * i3 - i2 * i3;
  }
  printf("%d\n", ans);
  return 0;
}

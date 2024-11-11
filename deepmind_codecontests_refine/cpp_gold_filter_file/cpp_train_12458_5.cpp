#include <bits/stdc++.h>
using namespace std;
int s[105];
char a[2][105];
int main() {
  scanf("%s", a[0] + 1);
  scanf("%s", a[1] + 1);
  int l = strlen(a[0] + 1);
  for (int i = 2; i <= l; i++) {
    s[i] = s[i - 1];
    if (i >= 3) {
      if (a[0][i] == '0' && a[0][i - 1] == '0' && a[0][i - 2] == '0' &&
          a[1][i] == '0' && a[1][i - 1] == '0' && a[1][i - 2] == '0') {
        s[i] = max(s[i], s[i - 3] + 2);
      }
    }
    if (a[0][i] == '0' && a[1][i] == '0' && a[0][i - 1] == '0')
      s[i] = max(s[i], s[i - 2] + 1);
    if (a[0][i] == '0' && a[1][i] == '0' && a[1][i - 1] == '0')
      s[i] = max(s[i], s[i - 2] + 1);
    if (a[0][i - 1] == '0' && a[1][i - 1] == '0' && a[0][i] == '0')
      s[i] = max(s[i], s[i - 2] + 1);
    if (a[0][i - 1] == '0' && a[1][i - 1] == '0' && a[1][i] == '0')
      s[i] = max(s[i], s[i - 2] + 1);
  }
  printf("%d\n", s[l]);
  return 0;
}

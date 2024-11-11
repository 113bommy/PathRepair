#include <bits/stdc++.h>
using namespace std;
const int Size = 1024;
const int maxn = 6e3 + 15;
char mp[600][600];
int main() {
  int n, m, i, j, flag1, flag2, flag3, flag4;
  scanf("%d%d", &n, &m);
  for (i = 1; n >= i; i++) scanf("%s", mp[i] + 1);
  int tot = 0, ans = 0;
  int l = 600, r = -1, down = -1, up = 600;
  for (i = 1; n >= i; i++) {
    for (j = 1; m >= j; j++) {
      if (mp[i][j] == '*') {
        if (l > j) {
          l = j;
          flag1 = i;
        }
        if (r < j) {
          r = j;
          flag2 = i;
        }
        if (up > i) {
          up = i;
          flag3 = j;
        }
        if (down < i) {
          down = i;
          flag4 = j;
        }
        tot++;
      }
    }
  }
  if (flag1 != flag2 || flag3 != flag4 || l >= flag3 || r <= flag3 ||
      up >= flag1 || down <= flag1) {
    printf("NO\n");
    return 0;
  } else {
    for (i = l; r >= i; i++) {
      if (mp[flag1][i] == '*')
        ans++;
      else {
        printf("NO\n");
        return 0;
      }
    }
    for (i = up; down >= i; i++) {
      if (mp[flag1][i] == '*')
        ans++;
      else {
        printf("NO\n");
        return 0;
      }
    }
  }
  if (ans - 1 == tot)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char str[5050];
int main() {
  scanf("%s", str + 1);
  int l, r;
  int ans = 0;
  int len = strlen(str + 1);
  for (int i = 1; i <= len; i++) {
    l = 0;
    r = 0;
    for (int j = i; j <= len; j++) {
      if (str[i] == ')') {
        l--;
        r--;
      } else if (str[i] == '(') {
        l++;
        r++;
      } else {
        l--;
        r++;
      }
      if (r < 0) break;
      if (r > 0 && l < 0) l += 2;
      if (l == 0) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}

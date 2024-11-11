#include <bits/stdc++.h>
using namespace std;
int n, l, ls, rs, T;
char s[1000005];
int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &n);
    scanf("%s", s);
    ls = rs = 0;
    l = strlen(s);
    for (int i = 0; i < l; ++i) {
      if (s[i] == '1') {
        ls = i;
        rs = max(rs, n - i);
      }
    }
    if (!rs)
      printf("%d\n", n);
    else
      printf("%d\n", max(ls, rs) * 2);
  }
  return 0;
}

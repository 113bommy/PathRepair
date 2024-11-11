#include <bits/stdc++.h>
char inp[1000005];
int main() {
  while (scanf("%s", inp) != EOF) {
    int len = strlen(inp);
    int cnt = 0, ans = 0, before = 0;
    int i;
    for (i = 0; i < len && inp[i] == 'F'; ++i, ++cnt)
      ;
    for (; i < len; ++i) {
      if (inp[i] == 'F') {
        ans = (ans + 1) > (i - cnt) ? (ans + 1) : (i - cnt);
        ++cnt;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

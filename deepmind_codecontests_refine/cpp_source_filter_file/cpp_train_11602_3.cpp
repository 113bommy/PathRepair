#include <bits/stdc++.h>
using namespace std;
char s[100005], ans[100005];
int main() {
  int n, i, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%s", s);
      if (i == 0) {
        for (j = 0; s[j]; j++) ans[j] = '?';
        ans[j] = 0;
      }
      for (j = 0; s[j]; j++) {
        if (ans[j] == '?') {
          ans[j] = s[j];
          continue;
        }
        if (s[j] == '?') continue;
        if (ans[j] == '-') continue;
        if (ans[j] == s[j]) continue;
        if (ans[j] != s[j]) ans[j] = '-';
      }
    }
    for (i = 0; i < s[i]; i++)
      printf("%c", ans[i] == '-' ? '?' : (ans[i] == '?' ? 'a' : ans[i]));
    printf("\n");
  }
  return 0;
}

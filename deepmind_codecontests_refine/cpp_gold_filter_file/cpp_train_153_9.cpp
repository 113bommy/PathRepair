#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main() {
  int m, ans, f;
  m = 0;
  ans = 0;
  while (fgets(s, sizeof(s), stdin) != NULL) {
    if (s[0] == '+') m++;
    if (s[0] == '-') m--;
    if (strchr(s, ':') != NULL) {
      f = 0;
      for (int i = 0; i < strlen(s) - 1; i++) {
        if (f == 1) ans += m;
        if (s[i] == ':') f = 1;
      }
    }
  }
  printf("%d", ans);
  return 0;
}

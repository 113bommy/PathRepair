#include <bits/stdc++.h>
using namespace std;
char s[300010];
int a, b;
int get(char s[]) {
  int i, j, l = 0, num = 0, len = 0, cnt = 0, tot = 0;
  for (i = 0; s[i]; i++) {
    if (s[i] == 'X') {
      if (l < b)
        ;
      else if (l < a)
        return 0;
      else if (l < 2 * b)
        num++;
      else {
        if (++cnt > 1) return 0;
        len = l - a;
      }
      l = 0;
    } else
      l++;
  }
  if (!cnt)
    return num % 2;
  else {
    for (i = 0; i <= len - i; i++) {
      j = len - i;
      if (i >= b && i < a || j >= b && j < a) continue;
      if (i >= 2 * b || j >= 2 * b) continue;
      if (!(((i >= a) + (j >= a) + num) & 1)) return 1;
    }
  }
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%s", &a, &b, s);
    s[strlen(s) + 1] = '\0';
    s[strlen(s)] = 'X';
    printf("%s\n", get(s) ? "YES" : "NO");
  }
  return 0;
}

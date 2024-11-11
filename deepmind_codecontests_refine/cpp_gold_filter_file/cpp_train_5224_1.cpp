#include <bits/stdc++.h>
int main() {
  int t[10], i, j, p, n;
  scanf("%d", &n);
  char s[100001];
  for (j = 0; j <= n; j++) scanf("%c", &s[j]);
  for (i = 0; i < 10; i++) t[i] = 0;
  for (j = 0; j <= n; j++) {
    if (s[j] == 'L') {
      i = 0;
      while (t[i] != 0 && i < 10) i++;
      t[i] = 1;
    }
    if (s[j] == 'R') {
      i = 0;
      while (t[9 - i] != 0 && i < 10) i++;
      t[9 - i] = 1;
    } else {
      p = s[j] - 48;
      t[p] = 0;
    }
  }
  for (i = 0; i < 10; i++) printf("%d", t[i]);
  return 0;
}

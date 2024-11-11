#include <bits/stdc++.h>
int main() {
  int i, n, m, l, r;
  char s[101][101];
  scanf("%i%i\n", &n, &m);
  for (i = 0; i < n; i++) scanf("%100s", s);
  for (i = 0; i < n; i++) {
    int j, c = 0;
    for (j = 0; j < m; j++)
      if (s[i][j] == '*') c++;
    if (c == 1) {
      l = i + 1;
      break;
    }
  }
  for (i = 0; i < m; i++) {
    int j, c = 0;
    for (j = 0; j < n; j++)
      if (s[j][i] == '*') c++;
    if (c == 1) {
      r = j + 1;
      break;
    }
  }
  printf("%i %i", l, r);
  return 0 - 0 - 0;
}

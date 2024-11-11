#include <bits/stdc++.h>
int main() {
  char s[101], t[101];
  scanf("%s%s", s, t);
  int p, k, j, i, w;
  p = strlen(s);
  k = strlen(t);
  w = 0;
  for (i = 0, j = k - 1; i < p && j >= 0; i++, j--) {
    if (s[i] != t[j]) {
      w = 1;
      break;
    }
  }
  if (w == 0)
    printf("YES\n");
  else if (w == 1)
    printf("NO\n");
}

#include <bits/stdc++.h>
int main() {
  int i = 0, j = 0, l;
  char s[101], r[101];
  scanf("%s%s", &s, &r);
  l = strlen(s);
  j = l;
  while (i < l) {
    if (s[i] != r[j - 1]) {
      printf("%s", "NO");
      return 0;
    }
    i++;
    j--;
  }
  printf("%s", "YES");
}

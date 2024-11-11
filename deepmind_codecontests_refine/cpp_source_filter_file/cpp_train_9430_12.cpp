#include <bits/stdc++.h>
int main() {
  int i, b[3], j;
  char s[3][100];
  for (i = 0; i < 3; i++) gets(s[i]);
  for (i = 0; i < 3; i++) {
    b[i] = 0;
    for (j = 0; j < strlen(s[i]); j++) {
      if (s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' ||
          s[i][j] == 'o' || s[i][j] == 'u')
        b[i]++;
    }
  }
  if (b[0] == 5 && b[1] == 7 && b[2] == 5)
    printf("YES");
  else
    printf("NO");
  return (0);
}

#include <bits/stdc++.h>
using namespace std;
char s[1005][5];
int main() {
  int i, j, n, q;
  q = 0;
  scanf("%d", &n);
  for (i = 0; i <= n; i++) gets(s[i]);
  for (i = 1; i <= n; i++) {
    if (s[i][0] == s[i][1] && s[i][0] == 'O') {
      s[i][0] = s[i][1] = '+';
      q = 1;
      break;
    }
    if (s[i][3] == s[i][4] && s[i][4] == 'O') {
      s[i][3] = s[i][4] = '+';
      q = 1;
      break;
    }
  }
  if (q == 0) {
    printf("NO");
    return 0;
  }
  printf("YES\n");
  for (i = 1; i <= n; i++) {
    for (j = 0; j < 5; j++) printf("%c", s[i][j]);
    printf("\n");
  }
  return 0;
}

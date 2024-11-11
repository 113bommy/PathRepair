#include <bits/stdc++.h>
int main() {
  int i, t1 = 0, t2 = 0;
  char s[101];
  scanf("%s", s);
  for (i = 0; i < strlen(s); i++) {
    if (s[i] == '0') {
      t2 = 0;
      t1++;
      if (t1 == 7) {
        printf("YES");
        break;
      }
    } else {
      t1 = 0;
      t2++;
      if (t2 == 7) {
        printf("YES");
        break;
      }
    }
  }
  if ((t1 != 7) && (t2 != 7)) {
    printf("NO");
  }
  return 0;
}

#include <bits/stdc++.h>
int main() {
  int t, i;
  scanf("%d", &t);
  while (t--) {
    char s[55];
    int a = 0, b = 0, c = 0, l;
    scanf("%s", s);
    l = strlen(s);
    for (i = 0; i < l; i++) {
      if (s[i] == 'A')
        a++;
      else if (s[i] == 'B')
        b++;
      else
        c++;
    }
    if (a + c == b) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}

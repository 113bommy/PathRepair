#include <bits/stdc++.h>
int main() {
  char s[100001];
  scanf("%s", s);
  int cur = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] <= 'a' + cur) {
      s[i] = 'a' + cur;
      cur++;
    }
    if (cur == 26) {
      break;
    }
  }
  if (cur == 26) {
    printf("%s", s);
  } else {
    printf("-1");
  }
  return 0;
}

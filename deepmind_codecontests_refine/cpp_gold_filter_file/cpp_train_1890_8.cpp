#include <bits/stdc++.h>
int main() {
  char s[100005], t[100005];
  scanf("%s", s);
  int i, lens = strlen(s), lent = 0, cnt;
  for (i = 0; i < lens; i++) {
    if (s[i] != 'a')
      t[++lent] = s[i];
    else
      cnt++;
  }
  if (cnt == lens) {
    printf("%s", s);
    return 0;
  }
  if (lent % 2 != 0)
    printf(":(");
  else {
    cnt = 0;
    for (i = 1; i <= lent / 2; i++) {
      if (t[i] == t[lent / 2 + i]) cnt++;
    }
    if (cnt != lent / 2)
      printf(":(");
    else {
      cnt = 0;
      for (i = lens - lent / 2; i < lens; i++) {
        if (s[i] == 'a') break;
      }
      if (i != lens)
        printf(":(");
      else {
        for (i = 0; i < lens - lent / 2; i++) printf("%c", s[i]);
      }
    }
  }
  return 0;
}

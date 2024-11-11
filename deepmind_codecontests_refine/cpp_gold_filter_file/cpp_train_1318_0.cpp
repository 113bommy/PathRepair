#include <bits/stdc++.h>
int main() {
  char s[101];
  int l = 0, p = 0;
  scanf("%s", s);
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == 'o')
      p++;
    else
      l++;
  }
  if (p == 0)
    printf("YES\n");
  else if (l % p)
    printf("NO\n");
  else
    printf("Yes\n");
  return 0;
}

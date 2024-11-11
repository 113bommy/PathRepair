#include <bits/stdc++.h>
int main() {
  char str[105];
  int pearl = 0, link = 0, i, j, n;
  gets(str);
  n = strlen(str);
  for (i = 0; i < n; i++) {
    if (str[i] == '-')
      link++;
    else
      pearl++;
  }
  if (pearl == 0)
    printf("NO\n");
  else if (link % pearl == 0)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

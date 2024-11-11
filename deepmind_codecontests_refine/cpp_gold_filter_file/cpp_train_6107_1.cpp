#include <bits/stdc++.h>
int main(void) {
  int i = 0, c = 0;
  char a[100];
  scanf("%s", &a);
  while (a[i] != '\0') {
    if (a[i] == a[i + 1])
      c++;
    else
      c = 0;
    if (c >= 6) break;
    i++;
  }
  if (c >= 6)
    printf("YES");
  else
    printf("NO");
  return 0;
}

#include <bits/stdc++.h>
int main() {
  char a[101];
  scanf("%s", a);
  int n = strlen(a);
  int i, count1 = 0, count2 = 0;
  for (i = 0; i < n; i++) {
    if (a[i] == 'o')
      count1++;
    else
      count2++;
  }
  if (count1) {
    if (count2 % count1)
      printf("YES");
    else
      printf("NO");
  } else
    printf("YES");
  return 0;
}

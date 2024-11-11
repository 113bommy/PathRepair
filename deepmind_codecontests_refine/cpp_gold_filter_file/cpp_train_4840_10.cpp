#include <bits/stdc++.h>
int main() {
  int a, ara[109][109], i, j, str[109], c = 0;
  scanf("%d", &a);
  for (i = 1; i <= a; i++) {
    str[i] = 0;
  }
  for (i = 1; i <= a; i++) {
    for (j = 1; j <= a; j++) {
      scanf("%d", &ara[i][j]);
      if (ara[i][j] == 1)
        str[i] = 1;
      else if (ara[i][j] == 2)
        str[j] = 1;
      else if (ara[i][j] == 3)
        str[i] = 1, str[j] = 1;
    }
  }
  for (i = 1; i <= a; i++) {
    if (str[i] == 0) c++;
  }
  if (c == 0)
    printf("%d", c);
  else {
    printf("%d\n", c);
    for (i = 1; i <= a; i++) {
      if (str[i] == 0) printf("%d ", i);
    }
  }
  return 0;
}

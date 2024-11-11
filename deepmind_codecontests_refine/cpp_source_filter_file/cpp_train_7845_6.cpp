#include <bits/stdc++.h>
int main() {
  int t, a, i;
  scanf("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf("%d", &a);
    if (360 % (180 - a) == 00)
      printf("YES");
    else
      printf("NO");
  }
}

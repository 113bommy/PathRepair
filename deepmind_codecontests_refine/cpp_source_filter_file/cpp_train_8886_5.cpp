#include <bits/stdc++.h>
int main() {
  int n, c = 0, i, j;
  scanf("%d", &n);
  char a[n];
  scanf("%s", &a);
  if (n == 1)
    printf("0");
  else {
    for (i = 0, j = 1; i <= n; i++, j++) {
      if (a[i] == a[j]) c++;
    }
    printf("%d", c);
  }
}

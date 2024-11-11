#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n < 3)
    printf("-1");
  else {
    printf("2 2 ");
    for (int i = 2; i < n; i++) printf("1 ");
  }
  return 0;
}

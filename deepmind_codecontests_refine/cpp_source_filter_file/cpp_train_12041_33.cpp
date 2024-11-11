#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 4)
    printf("-1\n");
  else {
    printf("1 2\n2 3\n3 4\n");
    for (int i = 5; i <= n; i++) printf("1 %d\n", i);
  }
  for (int i = 2; i <= n; i++) printf("1 %d\n", i);
}

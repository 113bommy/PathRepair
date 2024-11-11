#include <bits/stdc++.h>
int i, t = 0, sum = 0;
int main() {
  for (i = 1; i <= 5; i++) {
    scanf("%d", &t);
    sum += t;
  }
  if (sum % 5 == 0 && sum != 0)
    printf("%d", sum / 5);
  else if (sum == 0)
    printf("-1");
  else
    printf("-1");
  return 0;
}

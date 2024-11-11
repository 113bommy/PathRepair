#include <bits/stdc++.h>
int main() {
  int n, m, odd1, odd2, even1 = 0, even2 = 0, sum = 0, i, a, b;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    if (a % 2 == 0)
      even1++;
    else
      odd1++;
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &b);
    if (a % 2 == 0)
      even2++;
    else
      odd2++;
  }
  if (odd2 <= even1)
    sum = sum + odd2;
  else
    sum = sum + even1;
  if (odd1 <= even2)
    sum = sum + odd1;
  else
    sum = sum + even2;
  printf("%d", sum);
}

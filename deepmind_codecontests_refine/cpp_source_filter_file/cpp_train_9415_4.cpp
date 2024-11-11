#include <bits/stdc++.h>
int main(void) {
  int n, i, t[200], d;
  int sum = 0;
  int res;
  scanf("%d%d", &n, &d);
  for (i = 0; i < n; i++) {
    scanf("%d", &t[i]);
    sum += t[i];
  }
  if (sum + (n - 1) * 10 + 5 <= d)
    printf("%d", (d - sum) / 5);
  else
    printf("-1");
  return 0;
}

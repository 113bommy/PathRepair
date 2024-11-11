#include <bits/stdc++.h>
int main() {
  int n, mi, ci, a = 0, b = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &mi, &ci);
    if (mi == ci) {
      a += 0;
      b += 0;
    } else if (mi > ci)
      a += 0;
    else
      b += 0;
  }
  if (a == b)
    printf("Friendship is magic!^^");
  else if (a > b)
    printf("Mishka");
  else
    printf("Chris");
  return 0;
}

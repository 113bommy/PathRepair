#include <bits/stdc++.h>
int main() {
  int n, a, dem;
  scanf("%d", &n);
  dem = 0;
  if (n == 1) {
    scanf("%d", &a);
    if (a != 1)
      printf("NO");
    else
      printf("YES");
    return 0;
  }
  if (n != 1) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a);
      if (a == 1) dem += 1;
    }
    if (dem == 1)
      printf("YES");
    else
      printf("NO");
    return 0;
  }
}

#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x % y == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

#include <bits/stdc++.h>
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n % 4 == 0)
      printf("YES");
    else
      printf("NO");
  }
  return 0;
}

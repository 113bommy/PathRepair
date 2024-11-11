#include <bits/stdc++.h>
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, s;
    scanf("%d%d", &n, &s);
    if (n == 1)
      printf("%d\n", s);
    else if (n == 2)
      printf("%d\n", s / 2);
    else {
      int ans = n / 2 + 1;
      ans = s / ans;
      printf("%d\n", ans);
    }
  }
  return 0;
}

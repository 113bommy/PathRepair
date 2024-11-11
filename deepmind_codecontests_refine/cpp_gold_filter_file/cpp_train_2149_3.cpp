#include <bits/stdc++.h>
int main() {
  int n, tmp = 1, ans = 0;
  scanf("%d", &n);
  while (n != 0) {
    int t = 2;
    while (t--) {
      ans += tmp;
      n--;
      if (n == 0) break;
    }
    tmp++;
  }
  printf("%d\n", ans);
  return 0;
}

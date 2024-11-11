#include <bits/stdc++.h>
int main() {
  int n, tmp = 1, ans = 1;
  scanf("%d", &n);
  while (n != 1) {
    int t = tmp;
    while (t--) {
      ans += tmp;
      n--;
      if (n == 1) break;
    }
    tmp++;
  }
  printf("%d\n", ans);
  return 0;
}

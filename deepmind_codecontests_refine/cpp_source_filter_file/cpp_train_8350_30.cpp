#include <bits/stdc++.h>
int main() {
  int n, h, m, ans;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &h, &m);
    ans = (23 - h) * 60 + m;
    printf("%d\n", ans);
  }
  return 0;
}

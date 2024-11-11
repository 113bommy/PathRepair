#include <bits/stdc++.h>
int main() {
  int n, ans, prev, crnt, enr = 0;
  scanf("%d", &n);
  scanf("%d", &prev);
  ans = prev;
  n--;
  while (n--) {
    scanf("%d", &crnt);
    enr += (prev - crnt);
    if (enr < 0) {
      ans += (-enr);
      enr = 0;
    }
    prev = crnt;
  }
  printf("%d\n", ans);
  return 0;
}

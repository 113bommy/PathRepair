#include <bits/stdc++.h>
int main() {
  int n, m, ans;
  scanf("%d %d", &n, &m);
  ans = m - 1;
  if (n == m && n == 1)
    ans = 1;
  else if (n - m > m - 1)
    ans = m + 1;
  printf("%d", ans);
  return 0;
}

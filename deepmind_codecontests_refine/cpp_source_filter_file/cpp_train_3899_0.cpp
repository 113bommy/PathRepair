#include <bits/stdc++.h>
int hash[100005];
int main() {
  int n, x, i, y, ans, a, b;
  scanf("%d %d", &n, &x);
  for (i = 0; i < 10000; i++) hash[i] = 0;
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    hash[a] = hash[a] + b;
  }
  ans = 0;
  y = x;
  if (hash[1] >= y) {
    ans = ans + y;
    hash[1] = hash[1] - y;
  } else {
    ans = ans + y - hash[1];
    hash[1] = 0;
  }
  for (i = 2; i <= n + 5; i++) {
    y = x;
    if (hash[i - 1] != 0) {
      if (hash[i - 1] >= y) {
        hash[i - 1] = hash[i - 1] - y;
        ans = ans + y;
        y = 0;
      } else {
        y = y - hash[i - 1];
        ans = ans + hash[i - 1];
        hash[i - 1] = 0;
      }
    }
    if (y != 0 && hash[i] != 0) {
      if (hash[i] >= y) {
        hash[i] = hash[i] - y;
        ans = ans + y;
        y = 0;
      } else {
        ans = ans + hash[i];
        y = y - hash[i];
        hash[i] = 0;
      }
    }
  }
  printf("%d", ans);
  return 0;
}

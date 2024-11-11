#include <bits/stdc++.h>
int n, m, d;
bool dp[50 * 20000];
int main() {
  dp[0] = true;
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    for (int j = 0; j <= m; ++j)
      if (dp[j]) dp[j + t] = true;
    m += t;
  }
  int cur = 0, days = 0;
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = cur + d; i > cur; --i) {
      if (dp[i]) {
        cur = i;
        ++days;
        changed = true;
        break;
      }
    }
  }
  printf("%d %d", cur, days);
  return 0;
}

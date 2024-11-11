#include <bits/stdc++.h>
int main() {
  int n, t, a, sum = 0, time = 0, ans = 0, i, j = 0;
  scanf("%d%d", &n, &t);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    time += (86400 - a);
    if (time <= t) {
      ans++;
      if (time == t) {
        time++;
      }
    }
  }
  printf("%d", ans);
  return 0;
}

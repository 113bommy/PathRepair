#include <bits/stdc++.h>
const int MAXN = 10005;
int x[MAXN], y[MAXN];
int check(int i) {
  if (x[i] == y[i])
    return 0;
  else if (x[i] > y[i])
    return 1;
  else
    return -1;
}
int main() {
  int n;
  scanf("%d", &n);
  int ans = 1, prev = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", x + i, y + i);
    int stats = check(i);
    if (prev == 0) {
      if (stats == 0)
        ans += x[i] - x[i - 1];
      else if (stats == 1)
        ans += y[i] - y[i - 1];
      else
        ans += x[i] - x[i - 1];
    } else if (prev == 1) {
      if (stats == 0)
        ans += x[i] - x[i - 1] + 1;
      else if (stats == 1)
        ans += std::max(y[i] - x[i - 1] + 1, 0);
      else
        ans += x[i] - x[i - 1] + 1;
    } else if (prev == -1) {
      if (stats == 0)
        ans += y[i] - y[i - 1] + 1;
      else if (stats == 1)
        ans += y[i] - y[i - 1] + 1;
      else
        ans += std::max(x[i] - y[i - 1] + 1, 0);
    }
    prev = stats;
  }
  std::cout << ans << std::endl;
  return 0;
}

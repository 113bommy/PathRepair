#include <bits/stdc++.h>
using namespace std;
int n, m, ans, fl;
int main() {
  scanf("%d%d", &m, &n);
  if (n == 1) return printf("%d", -1), 0;
  if (n == 2 && m == 3) return printf("%d", 11), 0;
  if (n == 3 && m == 5) return printf("%d", 11), 0;
  for (;;) {
    if (n >= m + m) return printf("%d", ans + 1), 0;
    if (n >= m) return printf("%d", ans + 3 + 2 * (n == m)), 0;
    if (!fl)
      m -= n - 2, ans = 4, fl = 1;
    else if (n / 2 == 1)
      return printf("%d", -1), 0;
    else
      m -= n / 2 - 1, ans += 2;
  }
}

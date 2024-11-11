#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d%d", &m, &n);
  int ans = 0, flag = 0;
  if (n == 1) return printf("-1"), 0;
  if (n == 2 && m == 3) return printf("11"), 0;
  if (n == 3 && m == 5) return printf("11"), 0;
  while (true) {
    if (n >= m * 2) return printf("%d", ans + 1), 0;
    if (n >= m) return printf("%d", ans + (n == m ? 5 : 3)), 0;
    if (!flag)
      m -= n - 2, ans = 4, flag = 1;
    else {
      if (n / 2 == 1) return printf("-1"), 0;
      m -= n / 2 - 1, ans += 2;
    }
  }
  return 0;
}

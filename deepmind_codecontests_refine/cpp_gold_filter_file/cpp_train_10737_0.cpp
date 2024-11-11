#include <bits/stdc++.h>
int a[100100];
int main() {
  int n, lst = 0, cnt = 0, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == a[i - 1])
      ++cnt;
    else {
      lst = cnt;
      cnt = 1;
    }
    if (cnt <= lst) ans = ans > cnt * 2 ? ans : cnt * 2;
  }
  printf("%d\n", ans);
  return 0;
}

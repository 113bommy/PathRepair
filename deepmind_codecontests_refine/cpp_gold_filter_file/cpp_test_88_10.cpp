#include <bits/stdc++.h>
int t;
int n;
int a[100005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    if (n % 2 == 0) {
      printf("YES\n");
      continue;
    }
    bool ans = 0;
    for (int i = 1; i < n; ++i)
      if (a[i] >= a[i + 1]) {
        ans = 1;
        break;
      }
    if (ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

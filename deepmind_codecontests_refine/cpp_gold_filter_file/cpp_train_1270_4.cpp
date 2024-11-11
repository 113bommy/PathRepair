#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    int n, a[1000000] = {0}, i, b, ans = INT_MAX;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%d", &b);
      if (a[b] > 0) ans = min(ans, i - a[b] + 1);
      a[b] = i;
    }
    if (ans == INT_MAX) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}

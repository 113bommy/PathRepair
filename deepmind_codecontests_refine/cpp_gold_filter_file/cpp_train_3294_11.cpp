#include <bits/stdc++.h>
using namespace std;
int a[205];
int main() {
  int T, n, k;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i < k; i++) {
      int res = a[i + 1] - a[i] + 1;
      res = (res + 1) / 2;
      ans = max(ans, res);
    }
    ans = max(a[1], ans);
    ans = max(n - a[k] + 1, ans);
    printf("%d\n", ans);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool chk[1000005];
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    chk[a[i]] = true;
  }
  int m = 0;
  for (int i = 0; i <= 1000000; i++)
    if (chk[i]) a[m++] = i;
  sort(a, a + m);
  for (int i = 0; i < m; i++) {
    for (int j = a[i];; j += a[i]) {
      int idx = lower_bound(a, a + m, j) - a - 1;
      if (idx >= i && idx < m) ans = max(ans, a[idx] % a[i]);
      if (idx >= m - 1) break;
    }
  }
  printf("%d", ans);
  return 0;
}

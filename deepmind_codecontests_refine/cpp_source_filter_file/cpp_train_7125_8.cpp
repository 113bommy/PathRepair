#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n + 1];
  int inc[n + 1], dec[n + 1];
  memset(inc, 0, sizeof(inc));
  memset(dec, 0, sizeof(dec));
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  inc[1] = dec[n] = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i - 1] < a[i])
      inc[i] = inc[i - 1] + 1;
    else
      inc[i] = 1;
  }
  for (int i = n - 1; i >= 1; --i) {
    if (a[i + 1] > a[i])
      dec[i] = dec[i + 1] + 1;
    else
      dec[i] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, inc[i]);
    if (i < n && a[i] > a[i + 1]) ans = max(ans, dec[i + 1] + 1);
    if (i > 1 && a[i - 1] > a[i]) ans = max(ans, inc[i - 1] + 1);
    if (i <= n - 1 && i >= 2 && a[i + 1] >= a[i - 1] + 2)
      ans = max(ans, inc[i - 1] + dec[i + 1] + 1);
  }
  printf("%d", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], d[N];
long long sum[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int minx = 1 << 30, mid = 1 << 30;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
    if (i < n) minx = min(minx, d[i]);
  }
  for (int i = n; i >= 1; i--) {
    sum[i] = sum[i + 1] + a[i];
  }
  long long ans = 0;
  if (k == 0) {
    for (int i = 1; i <= n; i++) {
      ans = max(ans, sum[i] - d[i]);
    }
  } else if (k == 1) {
    int now = 1 << 30;
    for (int i = 1; i <= n; i++) {
      if (i > 1 && i < n) mid = min(mid, a[i]);
      now = min(now, d[i]);
      if (i > 1) ans = max(ans, sum[i] - d[i]);
      if (i < n) {
        ans = max(ans, sum[1] - sum[n] - d[i]);
        ans = max(ans, sum[1] - now - d[i + 1]);
      }
    }
    ans = max(ans, sum[1] - mid - d[1]);
  } else {
    ans = max(ans, max(sum[1] - minx, sum[n] - d[n]));
  }
  printf("%lld\n", ans);
  return 0;
}

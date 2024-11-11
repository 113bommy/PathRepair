#include <bits/stdc++.h>
using namespace std;
int n, k, a[300005], b[300005], c[300005];
int main() {
  cin >> n >> k;
  double ans = -1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[n + 1] = a[n] + k + 1;
  for (int i = 1; i <= n; i++) b[i] = a[i + 1] - a[i];
  for (int i = 1; i <= n - 2; i++) {
    if (a[i + 1] - a[i] > k) continue;
    int pos = upper_bound(a + 1, a + n + 2, a[i] + k) - a;
    if (pos == i + 2) continue;
    int tmp = a[pos - 1];
    ans = max(ans,
              (double)((double)tmp - a[i + 1]) / (double)((double)tmp - a[i]));
  }
  printf("%.20lf\n", ans);
}

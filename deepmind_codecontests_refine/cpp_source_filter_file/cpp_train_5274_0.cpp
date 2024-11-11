#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
double ans;
int a[N];
int n, u, p;
int main() {
  scanf("%d%d", &n, &u);
  ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    if (i <= n - 2) {
      p = lower_bound(a + i + 2, a + n + 1, a[i] + u) - a;
      if (p > n || a[i] + u != a[p]) p--;
      if (p >= i + 2) {
        ans = max(ans, (a[p] - a[i + 1]) * 1.0 / (a[p] - a[i]));
      }
    }
  }
  if (ans == 0)
    printf("-1\n");
  else
    printf("%.6lf\n", ans);
  return 0;
}

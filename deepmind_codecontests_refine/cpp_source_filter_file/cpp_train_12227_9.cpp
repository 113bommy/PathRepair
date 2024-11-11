#include <bits/stdc++.h>
using namespace std;
int a[501];
double ans;
int main() {
  int n, m, x1, x2, x3;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d %d %d", &x1, &x2, &x3),
        ans = max(ans, (double)(a[x1] + a[x2]) / x3);
  printf("%lf\n", ans);
  return 0;
}

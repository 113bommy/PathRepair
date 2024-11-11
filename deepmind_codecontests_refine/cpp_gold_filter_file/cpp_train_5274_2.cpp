#include <bits/stdc++.h>
using namespace std;
int n, u;
int e[100050];
double Max(double a, double b) { return a > b ? a : b; }
int main() {
  scanf("%d%d", &n, &u);
  for (int i = 0; i < n; i++) scanf("%d", &e[i]);
  double ans = 0.0;
  for (int i = 0; i <= n - 3; i++) {
    int cnt = upper_bound(e, e + n, e[i] + u) - e;
    cnt--;
    if (cnt <= i + 1) continue;
    int p = upper_bound(e, e + n, e[i]) - e;
    ans = Max(ans, 1.0 * (e[cnt] - e[p]) / (e[cnt] - e[i]));
  }
  if (ans == 0)
    printf("-1\n");
  else
    printf("%.10lf\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000;
const int MOD = 1000000009;
int n, m, u, v, a, b, c;
int x[MAXN];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    ans = max(ans, 1.0 * (x[a] + x[b]) / c);
  }
  printf("%.15lf\n", ans);
}

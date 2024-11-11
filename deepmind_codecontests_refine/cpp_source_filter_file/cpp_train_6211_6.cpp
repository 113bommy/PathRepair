#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
int n, p, ans, pre[105000], back[105000];
double x, y, z, a[105000];
std::map<double, int> G, K;
signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf(" (%lf+%lf)/%lf", &x, &y, &z);
    a[i] = (x + y) / z;
    G[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", G[a[i]]);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int node[509];
int main() {
  int n, m, a, b, c;
  double ans = 0.0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &node[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    ans = max(ans, 1.0 * (node[a] + node[b] / c));
  }
  printf("%.10lf\n", ans);
  return 0;
}

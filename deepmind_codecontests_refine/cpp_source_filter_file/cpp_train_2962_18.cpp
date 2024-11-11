#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30) - 1;
const int mod = 1000000007;
const int maxn = 1000005;
int d[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> d[i];
  double ans = -1, tmp;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    tmp = (1.0 * (d[u] + d[v])) / w;
    ans = max(ans, tmp);
  }
  printf("ans=%.15lf\n", ans);
  return 0;
}

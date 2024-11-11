#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u >> 2;
int v[2010];
int a[2010];
int main() {
  int i, j, n, m;
  cin >> n >> m;
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = min(v[x], v[y]);
  }
  int ans = 0;
  for (i = 1; i <= m; i++) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}

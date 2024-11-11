#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, inf = 1e9;
int n, a[N][N], mn, vis[N];
long long d[N];
int main() {
  scanf("%d", &n);
  mn = inf;
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      int x;
      scanf("%d", &x);
      a[i][j] = a[j][i] = x;
      mn = min(mn, x);
    }
  for (int i = 1; i <= n; ++i) {
    d[i] = inf;
    for (int j = 1; j <= n; ++j)
      if (i != j) {
        a[i][j] -= mn;
        d[i] = min(d[i], 2ll * a[i][j]);
      }
  }
  for (int i = 1; i <= n; ++i) {
    int k = 0;
    for (int j = 1; j <= n; ++j)
      if (!vis[j] && (!k || d[k] > d[j])) k = j;
    vis[k] = 1;
    for (int j = 1; j <= n; ++j) d[j] = min(d[j], d[k] + a[k][j]);
  }
  for (int i = 1; i <= n; ++i) printf("%I64d\n", d[i] + 1ll * (n - 1) * mn);
  return 0;
}

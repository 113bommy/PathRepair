#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxm = 100005;
int x[maxm], xr[maxm];
int main() {
  int n, i, j, k, sum, m, cnt = 0, ans, t;
  int x1, x2, y;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &x[i]);
  ans = t = 0;
  sort(x, x + n);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &x1, &x2, &y);
    if (x1 == 1) {
      xr[t++] = x2;
      if (x2 == INF) ans++;
    }
  }
  sort(xr, xr + t);
  ans += n;
  int now = 0;
  cnt = t;
  for (i = 0; i < n; i++) {
    while (now < t && x[i] > xr[now]) --cnt, ++now;
    ans = min(ans, cnt + i);
    if (ans == 0) break;
    i++;
  }
  printf("%d\n", ans);
  return 0;
}

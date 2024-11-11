#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, x, y, z, ans, cnt, a[N], b[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  std::sort(a + 1, a + n + 1);
  a[n + 1] = INF, ans = INF;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (x == 1) b[++cnt] = y;
  }
  std::sort(b + 1, b + 1 + cnt);
  for (int i = 1; i <= n + 1; i++) {
    x = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    ans = std::min(ans, i + cnt - x);
  }
  printf("%d\n", ans);
  return 0;
}

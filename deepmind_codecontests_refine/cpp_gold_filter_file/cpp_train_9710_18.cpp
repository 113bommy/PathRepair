#include <bits/stdc++.h>
using namespace std;
struct ned {
  int x, y;
  bool operator<(const ned &a) const { return x == a.x ? (y < a.y) : x < a.x; }
};
ned ned[4000010];
int n, m, cnt;
int a[2010], b[2010], c[2010], d[2010];
int sma[4000010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &c[i], &d[i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] <= c[j] && b[i] <= d[j]) {
        ned[++cnt] = {c[j] - a[i] + 1, d[j] - b[i] + 1};
      }
    }
  }
  sort(ned + 1, ned + cnt + 1);
  for (int i = cnt; i >= 1; --i) sma[i] = max(sma[i + 1], ned[i].y);
  int ans = 0x3f3f3f3f;
  for (int i = 0; i <= cnt; ++i) ans = min(ans, ned[i].x + sma[i + 1]);
  ans = ans * (cnt > 0);
  cout << ans;
  return 0;
}

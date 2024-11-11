#include <bits/stdc++.h>
using namespace std;
struct Info {
  int x, y;
} a[110];
int dp[110 * 2], b[110 * 2], n, ans;
bool c1(const Info &a, const Info &b) { return a.x < b.x; }
void tr(int x) {
  int be = 1;
  while (be <= n && a[be].x <= b[x]) be++;
  for (int i = be; i <= n; i++) {
    int ma = a[i].x, qu = min(a[i].y, a[i].x - b[x]);
    for (int j = be; j <= n; j++) {
      if (j != i && a[j].x + a[j].y > ma && a[j].x <= ma) {
        qu += a[j].x + a[j].y - ma;
        ma = a[j].x + a[j].y;
      }
    }
    for (int j = be; j <= n + n; j++)
      if (b[j] == ma) dp[j] = max(dp[j], dp[x] + qu);
    ma = a[i].x + a[i].y, qu = a[i].y;
    for (int j = be; j <= n; j++) {
      if (j != i && a[j].x + a[j].y > ma && a[j].x <= ma) {
        qu += a[j].x + a[j].y - ma;
        ma = a[j].x + a[j].y;
      }
    }
    for (int j = be; j <= n + n; j++)
      if (b[j] == ma) dp[j] = max(dp[j], dp[x] + qu);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  for (int i = 1; i <= n; i++) {
    b[i] = a[i].x;
    b[i + n] = a[i].y + a[i].x;
  }
  b[0] = -2e8;
  sort(b + 1, b + n + n + 1);
  sort(a + 1, a + n + 1, c1);
  for (int i = 0; i <= n + n; i++) {
    tr(i);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}

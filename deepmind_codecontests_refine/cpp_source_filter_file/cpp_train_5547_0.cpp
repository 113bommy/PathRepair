#include <bits/stdc++.h>
using namespace std;
int dp[100005], ans[100005];
struct node {
  int x, y, t;
} a[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int r, n;
  cin >> r >> n;
  a[0].x = a[0].y = 1;
  a[0].t = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].t >> a[i].x >> a[i].y;
    dp[i] = -2;
    for (int j = i - 1; j >= 0; j--) {
      if (a[i].t - a[j].t >= 2 * (r - 1)) {
        dp[i] = max(dp[i], ans[j] + 1);
        break;
      }
      if (a[i].t - a[j].t >= abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans[i] = max(dp[i], ans[i - 1]);
  }
  cout << ans[n] << endl;
  return 0;
}

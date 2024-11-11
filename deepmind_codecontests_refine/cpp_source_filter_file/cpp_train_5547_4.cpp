#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1 << 62;
const long long MOD = 1e9 + 7;
const int iINF = 1 << 30;
const double PI = 3.14159265359;
struct pt {
  int x, y, t;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int r, n;
  cin >> r >> n;
  vector<pt> pts(n + 1);
  pts[0] = {0, 1, 1};
  for (int i = 1; i <= n; i++) {
    cin >> pts[i].t >> pts[i].x >> pts[i].y;
  }
  vector<int> dp(n + 2, 1);
  dp[n + 1] = 0;
  vector<int> prefmx(n + 2, 0);
  for (int i = n; i >= 0; i--) {
    for (int j = i + 1; j <= min(i + 2 * r, n); j++) {
      if (pts[i].t + abs(pts[j].x - pts[i].x) + abs(pts[j].y - pts[i].y) <=
          pts[j].t)
        dp[i] = max(dp[i], 1 + dp[j]);
    }
    dp[i] = max(dp[i], 1 + prefmx[min(n + 1, i + 2 * r + 1)]);
    prefmx[i] = max(dp[i], prefmx[i + 1]);
  }
  cout << dp[0] - 1 << "\n";
  return 0;
}

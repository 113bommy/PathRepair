#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct point {
  long long x, y;
};
point a[505], b[505];
long long cross(point a, point b) { return a.x * b.y - a.y * b.x; }
point operator-(point a, point b) { return {a.x - b.x, a.y - b.y}; }
long long dp[505][505];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  if (fopen("VietCT.INP", "r")) {
    freopen("VietCT.INP", "r", stdin);
    freopen("VietCT.OUT", "w", stdout);
  }
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  for (int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[j].x > a[i].x) {
        for (int k = 1; k <= m; k++) {
          if (b[k].x >= a[i].x && b[k].x < a[j].x &&
              (cross(a[j] - a[i], b[k] - a[i]) > 0))
            dp[i][j]++;
        }
        dp[j][i] = -dp[i][j];
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = j + 1; k <= n; k++) {
        if ((dp[i][j] + dp[j][k] + dp[k][i]) == 0) {
          ans++;
        }
      }
    }
  }
  cout << ans;
}

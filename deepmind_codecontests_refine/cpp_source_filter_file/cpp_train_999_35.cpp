#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
bool mini(A &x, const B &y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}
template <typename A, typename B>
bool maxi(A &x, const B &y) {
  if (y > x) {
    x = y;
    return true;
  }
  return false;
}
class fastio {
 public:
  fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} __fastio;
long long a[300500];
long long dp[300500][50];
long long was[300500][25];
int main() {
  long long ans = 0;
  int n;
  cin >> n;
  for (auto i = 0; i < n; i++) cin >> a[i];
  long long bal = 0;
  for (auto i = 0; i < n + 1; i++) {
    for (auto j = 0; j < 25; j++) {
      dp[i][j] = 1e18;
    }
  }
  dp[0][0] = 0;
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < 48; j++) {
      if (j > a[i] / 100) {
        dp[i + 1][j - a[i] / 100] = min(dp[i + 1][j - a[i] / 100], dp[i][j]);
      } else {
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + a[i] - j * 100);
      }
      dp[i + 1][j + a[i] / 1000] =
          min(dp[i + 1][j + a[i] / 1000], dp[i][j] + a[i]);
    }
  }
  ans = 1e18;
  for (auto j = 0; j < 50; j++) {
    ans = min(dp[n][j], ans);
  }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, r1, r2, r3, d, a[N];
long long dp[N][2];
long long one_shot(int k) { return 1LL * k * r1 + r3; }
long long two_shot(int k) {
  return min((k + 1LL) * r1, 1LL * r2) + min({r1, r2, r3});
}
void read_input() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
}
void solve() {
  memset(dp, 63, sizeof dp);
  dp[1][0] = one_shot(a[dp[0][0] = dp[0][1] = 0]);
  for (int i = 1; i < n; i++) {
    dp[i + 1][1] = min(dp[i - 1][0], dp[i - 1][1]) + two_shot(a[i - 1]) +
                   two_shot(a[i]) + (i > 1 ? 4LL : 3LL) * d;
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + two_shot(a[i]) + 3LL * d);
    dp[i + 1][0] = min(dp[i][0], dp[i][1]) + one_shot(a[i]) + d;
  }
}
void write_output() {
  long long ans = min(dp[n][0], dp[n][1]);
  long long cur = one_shot(a[n - 1]) + d;
  for (int i = n - 2; ~i; i--) {
    cur += two_shot(a[i]) + 2LL * d;
    ans = min(ans, min(dp[i][0], dp[i][1]) + cur);
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve(), write_output();
  return 0;
}

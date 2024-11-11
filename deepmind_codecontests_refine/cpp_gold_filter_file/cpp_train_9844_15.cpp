#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3e3 + 5;
int a[maxn], b[maxn];
long long dp[maxn][maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  memset(dp, 0x3f, sizeof(dp));
  dp[0][1] = 0;
  for (int i = 1; i < n + 1; i++) {
    long long mi = 1e18;
    for (int j = 1; j < n + 1; j++) {
      mi = min(mi, dp[i - 1][j]);
      dp[i][j] = mi + abs(b[j] - a[i]);
    }
  }
  long long ans = 1e18;
  for (int i = 1; i < n + 1; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c = 0;
  int t;
  if (!c) {
    t = 1;
  } else {
    cin >> t;
  }
  while (t--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n;
int a[MAXN];
int dp[MAXN];
void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[0] = -1e9;
}
void solve() {
  for (int i = 1; i <= n; i++) {
    int j = upper_bound(a, a + n + 1, a[i] - 90) - a;
    int k = upper_bound(a, a + n + 1, a[i] - 1440) - a;
    dp[i] = min(dp[i - 1] + 20, min(dp[j - 1] + 50, dp[k - 1] + 120));
    cout << dp[i] - dp[i - 1] << endl;
  }
}
int main() {
  input();
  solve();
  return 0;
}

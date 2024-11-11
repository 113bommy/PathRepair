#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int ff = 0x3f3f3f3f;
const double esp = 1e-7;
int n;
int a[maxn];
int dp[maxn];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) dp[i] = min(a[i], dp[i - 1] + 1);
  int ans = 1;
  for (int i = n; i >= 1; i--) {
    dp[i] = min(dp[i], dp[i + 1] + 1);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}

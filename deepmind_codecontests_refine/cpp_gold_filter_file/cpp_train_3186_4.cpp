#include <bits/stdc++.h>
using namespace std;
int dp[5001];
int a[50001];
int l[5001];
int r[50001];
int used[5001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (l[a[i]] == 0) l[a[i]] = i;
    r[a[i]] = i;
  }
  int x = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (r[a[i]] != i) continue;
    cnt = l[a[i]];
    x = 0;
    memset(used, 0, sizeof(used));
    for (int j = i; j; j--) {
      if (r[a[j]] > i) break;
      cnt = min(cnt, l[a[j]]);
      if (!used[a[j]]) {
        x ^= a[j];
        used[a[j]] = 1;
      }
      if (cnt == j) {
        dp[i] = max(dp[i], x + dp[j - 1]);
      }
    }
  }
  cout << dp[n];
  return 0;
}

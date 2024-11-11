#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const long long inf = 1e18;
int n;
int a[N];
int dp[N];
int dpn[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i <= 30; i++) {
    dp[i] = int(1e9);
    dpn[i] = int(1e9);
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 30; j++) {
      dpn[j + a[i] / 1000] = min(dpn[j + a[i] / 1000], dp[j] + a[i]);
      int jj = min(a[i] / 100, j);
      dpn[j - jj] = min(dpn[j - jj], dp[j] + a[i] - jj * 100);
    }
    for (int j = 0; j <= 30; j++) {
      dp[j] = dpn[j];
      dpn[j] = int(1e9);
    }
  }
  int ans = int(1e9);
  for (int i = 0; i <= 30; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans;
  return 0;
}

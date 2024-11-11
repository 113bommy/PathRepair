#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int dp[N], bst[N];
int main() {
  int n;
  cin >> n;
  int bsum = 0, asum = 0;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], bsum += b[i], asum += a[i];
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (b[j] < b[i]) {
        swap(b[i], b[j]);
        swap(a[i], a[j]);
      } else if (b[j] == b[i]) {
        if (a[j] > a[i]) {
          swap(b[i], b[j]);
          swap(a[i], a[j]);
        }
      }
    }
  }
  memset(dp, 0x3f3f, sizeof(dp));
  dp[0] = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = asum; j >= a[i]; j--) {
      dp[j] = min(dp[j - a[i]] + b[i], dp[j]);
    }
  }
  for (int i = asum; i >= 0; i++) {
    if ((asum - i) >= dp[i]) {
      ans = asum - i;
      cout << ans << endl;
      return 0;
    }
  }
  return 0;
}

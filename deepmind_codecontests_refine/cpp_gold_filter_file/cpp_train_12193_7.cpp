#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int INF = 1e9;
int n, k;
int a[MAXN], b[MAXN];
int dp[MAXN][2];
int get(int pa, int pb, int a, int b) {
  int ans = INF;
  if (pa <= k) {
    int t = pa + a;
    int cnt = (t + k - 1) / k - 1;
    if (b == cnt)
      ans = min(ans, t - cnt * k);
    else if (b > cnt && b <= a * (long long)(k))
      ans = min(ans, 1);
  }
  if (pb <= k) {
    int cnt = (a + k - 1) / k - 1;
    if (b == cnt)
      ans = min(ans, a - cnt * k);
    else if (b > cnt && b <= (a - 1) * (long long)(k) + (k - pb))
      ans = min(ans, 1);
  }
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < 2; j++) dp[i][j] = INF;
  dp[0][0] = dp[0][1] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = get(dp[i][0], dp[i][1], a[i], b[i]);
    dp[i + 1][1] = get(dp[i][1], dp[i][0], b[i], a[i]);
  }
  cout << (dp[n][0] <= k || dp[n][1] <= k ? "YES" : "NO");
  return 0;
}

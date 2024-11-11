#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, k, a[1003], dp[1003][1003], l[1003], res, pre[1003][1003];
int cal(int val) {
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 0;
  l[0] = 0;
  for (int i = 1; i <= n; i++) {
    l[i] = l[i - 1];
    if (a[i] - a[l[i] + 1] >= val) l[i]++;
  }
  dp[0][0] = 1;
  for (int i = 0; i < k; i++) {
    pre[i][0] = dp[i][0];
    for (int j = 1; j <= n; j++) {
      pre[i][j] = (pre[i][j - 1] + dp[i][j]) % mod;
      dp[i + 1][j] = pre[i][l[j]];
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) res = (res + dp[k][i]) % mod;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i * (k - 1) <= 100010; i++) res = (res + cal(i)) % mod;
  cout << res;
}

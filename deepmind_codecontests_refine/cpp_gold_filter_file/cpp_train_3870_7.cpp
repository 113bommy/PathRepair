#include <bits/stdc++.h>
using namespace std;
long long maxi = LLONG_MIN;
long long mini = LLONG_MAX;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long t, i, j, k, n, temp, flag, ans, m;
long long dp[105][105];
int main() {
  fast();
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < j; k++) dp[i][j] += dp[i - 1][k];
      for (int k = 1; k < j; k++) {
        if (s[k - 1] == s[j - 1]) {
          dp[i][j] -= dp[i][k];
        }
      }
    }
  }
  long long co = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      co += dp[i][j];
      ans += dp[i][j] * (n - i);
      if (co > k) {
        ans -= (co - k) * (n - i);
        co = k;
        break;
      }
    }
    if (co == k) break;
  }
  if (co < k) {
    ans += n;
    co++;
  }
  if (co < k) ans = -1;
  cout << ans;
  return 0;
}

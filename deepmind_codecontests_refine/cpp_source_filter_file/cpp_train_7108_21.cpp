#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void chmax(int &a, int b) {
  if (a < b) a = b;
}
int a[5050], pre[5050];
int dp[5050], sdp[5050];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) pre[i] = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] >= 2 * a[i]) chmax(pre[j], i);
    }
  }
  for (int i = 0; i <= n; i++) sdp[i] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (pre[j] >= i - 1)
        dp[j + 1] = dp[j + 1] * (pre[j] - i + 2) % mod;
      else
        dp[j + 1] = 0;
      (dp[j + 1] += sdp[pre[j] + 2]) %= mod;
    }
    sdp[0] = 0;
    for (int j = 0; j <= n; j++) {
      sdp[j + 1] = (sdp[j] + dp[j]) % mod;
    }
  }
  cout << dp[n] << "\n";
}

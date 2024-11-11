#include <bits/stdc++.h>
using namespace std;
int n;
int a[5001];
bool b[5001] = {false};
int c[5001] = {0};
int dp[5001] = {0};
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    dp[i] = (i == 0) ? 0 : dp[i - 1];
    int curXor = 0, curCount = 0;
    for (int j = i; j >= 0; j--) {
      if (!b[a[j]]) {
        curXor ^= a[j];
        curCount += c[a[j]];
        b[a[j]] = true;
      }
      if (i - j + 1 == curCount) {
        int tail = (j == 0) ? 0 : dp[j - 1];
        dp[i] = max(dp[i], curXor + tail);
      }
    }
    for (int k = 0; k <= i; k++) {
      b[k] = false;
    }
  }
  cout << dp[n - 1];
  return 0;
}

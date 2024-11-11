#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
int n, K, p, a[N];
int dp[55][105], tp[55][105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> K >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= p;
  }
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j < p; j++) {
      dp[i][j] = tp[i][j] = INT_MIN;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k <= K; k++) {
      for (int prev = 0; prev < p; prev++) {
        int nVal = (prev + a[i]) % p;
        tp[k][nVal] = max(tp[k][nVal], dp[k][prev]);
        tp[k + 1][0] = max(tp[k + 1][0], dp[k][prev] + nVal);
      }
    }
    for (int k = 0; k <= K; k++) {
      for (int prev = 0; prev < p; prev++) {
        dp[k][prev] = tp[k][prev];
        tp[k][prev] = INT_MIN;
      }
    }
  }
  cout << dp[K][0] << endl;
  return 0;
}

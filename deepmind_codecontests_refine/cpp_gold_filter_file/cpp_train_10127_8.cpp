#include <bits/stdc++.h>
using namespace std;
const int M = 100;
const int N = 3e5 + 5;
const int mod = 1e9 + 7;
const long long lf = 1e18;
bool cmp(int a, int b) { return a > b; }
long long dp[N][2];
int a[N] = {0}, m = 0, x;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < 1000; i++)
      ;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < 1000; i++)
      ;
    for (int i = 0; i <= n; i++) {
      dp[i][0] = dp[i][1] = -lf;
    }
    for (int i = 0; i < 1000; i++)
      ;
    dp[0][0] = 0;
    long long ans = -lf;
    for (int i = 0; i <= n; i++) {
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - a[i]);
    }
    for (int i = 0; i < 1000; i++)
      ;
    cout << max(dp[n][0], dp[n][1]) << endl;
  }
  return 0;
}

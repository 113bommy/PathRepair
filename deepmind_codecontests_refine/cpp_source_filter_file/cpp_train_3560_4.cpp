#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, c;
  cin >> n >> c;
  int *a, *b;
  a = new int[n - 1];
  b = new int[n - 1];
  pair<int, bool> *ans = new pair<int, bool>[n];
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cin >> b[i];
  int dp[n][2];
  for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = INT_MAX;
  dp[0][0] = 0;
  dp[0][1] = c;
  cout << 0 << " ";
  for (int i = 0; i < n - 1; i++) {
    dp[i + 1][0] = min(dp[i][0] + a[i], dp[i][1] + b[i]);
    dp[i + 1][1] = min(dp[i][1] + b[i], dp[i][0] + c + b[i]);
    cout << min(dp[i + 1][0], dp[i + 1][1]) << " ";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
int dp[N][3], a[N], b[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) cin >> b[i];
  dp[0][1] = 2;
  for (int i = 1; i < n; i++) {
    dp[i][0] = min(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
    dp[i][1] = min(dp[i - 1][1] + b[i], dp[i - 1][0] + b[i] + m);
    dp[i][2] = min(dp[i][0], dp[i][1]);
  }
  cout << "0";
  for (int i = 1; i < n; i++) cout << " " << dp[i][2];
  cout << endl;
  return 0;
}

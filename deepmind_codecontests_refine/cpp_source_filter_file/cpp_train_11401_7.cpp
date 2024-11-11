#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int N;
  string S;
  cin >> N;
  cin >> S;
  int dp[2][3];
  int odp[2][3];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; i++) {
    memcpy(odp, dp, sizeof dp);
    int Q = (S[i] == '1');
    cerr << Q << " ";
    dp[Q][0] = odp[!Q][0] + 1;
    dp[!Q][1] = odp[Q][1] + 1;
    dp[Q][2] = odp[!Q][2] + 1;
    dp[Q][1] = max(odp[Q][0] + 1, odp[Q][1]);
    dp[Q][2] = max(odp[Q][1] + 1, odp[Q][2]);
  }
  cerr << endl;
  int ans = 0;
  ans = max(ans, dp[0][0]);
  ans = max(ans, dp[0][1]);
  ans = max(ans, dp[0][2]);
  ans = max(ans, dp[1][0]);
  ans = max(ans, dp[1][1]);
  ans = max(ans, dp[1][2]);
  cout << ans << endl;
}

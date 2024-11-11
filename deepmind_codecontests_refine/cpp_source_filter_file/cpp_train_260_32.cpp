#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int mm[N + 1], n, m;
int dp[N + 1][20][2];
int dpp[N + 1][20];
inline int solve() {
  for (int i = int(0); i < int(m); i++) dpp[mm[i]][0]++;
  for (int i = int(1); i < int(n + 1); i++) {
    for (int j = int(0); j < int(1 << n); j++) {
      for (int e = int(0); e < int(n); e++) {
        dp[j][e][i % 2] =
            dpp[j ^ (1 << e)][i - 1] - dp[j ^ (1 << e)][e][(i + 1) % 2];
        dpp[j][i] += dp[j][e][i % 2];
      }
      dpp[j][i] /= i;
    }
  }
  int ans = INT_MAX;
  for (int i = int(1); i < int(1 << n); i++) {
    int sum = 0;
    for (int j = int(1); j < int(n + 1); j++) sum += min(j, n - j) * dpp[i][j];
    ans = min(ans, sum);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int ag = 0;
  for (int i = int(0); i < int(n); i++) {
    int cc = 0;
    for (int j = int(0); j < int(m); j++) {
      char c;
      cin >> c;
      if (c == '1') mm[j] += (1 << i), cc++;
    }
    ag += min(cc, n - cc);
  }
  int ans = min(solve(), ag);
  cout << ans << endl;
  return 0;
}

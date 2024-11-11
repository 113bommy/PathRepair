#include <bits/stdc++.h>
using namespace std;
int dp[1000010][3][3];
int conts[1000010];
int n, m, x;
int rsolve(int pos, int _2_pos, int _3_pos) {
  if (pos == 0) return 0;
  if (dp[pos][_2_pos][_3_pos] == -1) {
    int ans = 0;
    int qnts_sobram = conts[pos] - (_2_pos + _3_pos);
    for (int _3_pos_ant = 0; _3_pos_ant < 3; ++_3_pos_ant) {
      qnts_sobram = conts[pos - 1] - (_3_pos_ant + _2_pos + _3_pos);
      if (qnts_sobram >= 0)
        ans = max(ans, rsolve(pos - 1, _3_pos, _3_pos_ant) + _2_pos +
                           qnts_sobram / 3);
    }
    dp[pos][_2_pos][_3_pos] = ans;
  }
  return dp[pos][_2_pos][_3_pos];
}
int main() {
  for (int i = 0; i < 1000010; ++i)
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k) dp[i][j][k] = -1;
  ;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    conts[x]++;
  }
  int ans = 0;
  ans = max(rsolve(m + 1, 0, 0), ans);
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> mark[4];
string sins[4];
int cost[5];
int sta[1010];
int dp[1010][0xffff];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 4; i++) cin >> cost[i];
  for (int i = 0; i < 4; i++) cin >> sins[i];
  for (int j = 0; j < n; j++) {
    sta[j] = 0;
    for (int i = 0; i < 4; i++) {
      sta[j] |= (sins[i][j] == '*') ? (1 << i) : 0;
    }
  }
  int S = 0;
  for (int i = 0; i < 4; i++) {
    S |= sta[i] << (i * 4);
    sta[n + i] = 0;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 3; j >= i; j--) {
      int t = 0xffff;
      for (int k = 0; k <= i; k++) {
        for (int y = j; y >= j - i; y--) t ^= 1 << (4 * k + y);
      }
      mark[i].push_back(t);
    }
  }
  memset(dp, 0x7f, sizeof(dp));
  dp[0][S] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0xffff; j >= 0; j--) {
      if (dp[i][j] == 0x7f7f7f7f) continue;
      if ((j & 0xf) == 0) {
        int S = ((j & 0xffff) >> 4) | (0xf000 & (sta[i + 4] << 12));
        dp[i + 1][S] = min(dp[i + 1][S], dp[i][j]);
      }
      for (int k = 0; k < 4 && k + i < n; k++) {
        vector<int>::iterator y;
        for (y = mark[k].begin(); y != mark[k].end(); y++) {
          dp[i][j & (*y)] = min(dp[i][j & (*y)], dp[i][j] + cost[k]);
        }
      }
    }
  }
  cout << dp[n][0] << endl;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
const int MOD = 1e9 + 7;
int n;
vector<long long> dp(10, 0);
void solve() {
  for (int i = 1; i <= (int)(9); i++) dp[i] = -1;
  cin >> n;
  for (int _ = 0; _ < (int)(n); _++) {
    vector<long long> tmp = dp;
    int k;
    cin >> k;
    vector<long long> card[4];
    for (int __ = 0; __ < (int)(k); __++) {
      int co;
      long long da;
      cin >> co >> da;
      card[co].push_back(da);
    }
    int l[4];
    for (int i = 1; i <= (int)(3); i++) {
      l[i] = ((int)(card[i]).size());
      if (l[i] != 0)
        sort((card[i]).begin(), (card[i]).end(), greater<long long>());
    }
    if (l[1] > 0)
      for (int i = 0; i < (int)(10); i++)
        if (dp[i] != -1) {
          if (i <= 8)
            tmp[i + 1] = max(tmp[i + 1], dp[i] + card[1][0]);
          else
            tmp[(i + 1) % 10] = max(tmp[(i + 1) % 10], dp[i] + card[1][0] * 2);
        }
    if (l[1] > 1)
      for (int i = 0; i < (int)(10); i++)
        if (dp[i] != -1) {
          if (i <= 7)
            tmp[i + 2] = max(tmp[i + 2], dp[i] + card[1][0] + card[1][1]);
          else
            tmp[(i + 2) % 10] =
                max(tmp[(i + 2) % 10], dp[i] + card[1][0] * 2 + card[1][1]);
        }
    if (l[2] > 0)
      for (int i = 0; i < (int)(10); i++)
        if (dp[i] != -1) {
          if (i <= 8)
            tmp[i + 1] = max(tmp[i + 1], dp[i] + card[2][0]);
          else
            tmp[(i + 1) % 10] = max(tmp[(i + 1) % 10], dp[i] + card[2][0] * 2);
        }
    if (l[1] > 2)
      for (int i = 0; i < (int)(10); i++)
        if (dp[i] != -1) {
          if (i <= 6)
            tmp[i + 3] =
                max(tmp[i + 3], dp[i] + card[1][0] + card[1][1] + card[1][2]);
          else
            tmp[(i + 3) % 10] =
                max(tmp[(i + 2) % 10],
                    dp[i] + card[1][0] * 2 + card[1][1] + card[1][2]);
        }
    if (l[1] > 0 && l[2] > 0)
      for (int i = 0; i < (int)(10); i++)
        if (dp[i] != -1) {
          if (i <= 7)
            tmp[i + 2] = max(tmp[i + 2], dp[i] + card[1][0] + card[2][0]);
          else
            tmp[(i + 2) % 10] =
                max(tmp[(i + 2) % 10], dp[i] + card[1][0] + card[2][0] +
                                           max(card[1][0], card[2][0]));
        }
    if (l[3] > 0)
      for (int i = 0; i < (int)(10); i++)
        if (dp[i] != -1) {
          if (i <= 8)
            tmp[i + 1] = max(tmp[i + 1], dp[i] + card[3][0]);
          else
            tmp[(i + 1) % 10] = max(tmp[(i + 1) % 10], dp[i] + card[3][0] * 2);
        }
    dp = tmp;
  }
  long long ans = 0;
  for (int i = 0; i < (int)(10); i++) ans = max(ans, dp[i]);
  cout << ans << endl;
}
int main() { solve(); }

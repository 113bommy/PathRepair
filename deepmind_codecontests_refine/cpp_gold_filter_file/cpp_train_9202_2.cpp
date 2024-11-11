#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, maxmsk = 10, mod = 1e9 + 7;
int n, x, y, col[maxn], dp[maxn][maxmsk];
vector<pair<int, int>> vec;
bool check(int i, int j) { return (i >= 0 && i < 3 && j >= 0 && j < n); }
void fillDp() {
  memset(dp, 0, sizeof(dp));
  for (int msk = 0; msk < 8; msk++)
    if ((msk | col[0]) == msk) {
      int tmp = msk ^ col[0];
      if (tmp == 0 || tmp == 3 || tmp == 6) dp[0][msk] = 1;
    }
  for (int i = 1; i < n; i++)
    for (int msk = 0; msk < 8; msk++) {
      if ((msk | col[i]) != msk) continue;
      int msk2 = msk ^ col[i];
      dp[i][msk] = (dp[i][msk] + dp[i - 1][msk2 ^ 7]) % mod;
      if (msk2 == 7)
        dp[i][msk] = (dp[i][msk] + (dp[i - 1][6] + dp[i - 1][3]) % mod) % mod;
      else if (msk2 == 6 || msk2 == 3)
        dp[i][msk] = (dp[i][msk] + dp[i - 1][7]) % mod;
    }
  return;
}
int solve() {
  int ans = 0;
  for (int msk = 1; msk < (1 << vec.size()); msk++) {
    for (int tmp = msk; tmp; tmp -= tmp & -tmp) {
      int xx = x, yy = y;
      for (int i = 0; i < 2; i++) {
        xx += vec[__builtin_ctz(tmp & -tmp)].first;
        yy += vec[__builtin_ctz(tmp & -tmp)].second;
        col[yy] |= (1 << xx);
      }
    }
    fillDp();
    if (__builtin_popcount(msk) & 1)
      ans = (ans + dp[n - 1][7]) % mod;
    else
      ans = (ans - dp[n - 1][7] + mod) % mod;
    for (int tmp = msk; tmp; tmp -= tmp & -tmp) {
      int xx = x, yy = y;
      for (int i = 0; i < 2; i++) {
        xx += vec[__builtin_ctz(tmp & -tmp)].first;
        yy += vec[__builtin_ctz(tmp & -tmp)].second;
        col[yy] ^= 1 << xx;
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 'O') x = i, y = j;
      if (c != '.') col[j] ^= 1 << i;
    }
  if (check(x + 2, y) && !(col[y] >> (x + 1) & 1) && !(col[y] >> (x + 2) & 1))
    vec.push_back({1, 0});
  if (check(x - 2, y) && !(col[y] >> (x - 1) & 1) && !(col[y] >> (x - 2) & 1))
    vec.push_back({-1, 0});
  if (check(x, y + 2) && !(col[y + 1] >> x & 1) && !(col[y + 2] >> x & 1))
    vec.push_back({0, 1});
  if (check(x, y - 2) && !(col[y - 1] >> x & 1) && !(col[y - 2] >> x & 1))
    vec.push_back({0, -1});
  cout << solve() << "\n";
  return 0;
}

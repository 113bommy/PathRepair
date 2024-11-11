#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int n;
string ss;
char dp[N][N];
vector<int> g[N];
int used[N][N];
int main() {
  cin >> ss;
  int n = (int)ss.size();
  if (n == 1) {
    cout << ss << endl;
    return 0;
  }
  int sz = 0;
  while (n > 1) {
    n >>= 1;
    sz++;
  }
  n = (int)ss.size();
  string ans = "";
  int steps = (1 << sz) - 1;
  for (int msk = 0; msk < (1 << sz); ++msk) {
    for (int i = 0; i < sz; ++i) {
      if ((1 << i) & msk) continue;
      g[msk].push_back(i);
    }
  }
  int lft = n - steps;
  for (int i = lft - 1; i >= 0; --i) {
    for (int msk = (1 << sz) - 1; msk >= 0; --msk) {
      dp[i][msk] = ss[i + msk];
      for (auto to : g[msk]) {
        dp[i][msk] = min(dp[i][msk], dp[i][msk | (1 << to)]);
      }
    }
  }
  used[0][0] = 1;
  for (int i = 0; i < lft; ++i) {
    char mn = 'z';
    for (int j = 0; j < (1 << sz); ++j) {
      if (used[i][j]) {
        mn = min(mn, dp[i][j]);
      }
    }
    ans += mn;
    for (int j = 0; j < (1 << sz) - 1; ++j) {
      if (used[i][j] && dp[i][j] == mn) {
        if (ss[i + j] == mn) used[i + 1][j] = 1;
        for (auto to : g[j])
          if (dp[i][j | (1 << to)] == mn) used[i][j | (1 << to)] = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

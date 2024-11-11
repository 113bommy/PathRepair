#include <bits/stdc++.h>
using namespace std;
int fastMax(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y; }
int fastMin(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x; }
const int MAXN = 1e5 + 10;
const int MAXK = (1 << 20);
int n, m;
int t_mask;
int dp[MAXK];
int judehue[20][20];
int cnt[20];
int rec(int mask) {
  if (mask == t_mask) return 0;
  int &ans = dp[mask];
  if (ans != -1) return ans;
  ans = 1e8;
  int idx = __builtin_popcount(mask) + 1;
  for (int i = (0); i <= (m - 1); ++i) {
    if (((mask >> i) & 1) == 0) {
      int cnt = 0;
      for (int j = (0); j <= (m - 1); ++j) {
        if (i == j) continue;
        if ((mask >> j) & 1) {
          cnt += judehue[i][j];
        } else
          cnt -= judehue[i][j];
      }
      ans = min(ans, cnt * idx + rec(mask | (1 << i)));
    }
  }
  return ans;
}
void solve() {
  cin >> n >> m;
  t_mask = (1 << m) - 1;
  string second;
  cin >> second;
  for (int i = (0); i <= (n - 1); ++i) {
    if (i != 0) judehue[second[i] - 'a'][second[i - 1] - 'a']++;
    if (i != n - 1) judehue[second[i] - 'a'][second[i + 1] - 'a']++;
  }
  for (int i = (0); i <= (t_mask); ++i) dp[i] = -1;
  cout << rec(0) << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  for (int i = (1); i <= (t); ++i) {
    solve();
  }
}

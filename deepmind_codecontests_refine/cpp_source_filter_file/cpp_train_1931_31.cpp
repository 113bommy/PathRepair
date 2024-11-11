#include <bits/stdc++.h>
using namespace std;
int n, m, k, dp[1010][1010][10][2];
string s, t;
int go(int i, int j, int cnt, bool taken) {
  if (cnt > k) return -1e9;
  if (i == n || j == m) return (!(cnt == k)) * (-1e9);
  if (dp[i][j][cnt][taken] != -1) return dp[i][j][cnt][taken];
  int ret = max(go(i + 1, j, cnt, 0), go(i, j + 1, cnt, 0));
  if (s[i] == t[j]) {
    if (taken) {
      ret = max(ret, go(i + 1, j + 1, cnt, 1) + 1);
    }
    ret = max(ret, go(i + 1, j + 1, cnt + 1, 1) + 1);
  }
  return dp[i][j][cnt][taken] = ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> k >> s >> t;
  cout << go(0, 0, 0, 0) << endl;
}

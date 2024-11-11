#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, k, a[105];
long long int dp[105][105][105];
vector<vector<int> > v(104);
long long int calc(int i, int pclr, int bty) {
  if (i == n) {
    if (bty == k)
      return 0;
    else
      return 1e13;
  }
  long long int &ret = dp[i][pclr][bty];
  if (ret != -1) return ret;
  if (a[i] != 0) {
    if (a[i] == pclr)
      return ret = calc(i + 1, a[i], bty);
    else
      return ret = calc(i + 1, a[i], bty + 1);
  }
  ret = 1e12;
  for (int j = 0; j < m; j++) {
    if (j == pclr - 1)
      ret = min(ret, v[i][pclr - 1] + calc(i + 1, pclr, bty));
    else
      ret = min(ret, v[i][j] + calc(i + 1, j + 1, bty + 1));
  }
  return ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
    for (int x, j = 0; j < m; j++) {
      cin >> x;
      v[i].push_back(x);
    }
  long long int ans = 1e13;
  if (a[0] != 0)
    ans = calc(1, a[0], 1);
  else
    for (int i = 0; i < m; i++) {
      ans = min(v[0][i] + calc(1, i + 1, 1), ans);
    }
  if (ans >= 1e13)
    cout << -1;
  else
    cout << ans << endl;
  return 0;
}

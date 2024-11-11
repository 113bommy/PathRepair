#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e9 + 7;
const int MAX = 41;
int n, m;
vector<vector<long long> > multiply(vector<vector<long long> > a,
                                    vector<vector<long long> > b) {
  vector<vector<long long> > ret(n + 1, vector<long long>(n + 1, OO));
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        ret[i][j] = min(ret[i][j], (a[i][k] + b[k][j]));
      }
  return ret;
}
vector<vector<long long> > power(vector<vector<long long> > a, long long k) {
  if (k == 1) return a;
  if (k % 2) return multiply(a, power(a, k - 1));
  return power(multiply(a, a), k / 2);
}
int dp[21][MAX][MAX];
int a[21], b[21];
int rec(int indx, int r, int l) {
  if (indx == n) {
    if (r == l) return 0;
    return OO;
  }
  int &ret = dp[indx][r][l];
  if (ret != -1) return ret;
  ret = OO;
  ret = rec(indx + 1, r + 1, l) + a[indx];
  if (r > 0) ret = min(ret, rec(indx + 1, r - 1, l) + b[indx]);
  return ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<vector<long long> > ans(n + 1, vector<long long>(n + 1, OO));
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) ans[i][j] = rec(0, i, j);
  ans = power(ans, m);
  cout << ans[0][0] << endl;
}

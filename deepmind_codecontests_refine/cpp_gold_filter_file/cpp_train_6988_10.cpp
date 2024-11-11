#include <bits/stdc++.h>
using namespace std;
const int modd = 1e9 + 7;
inline void bbli(int &a, int b) {
  a = a + b;
  if (a < 0) a += modd;
  if (a >= modd) a -= modd;
}
const int inf = 2e9;
const int mxN = 200004;
const int di[] = {0, -1, 0, 1};
const int dj[] = {1, 0, -1, 0};
int n, m;
vector<vector<int>> a, mn1, mn2, dp;
int rfun(int i, int msk, int &ft, int &lt) {
  if (__builtin_popcount(msk) == n) {
    return mn1[i][lt];
  }
  if (dp[i][msk] != -1) return dp[i][msk];
  int ans = 0;
  for (int k = 0; k < n; k++) {
    if ((msk & (1 << k)) > 0) continue;
    int an = mn1[i][k];
    an = min(an, rfun(k, msk | (1 << k), ft, lt));
    ans = max(ans, an);
  }
  return dp[i][msk] = ans;
}
void dbgv(vector<vector<int>> &v) {
  for (auto x : v) {
    for (auto y : x) cout << y << " ";
    cout << endl;
  }
}
int main() {
  cin >> n >> m;
  a.resize(n, vector<int>(m));
  mn1.resize(n, vector<int>(n, inf));
  mn2.resize(n, vector<int>(n, inf));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        mn1[i][j] = min(mn1[i][j], abs(a[i][k] - a[j][k]));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 1; k < m; k++) {
        mn2[i][j] = min(mn2[i][j], abs(a[i][k] - a[j][k - 1]));
      }
    }
  }
  if (n == 1) {
    int an = inf;
    for (int i = 1; i < m; i++) an = min(an, abs(a[0][i] - a[0][i - 1]));
    cout << an;
    return 0;
  }
  dp.resize(n, vector<int>(1 << n));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < 1 << n; j++) dp[i][j] = -1;
      int msk = (1 << i);
      msk |= (1 << j);
      int an = mn2[i][j];
      an = min(an, rfun(i, msk, i, j));
      ans = max(ans, an);
    }
  }
  cout << ans;
}

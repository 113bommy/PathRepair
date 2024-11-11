#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long INF = 1e18;
const long double PI = acos((long double)-1);
const int N = 1000001;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)(name).size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
int main() {
  int n, m, c0, d0;
  cin >> n >> m >> c0 >> d0;
  vector<int> a(m + 1), b(m + 1), c(m + 1), d(m + 1);
  for (int i = (1); i < (m + 1); i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  vector<vector<int> > Dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= (a[i] / b[i]); j++) {
      for (int k = 1; k <= n; k++) {
        Dp[k][i] = max(Dp[k][i], Dp[k][i - 1]);
        if (c[i] * j <= k)
          Dp[k][i] = max(Dp[k][i], Dp[k - j * c[i]][i - 1] + d[i] * j);
      }
    }
  }
  int Ans = 0;
  for (int i = (0); i < (n + 1); i++) {
    Ans = max(Ans, Dp[i][m] + ((n - i) / c0) * d0);
  }
  cout << Ans;
}

#include <bits/stdc++.h>
using namespace std;
long long n, m, k, l;
string s;
pair<long long, long long> p[222];
long long dp[222][222] = {1};
long long solve() {
  for (int i = 0; i < l; i++)
    for (int j = 0; j <= l; j++) {
      if (s[i] == '(') {
        if (j)
          dp[i + 1][j] = dp[i][j - 1];
        else
          dp[i + 1][j] = 0;
      } else if (s[i] == ')' || !j)
        dp[i + 1][j] = dp[i][j + 1];
      else
        dp[i + 1][j] =
            (dp[i][j - 1] + dp[i][j + 1] > 2e18 ? 2e18
                                                : dp[i][j - 1] + dp[i][j + 1]);
    }
  return dp[l][0];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  l = m + n - 1;
  for (int i = 0; i < l; i++) p[i] = make_pair(2e18, i);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      p[i + j].first = (t > p[i + j].first ? p[i + j].first : t);
    }
  sort(p, p + l);
  for (int i = 0; i < l; i++) s += '?';
  for (int i = 0; i < l; i++) {
    s[p[i].second] = '(';
    long long f = solve();
    if (f < k) {
      k -= f;
      s[p[i].second] = ')';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << s[i + j];
    cout << endl;
  }
}

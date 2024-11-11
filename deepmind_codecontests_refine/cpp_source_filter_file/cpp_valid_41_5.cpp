#include <bits/stdc++.h>
using namespace std;
const long long mxN = 2e5, mod = 1e9 + 7;
const long long INF = 1e18;
vector<long long> findans(string &s1, string &s) {
  long long n = s.size();
  long long n1 = n / 3;
  long long n2 = n % 3;
  string s2 = "";
  for (long long i = 0; i < n1; i++) {
    s2 += s1;
  }
  s2 += s1.substr(0, n2);
  vector<long long> dp(n);
  if (s2[0] != s[0]) {
    dp[0]++;
  }
  for (long long i = 1; i < n; i++) {
    if (s[i] != s2[i]) {
      dp[i]++;
    }
    dp[i] += dp[i - 1];
  }
  return dp;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long ans = INT_MAX;
    vector<vector<long long>> dp(6, vector<long long>(n));
    long long cnt = 0;
    for (long long i = 0; i < 3; i++) {
      for (long long j = 0; j < 3; j++) {
        for (long long k = 0; k < 3; k++) {
          if (i != j && j != k && i != k) {
            char c1 = i + 'a';
            char c2 = k + 'a';
            char c3 = j + 'a';
            string s1 = "";
            s1.push_back(c1);
            s1.push_back(c2);
            s1.push_back(c3);
            dp[cnt] = findans(s1, s);
            cnt++;
          }
        }
      }
    }
    for (long long i = 0; i < m; i++) {
      long long l, r;
      cin >> l >> r;
      l--;
      r--;
      long long ans = INT_MAX;
      for (long long j = 0; j < 6; j++) {
        long long ls = 0;
        if (l > 0) {
          ls = dp[j][l - 1];
        }
        ans = min(ans, dp[j][r] - ls);
      }
      cout << ans << "\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18 + 100, mod = 1e9 + 7, MAX = 1e18;
vector<string> powers;
string tostr(long long n) {
  string s;
  while (n) {
    s.push_back((n % 10) + '0');
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
void pre() {
  for (long long i = 1; i <= MAX; i *= 2) {
    powers.push_back(tostr(i));
  }
}
long long dp[11][11];
long long solve(string &s1, string &s2, long long i, long long j) {
  if (i >= s1.size()) {
    return s2.size() - j;
  }
  if (j >= s2.size()) {
    return s1.size() - i;
  }
  if (dp[i][j] != -1) return dp[i][j];
  dp[i][j] = inf;
  if (s1[i] == s2[j]) dp[i][j] = solve(s1, s2, i + 1, j + 1);
  dp[i][j] = min(dp[i][j], 1 + solve(s1, s2, i + 1, j));
  return dp[i][j];
}
long long match(string s1, string s2) {
  memset(dp, -1, sizeof dp);
  return solve(s1, s2, 0, 0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  pre();
  while (t--) {
    long long n;
    cin >> n;
    string s = tostr(n);
    long long min_ = inf;
    for (auto a : powers) {
      min_ = min(min_, match(s, a));
    }
    cout << min_ << "\n";
  }
  return 0;
}

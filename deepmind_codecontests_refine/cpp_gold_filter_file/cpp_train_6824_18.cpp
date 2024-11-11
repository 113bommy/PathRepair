#include <bits/stdc++.h>
const long long int INF = 1000000000000000000, MOD = 1e9 + 7, MAXN = 10000;
const double EPS = 0.0000001;
using namespace std;
string rev(string s) {
  string s1 = "";
  for (long long int i = s.size() - 1; i >= 0; i--) {
    s1 += s[i];
  }
  return s1;
}
bool ask(string s, string s1) {
  for (long long int i = 0; i < min(s.size(), s1.size()); i++) {
    if (s[i] < s1[i]) return true;
    if (s[i] > s1[i]) return false;
  }
  return s.size() <= s1.size();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int n;
  cin >> n;
  vector<long long int> d(200000);
  for (long long int i = 0; i < n; i++) cin >> d[i];
  vector<string> str;
  for (long long int i = 0; i < n; i++) {
    string s;
    cin >> s;
    str.push_back(s);
  }
  long long int dp[200000][2];
  for (long long int i = 0; i < 200000; i++) {
    dp[i][0] = INF;
    dp[i][1] = INF;
  }
  dp[0][0] = 0;
  dp[0][1] = d[0];
  for (long long int i = 1; i < n; i++) {
    if (ask(str[i - 1], str[i]) && dp[i][0] > dp[i - 1][0]) {
      dp[i][0] = dp[i - 1][0];
    }
    if (ask(rev(str[i - 1]), str[i]) && dp[i][0] > dp[i - 1][1]) {
      dp[i][0] = dp[i - 1][1];
    }
    if (ask(str[i - 1], rev(str[i])) && dp[i][1] > dp[i - 1][0] + d[i]) {
      dp[i][1] = dp[i - 1][0] + d[i];
    }
    if (ask(rev(str[i - 1]), rev(str[i])) && dp[i][1] > dp[i - 1][1] + d[i]) {
      dp[i][1] = dp[i - 1][1] + d[i];
    }
  }
  if (dp[n - 1][0] == INF && dp[n - 1][1] == INF) {
    cout << -1;
    return 0;
  }
  cout << min(dp[n - 1][0], dp[n - 1][1]);
}

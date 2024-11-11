#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int MOD = 1e9 + 7;
const int N = 1e6 + 6;
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> pi = prefix_function(s.substr(i - 1, n - i + 1));
    for (int j = i, k = 0; j <= n; j++, k++) {
      int len = j - i + 1;
      dp[j] = min(dp[j], dp[i - 1] + 1 + len);
      int div = len - pi[k];
      if (div == len || (len % div)) continue;
      dp[j] = min(dp[j], div + dp[i - 1] + (int)log10(len / div) + 1);
    }
  }
  cout << dp[n] << '\n';
  return 0;
}

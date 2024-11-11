#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
vector<int> PrefixF(string s, int k) {
  vector<int> pi(int((s).size()));
  for (int i = k + 1; i < int((s).size()); ++i) {
    int j = pi[i - 1];
    while (j > k && s[i] != s[k + j]) j = pi[j - 1];
    if (s[i] == s[k + j]) ++j;
    pi[i] = j;
  }
  return pi;
}
int CountDigits(int k) {
  int res = 0;
  while (k) {
    ++res;
    k /= 10;
  }
  return res;
}
int main() {
  string s;
  cin >> s;
  vector<int> dp(int((s).size()) + 1, INF);
  dp[0] = 0;
  vector<vector<int> > pi(int((s).size()));
  for (int j = 0; j < int((s).size()); ++j) pi[j] = PrefixF(s, j);
  for (int i = 0; i < int((s).size()); ++i) {
    for (int j = 0; j <= i; ++j) {
      int n = i - j + 1;
      int T;
      if (n % (n - pi[j][i]))
        T = n;
      else
        T = n - pi[j][i];
      int k = n / T;
      dp[i + 1] = min(dp[i + 1], dp[j] + T + CountDigits(k));
    }
  }
  cout << dp.back() << endl;
  return 0;
}

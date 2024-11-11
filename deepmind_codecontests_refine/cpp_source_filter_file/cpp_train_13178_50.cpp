#include <bits/stdc++.h>
using namespace std;
const unsigned long long N = 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string str;
  cin >> str;
  vector<unsigned long long> hash[2];
  unsigned long long tmp = N;
  hash[0].push_back(str[0]);
  hash[1].push_back(str[0]);
  for (int i = 1; i < str.size(); ++i) {
    hash[0].push_back(hash[0].back() * N + str[i]);
    hash[1].push_back(hash[1].back() + str[i] * tmp);
    tmp *= N;
  }
  int ans = 1;
  vector<int> dp(str.size());
  dp[0] = 1;
  for (int i = 1; i < str.size(); ++i) {
    if (hash[0][i] == hash[1][i]) {
      dp[i] = dp[(i - 1) / 2] + 1;
      ans += dp[i];
    }
  }
  cout << ans << endl;
  return 0;
}

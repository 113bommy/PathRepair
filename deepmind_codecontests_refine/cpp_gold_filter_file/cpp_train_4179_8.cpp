#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int main() {
  int n;
  cin >> n;
  long long vals[MAXN], ans = 0, dp[MAXN][4];
  vector<long long> sum(4);
  vector<char> cs = {'h', 'a', 'r', 'd'};
  string s;
  cin >> s;
  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> vals[i];
    dp[i][0] = dp[i - 1][0] + (s[i - 1] == 'h' ? vals[i] : 0);
    dp[i][1] =
        min(dp[i - 1][0], dp[i - 1][1] + (s[i - 1] == 'a' ? vals[i] : 0));
    dp[i][2] =
        min(dp[i - 1][1], dp[i - 1][2] + (s[i - 1] == 'r' ? vals[i] : 0));
    dp[i][3] =
        min(dp[i - 1][2], dp[i - 1][3] + (s[i - 1] == 'd' ? vals[i] : 0));
  }
  cout << dp[n][3] << endl;
}

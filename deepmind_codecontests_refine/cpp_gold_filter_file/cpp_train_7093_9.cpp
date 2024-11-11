#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18, MAX = 5005, mod = 1000000007;
int main() {
  int n, a, b;
  int z[MAX];
  int dp[MAX];
  string s;
  cin >> n >> a >> b;
  cin >> s;
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = a + dp[i];
    string sr = s.substr(0, i + 1);
    reverse(sr.begin(), sr.end());
    int m = sr.length();
    z[0] = 0;
    int l = 0, r = 0;
    int j = 1;
    while (j < m) {
      if (j <= r)
        z[j] = min(r - j + 1, z[j - l]);
      else
        z[j] = 0;
      while (j + z[j] < m && sr[j + z[j]] == sr[z[j]]) z[j]++;
      if (j + z[j] - 1 >= r) l = j, r = j + z[j] - 1;
      int cur_len = min(z[j], j);
      if (cur_len > 0) dp[i + 1] = min(dp[i + 1], b + dp[i + 1 - cur_len]);
      j++;
    }
  }
  cout << dp[n] << endl;
  return 0;
}

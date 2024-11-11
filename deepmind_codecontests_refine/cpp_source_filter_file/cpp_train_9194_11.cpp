#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int T;
long long dp[101][2501];
int main() {
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j < 2501; j++) {
      long long res = 0;
      if (i == 0) {
        if (j == 0) res = 1;
      } else {
        for (int k = 0; k < 26; k++)
          if (j - k >= 0) res = (res + dp[i - 1][j - k]) % mod;
      }
      dp[i][j] = res % mod;
    }
  }
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1)
      cout << 1 << endl;
    else {
      int sum = 0;
      for (int i = 0; i < s.size(); i++) sum += (s[i] - 'a');
      cout << (dp[s.size()][sum] - 1 + mod) % mod << endl;
    }
  }
  return 0;
}

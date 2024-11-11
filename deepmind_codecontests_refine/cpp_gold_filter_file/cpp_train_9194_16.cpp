#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
const long long int INF = 2e18;
long long int dp[200][3000];
long long int tr(char a) { return (long long int)(a - 'a'); }
int main() {
  long long int tt = 'z' - 'a', mod = 1000000007;
  memset(dp, 0, sizeof dp);
  for (long long int i = 0; i <= tt; i++) {
    dp[0][i] = 1;
  }
  for (long long int i = 1; i < 100; i++) {
    for (long long int j = 0; j <= tt; j++) {
      long long int temp = 100;
      for (long long int d = 0; j + d < 3000; d++) {
        dp[i][j + d] = (dp[i][j + d] + dp[i - 1][d]) % mod;
      }
    }
  }
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    string s;
    cin >> s;
    long long int n = (long long int)s.size();
    if (n == 1) {
      cout << 0 << endl;
      continue;
    }
    long long int sum = 0;
    for (long long int j = 0; j < n; j++) {
      sum += s[j] - 'a';
    }
    cout << (dp[n - 1][sum] + mod - 1) % mod << endl;
  }
}

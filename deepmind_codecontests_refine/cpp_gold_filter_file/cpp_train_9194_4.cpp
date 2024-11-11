#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long dp[101][2501];
long long value(string a) {
  long long sum = 0;
  for (int i = 0; i < a.length(); i++) {
    sum += a[i];
    sum -= 'a';
  }
  return dp[a.length()][sum] - 1;
}
int main() {
  for (int j = 0; j <= 25; j++) {
    dp[1][j] = 1;
  }
  for (int i = 2; i <= 100; i++) {
    for (int j = 0; j <= 25 * i; j++) {
      dp[i][j] = 0;
      for (int k = max(j - 25, 0); k <= min(j, 25 * (i - 1)); k++) {
        dp[i][j] += dp[i - 1][k];
        dp[i][j] %= mod;
      }
    }
  }
  int cases;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    string a;
    cin >> a;
    cout << value(a) << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589;
const long long int zero = 0;
long long int mod = 1000000007;
char al[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
               'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main() {
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    long long int dp[n][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (long long int i = 1; i < n; i++) {
      if (i % 2 == 1) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + 1;
        dp[i][1] %= mod;
      } else {
        dp[i][1] = dp[i - 1][1];
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + 1;
        dp[i][0] %= mod;
      }
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod;
  }
}

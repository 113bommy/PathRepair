#include <bits/stdc++.h>
using namespace std;
const int maxN = 5000;
const long long mod = 1e9 + 7;
long long c[maxN][maxN], dp[maxN];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < maxN; i++) c[i][i] = 1;
  for (int i = 0; i < maxN; i++) c[i][0] = 1;
  for (int i = 1; i < maxN; i++)
    for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1] % mod;
  dp[1] = dp[0] = 1;
  for (int i = 2; i <= n; i++) {
    long long sum = 0;
    for (int j = 0; j < i; j++) {
      sum = sum + ((c[i - 1][j] * dp[i - j - 1]) % mod) % mod;
    }
    dp[i] = sum;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + c[n][i] * dp[n - i]) % mod;
  }
  cout << ans;
  return 0;
}

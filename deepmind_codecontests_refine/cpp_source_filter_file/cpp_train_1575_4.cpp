#include <bits/stdc++.h>
using namespace std;
long long int getN(long long int sum) {
  sum = sum * 8;
  sum = sqrt(sum + 1) - 1;
  sum /= 2;
  return sum;
}
long long int apSum(long long int n) {
  long long int a = 1, d = 1;
  long long int res = (2 * a + (n - 1) * d) * n;
  res /= 2;
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int mod = 998244353;
vector<vector<long long int>> dp;
long long int get(long long int n, long long int k, long long int m) {
  if (n == 0) return 0;
  if (k == 0) {
    return m;
  }
  if (dp[n][k] != -1) return dp[n][k];
  long long int res1 = get(n - 1, k - 1, m) * (m - 1);
  long long int res2 = get(n - 1, k, m);
  res1 %= mod;
  res2 %= mod;
  dp[n][k] = (res1 + res2) % mod;
  return dp[n][k];
}
void solveKaro() {
  long long int n, m, k;
  cin >> n >> m >> k;
  dp = vector<vector<long long int>>(n + 1, vector<long long int>(m + 1, -1));
  long long int ans = get(n, k, m);
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tCase = 1;
  while (tCase--) {
    solveKaro();
  }
}

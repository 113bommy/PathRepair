#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e5 + 10;
int n, m, k, T;
long long dp[N];
int main() {
  cin >> n >> m;
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= max(n, m); i++) dp[i] = dp[i - 1] + dp[i - 2];
  cout << (dp[n] - 1 + dp[m]) * 2 % mod;
}

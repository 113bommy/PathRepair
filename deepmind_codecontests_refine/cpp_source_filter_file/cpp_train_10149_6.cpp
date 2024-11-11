#include <bits/stdc++.h>
using namespace std;
int r;
int Abs(int x) {
  if (x < 0) return -x;
  return x;
}
long long Min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
int Max(int a, int b) {
  if (a > b) return a;
  return b;
}
long long dp[510][510];
int main() {
  long long n, m, b, mod;
  cin >> n >> m >> b >> mod;
  vector<int> errs;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    errs.push_back(a);
  }
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= b; j++) dp[i][j] = 0;
  dp[0][0] = 1;
  for (int k = 0; k < errs.size(); k++)
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= b; j++)
        if (j - errs[k] >= 0) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - errs[k]]) % mod;
        }
  long long ans = 0;
  for (int j = 0; j <= b; j++) {
    ans = (ans + dp[m][j]) % mod;
  }
  cout << ans << endl;
  return 0;
}

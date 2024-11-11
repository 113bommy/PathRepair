#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1);
const double eps = 1e-9;
const int inf = 1e9 + 7;
const long long lnf = 1e18 + 7;
const int maxn = 1e6 + 10;
long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(max(n, m) + 1);
  dp[1] = 2, dp[2] = 4;
  for (int i = 3; i <= max(n, m); i++) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  cout << dp[n] + dp[m] - 2 << endl;
  return 0;
}

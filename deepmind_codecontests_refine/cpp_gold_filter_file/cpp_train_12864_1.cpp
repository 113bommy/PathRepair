#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
double pi = 3.1415926535898;
const long long M = 1e9 + 7;
const int N = 50500;
const int inf = INT_MAX;
const double eps = 1e-6;
long long dp[100100];
long long a[100100];
int n, x;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  for (int i = 0; i < int(n); i++) cin >> a[i];
  for (int i = 0; i < int(n); i++) {
    dp[i + 1] = dp[i] + 20;
    dp[i + 1] = min(dp[i + 1], 50 + dp[lower_bound(a, a + n, a[i] - 89) - a]);
    dp[i + 1] =
        min(dp[i + 1], 120 + dp[lower_bound(a, a + n, a[i] - 1439) - a]);
    cout << dp[i + 1] - dp[i] << ' ';
  }
  return 0;
  ;
}

#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int N = 100001;
int a[1000005];
long long dp[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long n, i, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  dp[0] = 0;
  dp[1] = a[1];
  for (i = 2; i <= N; i++) {
    dp[i] = max(a[i] * (long long)i + dp[i - 2], dp[i - 1]);
  }
  cout << dp[n] << endl;
  return 0;
}

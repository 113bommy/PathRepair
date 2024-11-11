#include <bits/stdc++.h>
using namespace std;
long long ar[100005];
long long dp[100005];
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ar[x]++;
  }
  dp[0] = 0;
  dp[1] = ar[1];
  for (int i = 2; i < 100002; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + (i * ar[i]));
  }
  cout << dp[100001];
  return 0;
}

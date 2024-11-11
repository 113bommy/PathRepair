#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int n, i;
  cin >> n;
  long long int a[n], c[100001] = {0}, dp[100001];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }
  dp[0] = 0;
  dp[1] = c[1];
  for (i = 2; i < 100001; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + c[i] * i);
  }
  cout << dp[100000];
  return 0;
}

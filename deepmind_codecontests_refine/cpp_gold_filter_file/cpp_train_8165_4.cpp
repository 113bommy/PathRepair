#include <bits/stdc++.h>
using namespace std;
long long dp[100005], cnt[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  dp[0] = 0, dp[1] = cnt[1];
  for (int i = 2; i <= 100000; i++)
    dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
  cout << dp[100000] << endl;
}

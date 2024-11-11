#include <bits/stdc++.h>
using namespace std;
int num[200000];
long long cnt[200000] = {0};
long long dp[200000] = {0};
long long sum[200000] = {0};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
    cnt[num[i]]++;
  }
  long long ans = 0;
  for (int i = 1; i < 200000; ++i) {
    if (i > 1) {
      dp[i] = max(dp[i - 2] + cnt[i] * i, dp[i - 1]);
    } else {
      dp[i] = cnt[i] * i;
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}

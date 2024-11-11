#include <bits/stdc++.h>
using namespace std;
int dp[44], po[44];
long long int tw[44], arr[111111], val = 0, val2 = 0;
int main(void) {
  int n;
  scanf("%d", &n);
  tw[0] = 1;
  for (int e = 1; e < 44; e++) tw[e] = tw[e - 1] * 2;
  for (int e = 0; e < n; e++) {
    scanf("%lld", &arr[e]);
    int err = 0;
    for (int p = 0; p < 44; p++)
      if (arr[e] == tw[p]) {
        dp[p]++;
        err++;
      }
    if (err == 0) {
      val2++;
      long long int tmp = arr[e], num = 0;
      while (tmp != 0) {
        tmp /= 2;
        num++;
      }
      po[num - 1]++;
    }
  }
  vector<int> v;
  for (int e = 1; e <= dp[0]; e++) {
    int dp2[44], dp3[44];
    memset(dp2, 0, sizeof(dp2));
    for (int p = 0; p < 44; p++) dp3[p] = po[p];
    int num = e, diff = dp[0] - e + val2;
    dp3[0] += dp[0] - e;
    for (int p = 1; p < 44; p++) {
      dp2[p - 1] = max(0, num - dp[p]);
      dp3[p] += max(0, dp[p] - num);
      diff += max(0, dp[p] - num);
      num = min(num, dp[p]);
    }
    for (int p = 42; p >= 0; p--) {
      dp3[p] += dp3[p + 1];
      dp2[p] += dp2[p + 1];
    }
    if (diff == e || diff == 0) {
      int err = 0;
      for (int p = 43; p >= 0; p--) {
        if (dp2[p] < dp3[p]) err++;
      }
      if (err == 0) {
        v.push_back(e);
      }
    }
  }
  if (v.size() == 0)
    printf("-1");
  else {
    for (int p = 0; p < v.size(); p++) printf("%d ", v[p]);
  }
  return 0;
}

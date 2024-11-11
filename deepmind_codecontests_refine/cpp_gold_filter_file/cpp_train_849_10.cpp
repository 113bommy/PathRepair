#include <bits/stdc++.h>
using namespace std;
long long dp1[200005], dp2[200005];
int main() {
  int n, x;
  long long ans1 = 0, ans2 = 0;
  scanf("%d", &n);
  dp1[0] = 0;
  dp2[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x > 0) {
      dp1[i] = dp1[i - 1] + 1;
      dp2[i] = dp2[i - 1];
    } else {
      dp1[i] = dp2[i - 1];
      dp2[i] = dp1[i - 1] + 1;
    }
    ans1 += dp1[i];
    ans2 += dp2[i];
  }
  printf("%lld %lld\n", ans2, ans1);
  return 0;
}

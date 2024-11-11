#include <bits/stdc++.h>
using namespace std;
const int N = 55;
long long int dp[N], n, k;
void init() {
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i < N; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
}
int main() {
  init();
  scanf("%I64d%I64d", &n, &k);
  int ans[60];
  for (int i = 1; i <= n; i++) {
    if (k <= dp[n - i])
      ans[i] = i;
    else if (k > dp[n - i]) {
      ans[i] = i + 1;
      ans[i + 1] = i;
      k -= dp[n - i];
      i++;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

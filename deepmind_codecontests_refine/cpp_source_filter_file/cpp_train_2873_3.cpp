#include <bits/stdc++.h>
const int MAX_N = 300000;
const long long MOD = 1000000007;
long long x[1 + MAX_N];
long long count[1 + MAX_N];
long long sum[1 + MAX_N];
long long ans[1 + MAX_N];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
  std::sort(x + 1, x + n + 1);
  count[1] = 1;
  sum[1] = 0;
  ans[1] = 0;
  for (int i = 2; i <= n; i++) {
    count[i] = 2 * count[i - 1] % MOD;
    sum[i] = (sum[i - 1] + (x[i] - x[i - 1]) * (count[i] + MOD - 1)) % MOD;
    ans[i] = 2 * ans[i - 1] + sum[i];
  }
  int answer = ans[n];
  printf("%d\n", answer);
  return 0;
}

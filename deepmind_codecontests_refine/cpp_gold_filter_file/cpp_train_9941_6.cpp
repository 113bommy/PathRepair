#include <bits/stdc++.h>
const long long int mod = 1000000007;
long long int combi[1001][1001];
long long int C(int n, int r) {
  if (combi[n][r]) return combi[n][r];
  if (n == 0)
    return combi[n][r] = 1;
  else if (r == 0)
    return combi[n][r] = C(n - 1, r);
  else if (n == r)
    return combi[n][r] = C(n - 1, r - 1);
  else
    return combi[n][r] = (C(n - 1, r - 1) + C(n - 1, r)) % mod;
}
int main() {
  int n;
  scanf("%d", &n);
  long long int ans = 1LL;
  int total_ball = 0;
  for (int i = 0; i < n; i++) {
    int cur_ball;
    scanf("%d", &cur_ball);
    ans *= C(total_ball + cur_ball - 1, cur_ball - 1);
    ans %= mod;
    total_ball += cur_ball;
  }
  printf("%I64d", ans);
}

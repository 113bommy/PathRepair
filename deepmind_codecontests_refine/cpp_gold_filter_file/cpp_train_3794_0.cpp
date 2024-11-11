#include <bits/stdc++.h>
using namespace std;
long long M, K, dp[70][70][2], bits;
bool bit[70];
long long f(int ind, int k, int t) {
  if (dp[ind][k][t] != -1) return dp[ind][k][t];
  if (ind == bits + 1) return k == 0;
  dp[ind][k][t] = f(ind + 1, k, t ? 1 : (bit[ind] == 1 ? 1 : 0));
  if (k and (t or bit[ind] == 1)) dp[ind][k][t] += f(ind + 1, k - 1, t);
  return dp[ind][k][t];
}
long long F(long long N) {
  bits = 0;
  while (N) {
    bit[++bits] = N & 1;
    N >>= 1;
  }
  reverse(bit + 1, bit + bits + 1);
  memset(dp, -1, sizeof(dp));
  return f(1, K, 0);
}
int main() {
  scanf("%lld%lld", &M, &K);
  long long b = 0, e = 1e18;
  while (b < e) {
    if (F(2 * ((b + e) / 2 + 1)) - F(((b + e) / 2 + 1)) > M)
      e = ((b + e) / 2 + 1) - 1;
    else
      b = ((b + e) / 2 + 1);
  }
  printf("%lld\n", b);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, k;
int ara[2010];
int thold = 2002;
int dp[2010][2010];
long long func(int pos, int taken) {
  if (pos == n) {
    if (taken > thold) {
      return 1;
    }
    return 0;
  }
  if (dp[pos][taken] != -1) {
    return dp[pos][taken];
  }
  long long ans = 0;
  if (ara[pos] != ara[pos + 1]) {
    ans += func(pos + 1, taken + 1);
    ans %= 998244353;
    ans += func(pos + 1, taken - 1);
    ans %= 998244353;
    ans += ((k - 2LL) * func(pos + 1, taken)) % 998244353;
    ans %= 998244353;
  } else {
    ans += (k * func(pos + 1, taken)) % 998244353;
    ans %= 998244353;
  }
  return dp[pos][taken] = ans;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i <= n - 1; i++) {
    cin >> ara[i];
  }
  ara[n] = ara[0];
  memset((dp), -1, sizeof(dp));
  cout << func(0, 0 + thold);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 2105;
const long long MOD = 998244353;
long long n, k, ara[N];
long long dp[N][2 + N];
long long call(int pos, int d) {
  if (pos == n) {
    return d > 0;
  }
  if (dp[pos][d + N] != -1) return dp[pos][d + N];
  long long ret = 0;
  int prev = ara[(pos + n - 1) % n];
  int now = ara[pos];
  if (prev == now) {
    ret += call(pos + 1, d);
    ret %= MOD;
    ret += (k - 1) * call(pos + 1, d);
    ret %= MOD;
  } else {
    ret += call(pos + 1, d + 1);
    ret %= MOD;
    ret += call(pos + 1, d - 1);
    ret %= MOD;
    ret += (k - 2) * call(pos + 1, d);
    ret %= MOD;
  }
  return dp[pos][d + N] = ret % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> ara[i];
  memset(dp, -1, sizeof(dp));
  cout << call(0, 0) << "\n";
}

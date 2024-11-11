#include <bits/stdc++.h>
using namespace std;
int dig[20];
const int M = 262145;
long long dp[262145][101];
int m;
int pos;
long long dfs(int state, int x) {
  long long ans = 0;
  if (state == (1 << pos) - 1) return x == 0;
  long long &dpAns = dp[state][x];
  if (dpAns != -1) return dpAns;
  int vis[10] = {0};
  for (int i = pos - 1; i >= 0; i--) {
    if ((1 << i) & state) continue;
    if (vis[dig[i]]) continue;
    vis[dig[i]] = 1;
    ans += dfs(state | 1 << i, (x * 10 + dig[i]) % m);
  }
  dpAns = ans;
  return ans;
}
long long solve(long long n) {
  pos = 0;
  while (n) {
    dig[pos++] = n % 10;
    n /= 10;
  }
  long long ans = 0;
  int vis[10] = {0};
  for (int i = pos - 1; i >= 0; i--)
    if (dig[i] && !vis[dig[i]]) {
      vis[dig[i]] = 1;
      ans += dfs(1 << i, dig[i] % m);
    }
  return ans;
}
int main(void) {
  long long a;
  while (cin >> a >> m) {
    memset(dp, -1, sizeof(dp));
    cout << solve(a) << endl;
  }
  return 0;
}

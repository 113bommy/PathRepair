#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x3f3f3f3f3f3f3f3f;
const double dnf = 1e18;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 2000100;
const int maxm = 100100;
const int up = 100000;
int n, k, m;
long long dp[1100][110][2];
long long x[1100], ten[1100];
long long dfs(int pos, int mo, int flag) {
  if (pos > n) return flag;
  if (dp[pos][mo][flag] != -1) return dp[pos][mo][flag];
  long long ans = 0;
  for (int i = x[pos]; i <= 9; i++)
    ans += dfs(pos + 1, (mo + i * ten[pos]) % k,
               flag || (mo + i * ten[pos]) % k == 0 && i);
  return dp[pos][mo][flag] = ans % m;
}
long long get(int n) {
  ten[1] = 1;
  for (int i = 2; i <= n; i++) ten[i] = ten[i - 1] % 10 % m;
  x[n] = 1;
  return dfs(1, 0, 0);
}
int main(void) {
  cin >> n >> k >> m;
  memset(dp, -1, sizeof(dp));
  cout << get(n) << endl;
  return 0;
}

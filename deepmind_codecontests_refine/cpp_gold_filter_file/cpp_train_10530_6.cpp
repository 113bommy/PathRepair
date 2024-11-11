#include <bits/stdc++.h>
using namespace std;
const long long int N = 1E5 + 5, K = 13, M = 4;
long long int dp[N][K][1 << M];
long long int n, k, m;
long long int mod = 1E9 + 7;
long long int rec(long long int pid, long long int kid, long long int mask) {
  if (kid == 0) return 1;
  if (pid <= 0) return 0;
  if (pid < kid) return 0;
  if (dp[pid][kid][mask] != -1) return dp[pid][kid][mask];
  long long int ans = 0;
  long long int nwmask = (mask << 1) % (1 << m);
  ans = rec(pid - 1, kid, nwmask);
  nwmask |= 1;
  ans = (ans + rec(pid - 1, kid - 1, nwmask)) % mod;
  for (long long int i = 0; i < m; i++) {
    if (mask & (1 << i)) {
      nwmask = (mask << 1) % (1 << m);
      nwmask |= 1;
      ans = (ans + rec(pid - 1, kid - 1, nwmask)) % mod;
    }
  }
  dp[pid][kid][mask] = ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k >> m;
  for (long long int i = 0; i <= n; i++)
    for (long long int j = 0; j <= k; j++)
      for (long long int p = 0; p < (1 << m); p++) dp[i][j][p] = -1;
  long long int mask = 0;
  cout << rec(n, k, mask) << endl;
  return 0;
}

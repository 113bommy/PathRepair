#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int MOD = 1000000007;
const int N = 1e5 + 50;
int n;
int arr[N], q[3];
long long dp[N][3];
bool vis[N][3];
long long solve(int idx, int p) {
  if (p == 3) return 0;
  if (idx == n) return -(1ll << 63);
  long long &ret = dp[idx][p];
  if (vis[idx][p]) return ret;
  vis[idx][p] = 1;
  if (~ret) return ret;
  return ret =
             max(solve(idx, p + 1) + 1ll * q[p] * arr[idx], solve(idx + 1, p));
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < 3; ++i) cin >> q[i];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  cout << solve(0, 0) << endl;
  return 0;
}

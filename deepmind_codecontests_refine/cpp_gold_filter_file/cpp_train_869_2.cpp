#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int dp[N][N] = {}, arr[N] = {}, n, m;
int solve(int idx, int prv) {
  if (idx >= n) return 0;
  int &ret = dp[idx][prv];
  if (ret != -1) return ret;
  ret = 0;
  ret = max(ret, solve(idx + 1, prv));
  if (arr[idx] >= prv) ret = max(ret, solve(idx + 1, arr[idx]) + 1);
  return ret;
}
int main() {
  ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  ;
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  ;
  double z;
  for (int i = 0; i <= (int)n - 1; ++i) cin >> arr[i] >> z;
  cout << n - solve(0, 0) << "\n";
  return 0;
}

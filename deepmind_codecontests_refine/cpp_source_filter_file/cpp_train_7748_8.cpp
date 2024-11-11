#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[2000][2001];
long long go(int pre, int k) {
  if (k == 0) return 1;
  long long &ret = dp[pre][k];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = pre; i <= n; i += pre) ret += (go(i, k - 1)) % 1000000007;
  return ret % 1000000007;
}
int main() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  ;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    res += go(i, k - 1);
  }
  cout << res % 1000000007 << endl;
}

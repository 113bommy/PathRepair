#include <bits/stdc++.h>
using namespace std;
int n, m;
long long dp[((int)1e5 + 5)];
long long go(int x) {
  if (x <= 1) return 1;
  long long& ret = dp[x];
  if (ret != -1) return ret;
  ret = (go(x - 1) + go(x - 2)) % ((int)1e9 + 7);
  return ret;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  cout << ((go(m) + 1) << 1) % ((int)1e9 + 7);
  return 0;
}

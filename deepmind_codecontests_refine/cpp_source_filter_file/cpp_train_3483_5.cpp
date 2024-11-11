#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5 + 7;
const int MX = 1e5 + 1;
long long int dp[MX + 2];
long long int sum[MX + 2];
int k, n;
long long int blah(int pos) {
  if (pos == 0) return 1LL;
  long long int &ret = dp[pos];
  if (ret != -1) return ret;
  long long int r1 = 0, r2 = 0;
  if (pos >= k) {
    r1 = blah(pos - k) % MOD;
  }
  r2 = blah(pos - 1) % MOD;
  ret = (r1 + r2) % MOD;
  return ret;
}
void solve() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  long long int cnt = blah(MX);
  for (int i = 1; i <= MX; i++) {
    sum[i] = (sum[i - 1] + dp[i] + MOD) % MOD;
  }
  int x, y;
  while (n--) {
    cin >> x >> y;
    cout << (sum[y] - sum[x - 1] + MOD) % MOD << "\n";
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}

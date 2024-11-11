#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
const long long inf = 9e15 + 9;
long long res;
long long a[N], n;
long long dp[201][300];
long long go(long long idx, long long time) {
  if (idx == n) {
    return 0;
  }
  if (time > 300 && idx < n) {
    return inf;
  }
  if (dp[idx][time] + 1) {
    return dp[idx][time];
  }
  long long xx = go(idx + 1, time + 1) + abs(a[idx] - time);
  long long yy = go(idx, time + 1);
  return dp[idx][time] = min(xx, yy);
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof dp);
  sort(a, a + n);
  cout << go(0, 1) << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

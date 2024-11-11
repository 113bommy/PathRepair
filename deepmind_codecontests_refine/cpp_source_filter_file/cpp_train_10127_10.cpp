#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MXN = 2e5 + 5;
const long long LMXN = 1e14;
const int MOD = 1e9 + 7;
long long cs = 0;
const int N = 3e5 + 5;
int n, p;
int a[N];
long long dp[N][2];
long long fc(int pos, int cnt) {
  if (pos >= n) return 0;
  if (dp[pos][cnt] != -1) return dp[pos][cnt];
  long long v1 = fc(pos + 1, cnt);
  long long v2 = fc(pos + 1, cnt + 1);
  if (cnt % 2)
    v2 -= a[pos];
  else
    v2 += a[pos];
  return dp[pos][cnt] = max(v1, v2);
}
void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> p;
  for (int i = 0; i < (n); i++) cin >> a[i];
  fc(0, 0);
  cout << dp[0][0] << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout << fixed;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

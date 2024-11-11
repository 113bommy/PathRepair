#include <bits/stdc++.h>
using namespace std;
long long fibs[111];
int cnt;
const long long lim = 1000000000000000000LL;
void pre() {
  cnt = 0;
  fibs[++cnt] = 1;
  fibs[++cnt] = 2;
  while (true) {
    cnt++;
    fibs[cnt] = fibs[cnt - 1] + fibs[cnt - 2];
    if (fibs[cnt] > lim) break;
  }
  --cnt;
}
long long n;
long long dp[111][2];
long long arr[111];
int pos[111];
void solve() {
  int p = cnt;
  long long cur = n;
  int ctr = 0;
  while (cur >= 1) {
    if (cur >= fibs[p]) {
      pos[ctr] = p;
      arr[ctr++] = fibs[p];
      cur -= fibs[p];
    }
    --p;
  }
  int x = pos[ctr - 1] - 1;
  dp[ctr - 1][0] = 1;
  dp[ctr - 1][1] = x / 2;
  for (int i = ctr - 2; i >= 0; i--) {
    dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
    x = pos[i] - pos[i + 1] - 1;
    dp[i][1] = (x / 2) * (dp[i + 1][1] + dp[i + 1][0]);
    if (x & 1) dp[i][1] += (dp[i + 1][1]);
  }
  cout << (dp[0][0] + dp[0][1]) << endl;
}
int main() {
  pre();
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    solve();
  }
  return 0;
}

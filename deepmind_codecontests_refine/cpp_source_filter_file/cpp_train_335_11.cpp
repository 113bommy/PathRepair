#include <bits/stdc++.h>
using namespace std;
vector<long long> dp(2000005, 0);
void calc() {
  dp[1] = dp[2] = 0;
  dp[3] = dp[4] = 1;
  for (long long i = 5; i <= 100; i++) {
    dp[i] = max((1 + dp[i - 2] + 4 * dp[i - 3] + 4 * dp[i - 4]) % 1000000007,
                (dp[i - 1] + 2 * dp[i - 2]) % 1000000007);
  }
  cout << endl;
}
void solve() {
  long long n;
  cin >> n;
  cout << (dp[n] * 4) % 1000000007 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  calc();
  int t = 1, i;
  if (1) cin >> t;
  for (i = 1; i <= t; i++) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
}

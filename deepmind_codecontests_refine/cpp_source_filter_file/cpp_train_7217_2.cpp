#include <bits/stdc++.h>
using namespace std;
const long long int N = 21;
double p[N][N], dp[(1 << N)];
double pMove(long long int prev_mask, long long int j, long long int &n) {
  long long int k = __builtin_popcountll(prev_mask);
  long long int den = (k * (k - 1)) / 2;
  double move_probab = 0;
  for (long long int fish = 0; fish < n; fish++) {
    if (prev_mask & (1 << fish)) {
      move_probab += p[fish][j];
    }
  }
  return move_probab / (2.0 * den);
}
double rec(long long int mask, long long int &n) {
  long long int alive = __builtin_popcountll(mask);
  if (alive == n) return 1;
  if (dp[mask] > -1.0) return dp[mask];
  double ans = 0;
  for (long long int fish = 0; fish < n; fish++) {
    if (!(mask & (1 << fish))) {
      long long int prev_mask = mask ^ (1 << fish);
      double prev_day = rec(prev_mask, n);
      ans += prev_day * pMove(prev_mask, fish, n);
    }
  }
  return dp[mask] = ans;
}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  for (long long int i = 0; i < n; i++) {
    cout << fixed << setprecision(10) << rec((1 << i), n) << " ";
    ;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test_cases = 1;
  while (test_cases--) {
    solve();
  }
  cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n ";
  return 0;
}

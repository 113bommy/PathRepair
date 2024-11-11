#include <bits/stdc++.h>
using namespace std;
long double dp[4005][4005];
long double absf(long double a) {
  if (a < 0) return a * (-1);
  return a;
}
long double solve(vector<long double> &a, long long idx, long long left) {
  if (idx >= a.size()) return left == 0 ? 0 : 100000;
  if (dp[idx][left] != -100000) {
    return dp[idx][left];
  }
  long double cur_up = ceil(a[idx]);
  long double cur_down = floor(a[idx]);
  if (left > 0) {
    long double pt1 = a[idx] - cur_down + solve(a, idx + 1, left - 1);
    long double pt2 = a[idx] - cur_up + solve(a, idx + 1, left);
    if (absf(pt1) < absf(pt2)) {
      return dp[idx][left] = pt1;
    } else {
      return dp[idx][left] = pt2;
    }
  } else {
    long double pt2 = a[idx] - cur_up + solve(a, idx + 1, left);
    return dp[idx][left] = pt2;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long double> a;
  for (long long i = 0; i < 2 * n; i++) {
    long double temp;
    cin >> temp;
    a.push_back(temp);
  }
  for (long long i = 0; i < 4005; i++) {
    for (long long j = 0; j < 4005; j++) {
      dp[i][j] = -100000;
    }
  }
  long double res = abs(solve(a, 0, n));
  cout << fixed << setprecision(3);
  cout << res << '\n';
  return 0;
}

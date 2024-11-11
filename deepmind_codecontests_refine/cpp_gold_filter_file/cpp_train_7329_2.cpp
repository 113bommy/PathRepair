#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
long long dp[100005][2][2];
long long v[100005];
string s;
int N;
long long solve(int p, int t, bool e) {
  if (p < 0) return 0;
  if (dp[p][t][e] != -1) return dp[p][t][e];
  if (e) {
    if (s[p] == '1') {
      if (t == 1)
        return dp[p][t][e] = v[p] + max(solve(p - 1, 0, e), solve(p - 1, 1, e));
      if (t == 0)
        return dp[p][t][e] = max(solve(p - 1, 0, !e), solve(p - 1, 1, !e));
    }
    if (s[p] == '0') {
      if (t == 1) return dp[p][t][e] = 0;
      if (t == 0)
        return dp[p][t][e] = max(solve(p - 1, 0, e), solve(p - 1, 1, e));
    }
  }
  if (!e) {
    if (t == 1)
      return dp[p][t][e] = v[p] + max(solve(p - 1, 0, e), solve(p - 1, 1, e));
    if (t == 0)
      return dp[p][t][e] = max(solve(p - 1, 0, e), solve(p - 1, 1, e));
  }
}
int main() {
  cin >> N;
  for (int i = (0); i < (N); ++i) cin >> v[i];
  cin >> s;
  memset(dp, 0xff, sizeof(dp));
  long long ans;
  if (s[N - 1] == '1')
    ans = max(solve(N - 1, 1, true), solve(N - 1, 0, false));
  else
    ans = solve(N - 1, 0, true);
  cout << ans << endl;
  return 0;
}

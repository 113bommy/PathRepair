#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int maxn = 1e6;
const int max_log = 23;
int n, a[maxn], dp[1 << max_log];
bool p[1 << max_log];
int solve(int x) {
  if (dp[x] != 0) return dp[x];
  for (int i = 0; i <= max_log; i++)
    if (((x & (1 << i)) && 1)) {
      if (p[(x & ~(1 << i))]) return dp[x] = (x & ~(1 << i));
      int tmp = solve((x & ~(1 << i)));
      if (tmp != -1) return dp[x] = tmp;
    }
  return dp[x] = -1;
}
int REV(int x) {
  for (int i = 0; i < max_log; i++)
    if (((x & (1 << i)) && 1))
      x = (x & ~(1 << i));
    else
      x = (x | (1 << i));
  return x;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], p[a[i]] = 1;
  dp[0] = -1;
  for (int i = 0; i < n; i++) cout << solve(REV(a[i])) << ' ';
  cout << endl;
}

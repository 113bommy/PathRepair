#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const long long INF = 1e18;
int a[N], l[N], r[N];
int n, k;
unordered_map<int, long long> dp[N];
long long rec(int i, int rem) {
  if (i > n) return 0;
  long long temp = a[i] - rem - (r[i] - l[i]) * 1LL * k;
  if (temp > 0) return INF;
  if (dp[i].count(rem)) {
    return dp[i][rem];
  }
  temp = a[i] - rem;
  int m = (temp + k - 1) / k;
  int new_rem = m * k - temp;
  long long ans = rec(i + 1, new_rem);
  if (l[i] + m < l[i + 1]) {
    ans = min(ans, new_rem + rec(i + 1, k));
  }
  if (ans >= INF) ans = INF;
  return dp[i][rem] = ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i] >> a[i];
    sum += a[i];
  }
  long long ans = rec(1, k);
  if (ans >= INF)
    ans = -1;
  else
    ans += sum;
  cout << ans;
  return 0;
}

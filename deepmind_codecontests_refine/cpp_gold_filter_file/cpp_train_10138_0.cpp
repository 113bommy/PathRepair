#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, a[200005], dp[200005][4], k = 1;
int vis[200005][3];
long long f(long long x, int t) {
  if (x <= 0 || x > n) return 0;
  if (vis[x][t] == k) return -1e15;
  if (dp[x][t] != -1) return dp[x][t];
  vis[x][t] = k;
  long long ans = 0;
  if (t)
    ans += f(x + a[x], 0) + a[x];
  else
    ans += f(x - a[x], 1) + a[x];
  return dp[x][t] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 2; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    a[1] = i;
    long long ans = f(1, 1);
    if (ans > 0)
      cout << ans << endl;
    else
      cout << -1 << endl;
    dp[1][1] = -1;
    k++;
  }
}

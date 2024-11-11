#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MAX = 1e4 + 5;
long long i, j, k, n, m, ans, dp[1005][20005], a[1005];
long long f(int x, int k) {
  if (x > n && k == 0) return 1;
  if (x > n) return 0;
  long long &r = dp[x][k + MAX];
  if (r != -1) return r;
  return r = (f(x + 1, -a[x] + k) + f(x + 1, a[x] + k) + !k) % 1000000007;
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) ans = (ans + f(i, 0) - 1) % 1000000007;
  cout << ans << '\n';
  return 0;
}

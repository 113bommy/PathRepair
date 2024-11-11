#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, inf = 0x3f3f3f3f;
const long long mod = 998244353;
const double pi = acos(-1);
int dp[maxn], a[maxn], pre[maxn], sum[maxn];
int main() {
  int n, c;
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] += sum[i - 1] + (a[i] == c);
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    dp[i] = max(sum[i], dp[pre[a[i]]] + 1);
    pre[a[i]] = i;
    ans = max(ans, dp[i] + sum[n] - sum[i]);
  }
  cout << ans << endl;
}

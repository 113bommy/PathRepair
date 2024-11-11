#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 200000 + 5;
int n, a[maxn];
long long pre[maxn], dp[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), pre[i] = pre[i - 1] + a[i];
  dp[n] = pre[n];
  long long mx = pre[n];
  for (int i = n - 1; i >= 1; i--) dp[i] = mx, mx = max(mx, pre[i] - dp[i]);
  cout << dp[1] << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int n, m, b, a[105], c[105], q[105], s, d, dp[(1 << 20) + 5],
    ans = -1;
void MIN(long long int &a, long long int b) {
  if (a == -1 or b < a) a = b;
}
int main() {
  int x;
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> b;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i] >> c[i] >> s;
    for (long long int j = 1; j <= s; j++) {
      cin >> x;
      q[i] += 1 << x - 1;
    }
  }
  for (long long int i = 1; i <= n; i++)
    for (long long int j = 1; j <= n - i; j++)
      if (c[j] > c[j + 1]) {
        swap(c[j], c[j + 1]);
        swap(a[j], a[j + 1]);
        swap(q[j], q[j + 1]);
      }
  dp[0] = 0;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j <= ((1 << m) - 1); j++)
      if (dp[j] != -1) MIN(dp[j | q[i]], dp[j] + a[i]);
    if (dp[((1 << m) - 1)] != -1) MIN(ans, dp[((1 << m) - 1)] + c[i] * b);
  }
  cout << ans << endl;
  return 0;
}

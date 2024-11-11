#include <bits/stdc++.h>
using namespace std;
const long long C = 10000;
long long n, mei[110], k, ka[110], dp1[10010], dp2[10010], ans;
int main() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> mei[i];
  for (long long i = 1; i <= n; i++) {
    cin >> ka[i];
    ka[i] = mei[i] - ka[i] * k;
  }
  for (long long i = C; i >= 1; i--) dp1[i] = dp2[i] = -1e9;
  for (long long i = 1; i <= n; i++) {
    if (ka[i] >= 0)
      for (long long j = C; j >= ka[i]; j--) {
        dp1[j] = max(dp1[j], dp1[j - ka[i]] + mei[i]);
      }
    if (ka[i] < 0)
      for (long long j = C; j >= -ka[i]; j--) {
        dp2[j] = max(dp2[j], dp2[j + ka[i]] + mei[i]);
      }
  }
  for (long long i = C; i >= 0; i--) ans = max(ans, dp1[i] + dp2[i]);
  if (ans)
    cout << ans;
  else
    cout << -1;
  return 0;
}

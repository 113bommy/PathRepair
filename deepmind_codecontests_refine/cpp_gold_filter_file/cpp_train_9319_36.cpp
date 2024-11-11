#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, a[1001], b[1001];
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i], a[i] |= a[i - 1];
  for (long long i = 1; i <= n; i++) cin >> b[i], b[i] |= b[i - 1];
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = i; j <= n; j++)
      ans = max(ans, (b[j] | b[i - 1]) + (a[j] | a[i - 1]));
  cout << ans << '\n';
  return 0;
}

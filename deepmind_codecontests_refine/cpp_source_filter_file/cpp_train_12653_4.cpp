#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], b[200005], Min[200005][20], Max[200005][20];
long long getmin(long long l, long long r) {
  long long ans = 1e9;
  for (long long k = 19; k >= 0; k--)
    if (l + (1ll << k) - 1 <= r) {
      ans = min(ans, Min[l][k]);
      l += (1ll << k);
    }
  return ans;
}
long long getmax(long long l, long long r) {
  long long ans = -1e9;
  for (long long k = 19; k >= 0; k--)
    if (l + (1ll << k) - 1 <= r) {
      ans = max(ans, Max[l][k]);
      l += (1ll << k);
    }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  for (long long i = 0; i < n; i++) {
    Min[i][0] = a[i];
    Max[i][0] = b[i];
  }
  for (long long k = 1; k < 20; k++)
    for (long long i = 0; i + (1ll << k) <= n; i++) {
      Max[i][k] = max(Max[i][k - 1], Max[i + (1ll << k - 1)][k - 1]);
      Min[i][k] = min(Min[i][k - 1], Min[i + (1ll << k - 1)][k - 1]);
    }
  long long ans = 0;
  long long l = 0;
  long long L = 0;
  for (long long i = 0; i < n; i++) {
    while (L < i && getmin(L, i) < getmax(L, i)) L++;
    while (l < i && getmin(l, i) <= getmax(l, i)) l++;
    ans += l - L;
  }
  cout << ans;
}

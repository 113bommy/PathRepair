#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n;
long long k;
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + 1 + n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans += a[i];
  if (ans <= k) {
    cout << 0 << '\n';
    return;
  }
  long long cnt = n - 1;
  if (1ll * a[1] * n > k) {
    long long m = k / n;
    if (m * n > k) m--;
    cnt += (a[1] - m);
  }
  ans = cnt;
  long long pre = 0;
  for (int i = 2; i <= n; ++i) {
    cnt = n - i;
    pre += a[i];
    if (a[1] * (cnt + 1) + pre > k) {
      long long m = (k - pre) / (cnt + 1);
      if (m * (cnt + 1) + pre > k) m--;
      cnt += (a[1] - m);
    }
    ans = min(ans, cnt);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10, kM = 4e5 + 5;
int t, n, k, l, r, ans, a[kN], cnt[kM];
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n / 2; i++) {
      l = min(a[i], a[n - i + 1]) + 1;
      r = max(a[i], a[n - i + 1]) + k;
      cnt[1] += 2;
      cnt[l]--;
      cnt[r + 1]++;
      cnt[a[i] + a[n - i + 1]]--;
      cnt[a[i] + a[n - i + 1] + 1]++;
    }
    for (int i = 2; i <= 2 * k; i++) cnt[i] += cnt[i - 1];
    ans = n / 2;
    for (int i = 1; i <= 2 * k; i++) ans = min(ans, cnt[i]);
    cout << ans << '\n';
  }
  return 0;
}

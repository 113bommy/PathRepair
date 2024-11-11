#include <bits/stdc++.h>
using namespace std;
long long y, x, n, i, j, k, l, t, cnt[(1ll << 24)], mask, ans;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    mask = 0;
    for (j = 0; j < 3; j++) mask |= (1ll << (s[i] - 'a'));
    cnt[mask]++;
  }
  for (i = 0; i < 24; i++) {
    for (mask = 0; mask < (1ll << 24); mask++) {
      if (mask & (1ll << i)) cnt[mask] += cnt[mask ^ (1ll << i)];
    }
  }
  for (i = 0; i < (1ll << 24); i++) ans ^= (n - cnt[i]) * (n - cnt[i]);
  cout << ans << "\n";
}

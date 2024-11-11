#include <bits/stdc++.h>
using namespace std;
int n, m, k, s[2000006], a[2000006];
long long res = 1000000000000000007LL;
int c[2000006];
void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int g;
    cin >> g;
    s[g] = 1;
  }
  if (s[0]) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 1; i < k + 1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n + k + 1; i++) {
    if (s[i] == 0)
      c[i] = i;
    else
      c[i] = c[i - 1];
  }
  for (int l = 1; l < k + 1; l++) {
    int cur = 0, ans = 0, f = 1;
    while (cur < n) {
      if (c[cur + l] == cur) {
        f = 0;
        break;
      }
      cur = c[cur + l];
      ans++;
    }
    if (f) res = min(res, 1LL * a[l] * ans);
  }
  if (res != 1000000000000000007LL) {
    cout << res << '\n';
  } else {
    cout << -1 << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

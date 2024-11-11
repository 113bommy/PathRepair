#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (long long i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      cout << -1 << "\n";
      return;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 30; i++) {
    long long cnt = 0;
    for (long long j = 0; j < n; j++) {
      if (a[j] - 'a' == i && a[j] != b[j]) cnt++;
    }
    if (!cnt) continue;
    long long mn = 1000;
    for (long long j = 0; j < n; j++) {
      if (a[j] - 'a' == i && a[j] != b[j]) {
        mn = min(mn, (long long)(b[j] - 'a'));
      }
    }
    for (long long j = 0; j < n; j++) {
      if (a[j] - 'a' == i && a[j] != b[j]) {
        a[j] = char(mn + 'a');
      }
    }
    ans++;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
}

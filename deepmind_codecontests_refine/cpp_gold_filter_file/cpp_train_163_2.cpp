#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
long long a[N], b[N], p;
int k, n;
bool vis[N];
bool ok(long long x) {
  memset(vis, 0, sizeof(vis));
  bool f = 1;
  for (int i = 1; i <= n && f; i++) {
    f = 0;
    for (int j = 1; j <= k; j++) {
      if (!vis[j]) {
        if (abs(a[i] - b[j]) + abs(p - b[j]) <= x) {
          vis[j] = 1;
          f = 1;
          break;
        }
      }
    }
  }
  return f;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n >> k >> p) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    long long l = 0, r = 1e10 + 10;
    long long ans = -1;
    while (l <= r) {
      long long m = (l + r) >> 1;
      if (ok(m)) {
        ans = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    cout << ans << endl;
  }
  return 0;
}

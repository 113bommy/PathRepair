#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u, v, l = 1000001, r = 0;
const int md = 1000000007;
int p[1000001];
int a[1000001];
long long ans;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n - k - 1; i++) a[i] = 1;
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = (p[i - 1] * 2) % md;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    if (v == u + 1) continue;
    if (v != u + k + 1) {
      cout << "0";
      return 0;
    }
    a[u] = 0;
    l = min(l, u);
    r = max(r, u);
  }
  if (l + k + 1 <= r) {
    cout << "0";
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    a[i] += a[i - 1];
  }
  if (r == 0) {
    for (int i = 1; i <= n - k - 1; i++) {
      ans += p[a[i + k] - a[i]];
      ans %= md;
    }
  } else {
    for (int i = max(1, r - k); i < l + k + 1; i++) {
      if (a[i] - a[i - 1] == 1) {
        int mx = max(r, i);
        ans += p[a[i - 1] - a[max(0, mx - k - 1)]];
        ans %= md;
      }
    }
  }
  ans += 1;
  ans %= md;
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
const int P = 998244353;
int n, a[N];
long long ans = 0;
void solve(int l, int r) {
  if (l == r) {
    ans += a[l];
    return;
  }
  int m = l + r >> 1;
  solve(l, m);
  solve(m + 1, r);
  int j = m, mx = -INT_MAX;
  for (int i = m + 1; i <= r; i++) {
    mx = max(mx, a[i]);
    while (j >= l && a[j] <= mx) j--;
    ans += 1ll * (m - j) * mx;
  }
  j = m + 1, mx = -INT_MAX;
  for (int i = m; i >= l; i--) {
    mx = max(mx, a[i]);
    while (j <= r && a[j] < mx) j++;
    ans += 1ll * mx * (j - m - 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int t = 0; t < 2; t++) {
    solve(1, n);
    for (int i = 1; i <= n; i++) a[i] *= -1;
  }
  cout << ans;
}

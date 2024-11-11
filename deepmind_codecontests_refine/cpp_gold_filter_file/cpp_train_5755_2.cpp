#include <bits/stdc++.h>
using namespace std;
int t, n, x, y, a[200002], k, nxt[200001], ans[200001], mx[200001], an;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) mx[i] = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i) cin >> x;
    x = k, y = an = 0;
    for (int i = 0; i < n; ++i) {
      while (y < n && a[y] - a[i] <= k) y++;
      ans[i] = y - i;
      nxt[i] = y;
    }
    for (int i = n - 1; ~i; --i) mx[i] = max(mx[i + 1], ans[i]);
    for (int i = 0; i < n; ++i) an = max(ans[i] + mx[nxt[i]], an);
    cout << an << endl;
  }
}

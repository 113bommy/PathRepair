#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), ans(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n - 1; i++) {
      if (i == 0)
        ans[i] = a[i];
      else if (a[i] != ans[i - 1])
        ans[i] = a[i];
      else if (b[i] != ans[i - 1])
        ans[i] = b[i];
      else
        ans[i] = c[i];
    }
    if (ans[0] != a[n - 1] && ans[n - 2] != a[n - 1])
      ans[n - 1] = a[n - 1];
    else if (ans[0] != b[n - 1] && ans[n - 2] != b[n - 2])
      ans[n - 1] = b[n - 1];
    else
      ans[n - 1] = c[n - 1];
    for (int i = 0; i < n; i++) {
      cout << ans[i];
      if (i != n - 1) cout << " ";
    }
    cout << "\n";
  }
  return 0;
}

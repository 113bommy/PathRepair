#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 45;
int a[N], n;
int ans[N][320];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int lim = sqrt(n);
  for (int p = n; p >= 1; p--) {
    for (int k = 1; k <= lim; k++) {
      if (p + a[p] + k > n) {
        ans[p][k] = 1;
      } else {
        ans[p][k] = ans[p + a[p] + k][k] + 1;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    if (k <= lim) {
      cout << ans[p][k] << endl;
      continue;
    }
    int pos = p, ans = 0;
    while (pos <= n) {
      ans++;
      pos = pos + a[pos] + k;
    }
    cout << ans << endl;
  }
}

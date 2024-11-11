#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n, k, q;
  cin >> n >> k >> q;
  int a[200005] = {};
  for (auto i = 0; i != n; i++) {
    int l, r;
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }
  for (auto i = 1; i != 200005; i++) {
    a[i] += a[i - 1];
  }
  int ans[200005] = {};
  for (auto i = 1; i != 200005; i++) {
    if (a[i] >= k) {
      ans[i] = ans[i - 1] + 1;
    } else {
      ans[i] = ans[i - 1];
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << ans[r] - ans[l - 1] << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    Solve();
  }
  return 0;
}

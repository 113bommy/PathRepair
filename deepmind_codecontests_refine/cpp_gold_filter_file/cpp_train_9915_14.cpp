#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), peak(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n - 1; i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      peak[i] = 1;
    }
  }
  for (int i = n - 2; i > 0; i--) {
    peak[i] += peak[i + 1];
  }
  int ans = 0, pos;
  for (int i = n - 1; i >= 0; i--) {
    if (i + k > n) continue;
    if (peak[i + 1] - peak[i + k - 1] >= ans) {
      ans = peak[i + 1] - peak[i + k - 1];
      pos = i + 1;
    }
  }
  cout << ans + 1 << " " << pos << "\n";
}
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

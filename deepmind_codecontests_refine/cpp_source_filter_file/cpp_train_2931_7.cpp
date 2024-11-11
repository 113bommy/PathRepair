#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int mx = 0;
  cout << 1 << " " << n - 1 << " " << 1;
  for (int i = 2; i <= n; i++) {
    cout << " " << i;
  }
  cout << endl;
  cout.flush();
  cin >> mx;
  int lo = 2;
  int hi = n - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    cout << 1 << " " << (mid - lo + 1) << " " << 1;
    for (int i = lo; i <= mid; i++) {
      cout << " " << i;
    }
    cout << endl;
    cout.flush();
    int m;
    cin >> m;
    if (m == mx) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << 1 << " " << (n - 1) << " " << lo;
  for (int i = 1; i <= n; i++) {
    if (i == lo) continue;
    cout << " " << i;
  }
  cout << endl;
  cout.flush();
  int ans;
  cin >> ans;
  cout << "-1 " << ans << endl;
  cout.flush();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int mx = -1;
  for (int i = n - 1; i >= 1; i--) {
    mx = max(a[i], mx);
    if (mx != a[i] && a[i] < a[i - 1]) {
      cout << i << endl;
      return;
    }
  }
  if (a[0] > a[1] && mx != -1)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}

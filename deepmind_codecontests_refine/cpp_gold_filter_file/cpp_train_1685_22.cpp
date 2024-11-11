#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n], m;
  int c = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  m = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] <= m) {
      m = a[i];
    } else
      ++c;
  }
  cout << c << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

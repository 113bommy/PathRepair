#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 2) {
    cout << "-" << a[1] << " " << a[0] << "\n";
    return;
  }
  for (int i = 0; i < n - 1; i++, i++) {
    swap(a[i], a[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      cout << -1 * a[i] << " ";
    else
      cout << a[i] << " ";
  }
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

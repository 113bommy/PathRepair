#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int i, j, n, m, q, k, x, l, a, b;
  cin >> n;
  if (n < 4) {
    cout << -1 << endl;
    return;
  }
  if (n & 1) {
    for (i = 1; i <= n; i += 2) cout << i << " ";
    cout << n - 3 << " " << n - 1 << " ";
    for (i = n - 5; i >= 2; i -= 2) cout << i << " ";
    cout << endl;
  } else {
    for (i = 2; i <= n; i += 2) cout << i << " ";
    cout << n - 3 << " " << n - 1 << " ";
    for (i = n - 5; i >= 2; i -= 2) cout << i << " ";
    cout << endl;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1, i;
  cin >> t;
  for (i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}

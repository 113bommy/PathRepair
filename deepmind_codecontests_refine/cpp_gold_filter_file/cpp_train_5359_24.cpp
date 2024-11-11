#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, x, y;
  cin >> n >> m;
  long long a[n], b[m], i;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  cin >> x;
  for (i = 0; i < x; i++) cin >> y, a[y] = 1;
  cin >> x;
  for (i = 0; i < x; i++) cin >> y, b[y] = 1;
  for (i = 0; i < 2 * n * m; i++) {
    if (a[i % n] || b[i % m]) a[i % n] = b[i % m] = 1;
  }
  for (i = 0; i < n; i++)
    if (!a[i]) {
      cout << "No"
           << "\n";
      return;
    }
  for (i = 0; i < m; i++)
    if (!b[i]) {
      cout << "No"
           << "\n";
      return;
    }
  cout << "Yes"
       << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

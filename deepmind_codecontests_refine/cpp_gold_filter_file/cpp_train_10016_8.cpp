#include <bits/stdc++.h>
using namespace std;
int t, x, n, m, a[100001];
void solve() {
  long long k = 0, s = 0, d = 0;
  for (int i = 1; i <= m; i++) {
    cin >> x;
    if (k >= a[x])
      s++, d++;
    else
      k = a[x], s += (2 * (k - 1 - d) + 1), d++;
  }
  cout << s << endl;
}
int main() {
  for (cin >> t; t--;) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x, a[x] = i;
    solve();
  }
}

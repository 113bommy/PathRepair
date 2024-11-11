#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, x = 0, has = 0, p = 0, q = 1000;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int a;
      cin >> a;
      if (a == 0) x = 1;
      if (a < 0) p++;
      has += abs(a);
      q = min(q, abs(a));
    }
  }
  if (x == 1)
    cout << has << endl;
  else {
    if (q % 2 == 0)
      cout << has << endl;
    else
      cout << has - 2 * q << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
